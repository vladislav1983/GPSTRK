/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/

/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __SCHEDULER_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __SCHEDULER_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "scheduler.h"
#include "alarm.h"
#include "kerneltimer.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
/* This is the ID of task with highest priority */
#define cTASK_MSB_ID         (((tOSTaskID) 1UL) << (cOsTaskNumber - (tOSTaskID)2UL))

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#ifndef NO_DYNAMIC_DATA
    #define SCHEDULER_DATA_TYPE 
#else
    #define SCHEDULER_DATA_TYPE static

/*----- Scheduler stack management -----*/
    #define _ClearSchedulerStack()      (s16SchedulerStackLevel = ((S16)-1))

/*Scheduler stack treat only tSchedulerStack type*/
    #define _PushToSchedulerStack(Type, Data)                               \
    do{                                                                     \
        _assert(sizeof(Type) == sizeof(tOSTaskID));                         \
        s16SchedulerStackLevel++;                                           \
        _assert(s16SchedulerStackLevel < (S16)(cOSSchedulerStackSize));     \
        SchedulerStack[s16SchedulerStackLevel] = ((Type)(Data));            \
    }while(0)

#define _PopFromSchedulerStack(Type, Data)                                  \
    do{                                                                     \
        _assert(s16SchedulerStackLevel >= 0);                               \
        (Data) = ((Type)SchedulerStack[s16SchedulerStackLevel]);            \
        s16SchedulerStackLevel--;                                           \
    }while(0)

#define cOSSchedulerStackSize   (cOsTaskNumber + cOsSchedulerStackMargin)
#endif

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static volatile tOSTaskID   ListOfReadyTasks;
static          tOSTaskID   ListOfSelectableTasks;

#ifdef NO_DYNAMIC_DATA
    static S16       s16SchedulerStackLevel;
    static tOSTaskID SchedulerStack[cOSSchedulerStackSize];
#endif

static volatile U8   OsItState;
static volatile U8   AllItState;
/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
/* Task list */
static const tpOSTaskFct OSTaskList[cOsTaskNumber] = OSTaskListInit;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/


/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: TaskId - ID of task which will be activated
 *
 * Return: void
 *
 * Description: Activate task with ID = TaskId. Set task active in ready tasks list
 *===================================================================================================================*/
void OSActivateTask(tOSTaskID TaskId)
{
    _OsSuspendOsInterrupts();
    ListOfReadyTasks |= TaskId;
    _OsResumeOsInterrupts();
}

/*=====================================================================================================================
 * Parameters: TaskId - ID of task which will be suspended
 *
 * Return: void
 *
 * Description: Suspend task with ID = TaskId. Clear task active in ready tasks list
 *===================================================================================================================*/
void OSSuspendTask(tOSTaskID TaskId)
{
    ListOfReadyTasks &= (tOSTaskID)(~TaskId);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Shutdown OS -> Reset CPU
 *===================================================================================================================*/
void OSShutdown(void)
{
    _OsSuspendOsInterrupts();
    _OsResetCpu();
    _OsResumeOsInterrupts();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Startup OS. Before enter main loop init system modules.
 *              Function is defined with attribute "noreturn", because it will newer return
 *===================================================================================================================*/
void __attribute__((noreturn)) OsStartup(void)
{
    _DisableAllInterrupts();

    ListOfReadyTasks      = 0;
    /* Set all tasks are selectable --> ((cTASK_MSB_ID - 1) << 1) + 1 */
    ListOfSelectableTasks = (tOSTaskID)(((cTASK_MSB_ID - ((tOSTaskID)1U)) << ((tOSTaskID)1U)) + ((tOSTaskID)1U));

#ifdef NO_DYNAMIC_DATA
    _ClearSchedulerStack();
#endif

    OsTimerInit();
    //Start alarms
    OsAlarmStart(1);
    // Application initialization
    _OsStartupHook();

    // Interrupts authorization
    _EnableAllInterrupts();

    //Infinite loop
    for(;;)
    {
        // before the idle task execution a scheduling is made too
        // execute the pending task
        OSSchedule();
        (OSTaskList[0]());
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Scheduler
 *===================================================================================================================*/
void OSSchedule(void)
{
    while((ListOfReadyTasks & ListOfSelectableTasks) != 0)
    {
        /* 
        ** While scheduler must be re-entrant, we want this variable static 
        ** But when NO_DYNAMIC_DATA is defined these variables are stored in separated scheduler stack
        */
        SCHEDULER_DATA_TYPE tOSTaskID PreviousListOfSelectableTasks;
        SCHEDULER_DATA_TYPE tOSTaskID OSTaskID;
        U16                           u16TaskID;
        
        // save selectable task list
        PreviousListOfSelectableTasks = ListOfSelectableTasks;

        // search most priority pending task
        u16TaskID = cOsTaskNumber - 1;
        OSTaskID  = cTASK_MSB_ID;

        while((OSTaskID & ListOfReadyTasks) == 0)
        {
            --u16TaskID;
            OSTaskID >>= 1;
        }

        // Suppress task from the pending task list
        _OsSuspendOsInterrupts();
        ListOfReadyTasks -=  OSTaskID;
        _OsResumeOsInterrupts();

        // update selectable task list
        OSTaskID <<= 1;
        --OSTaskID;
        ListOfSelectableTasks = (tOSTaskID)~OSTaskID;

#ifdef NO_DYNAMIC_DATA      // Save context before call new task
        _PushToSchedulerStack(tOSTaskID, PreviousListOfSelectableTasks);
#endif
        // task function calling
        (OSTaskList[u16TaskID])();
        // restore selectable task list
#ifdef NO_DYNAMIC_DATA
        // Restore context
        _PopFromSchedulerStack(tOSTaskID, PreviousListOfSelectableTasks);
#endif
        ListOfSelectableTasks = PreviousListOfSelectableTasks;
    }
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Idle task. It will cal a external reference or local job may be performed during background
 *===================================================================================================================*/
void OsIdleTask(void)
{
    _OsIdleTaskExternal();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Halt OS. Put CPU in halt mode for current consumption reduction.
 *===================================================================================================================*/
void OSHalt(void)
{
    //Disable interrupt using OS service
    _DisableAllInterrupts();

    while(ListOfReadyTasks == 0)
    {
        //No pending task: go to halt
        _OsHaltCpu();

        //IT are executed
        _OSToggleOSInterrupts();
    }

    //Enable interrupt using OS service
    _EnableAllInterrupts();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void SuspendOsInterrupts(U8 Level)
{
    SET_AND_SAVE_CPU_IPL(OsItState, Level);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void ResumeOsInterrupts(void)
{
    RESTORE_CPU_IPL(OsItState);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void DisableAllInterrupts(U8 Level)
{
    SET_AND_SAVE_CPU_IPL(AllItState, Level);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void EnableAllInterrupts(void)
{
    RESTORE_CPU_IPL(AllItState);
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/

