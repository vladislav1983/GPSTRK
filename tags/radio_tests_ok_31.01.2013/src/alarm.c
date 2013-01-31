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
#ifdef __ALARM_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __ALARM_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "alarm.h"
#include "timer.h"
#include "scheduler.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
/* Number of slot available */
#define cSlotNumber                         16
/*This constant defines the period of designed for Alarm management hardware timer*/
#define cOsTimerPeriodUs                    (((U32)cOsAlarmTickUs)/((U32)cOsHardwareTimerTickUs * 2UL))

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarmTick AlarmState;
static tOSAlarmTick AlarmCycle;
static tOSTaskID    TasksList[cSlotNumber];

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static tOSAlarmTick GetSlot(tOSAlarmTick Duration);

/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Alarm init
 *===================================================================================================================*/
void OsAlarmInit(void)
{
    U16 u16NbSlot;

    AlarmState = 0;
    for (u16NbSlot = 0; u16NbSlot < cSlotNumber; u16NbSlot++)
    {
        _OSClearTaskList(&TasksList[u16NbSlot]);
    }
}

/*=====================================================================================================================
 * Parameters: AlarmCycle - Alarm cycle is multiplier -> Alarm tick = AlarmCycle * cOsAlarmTickUs
 *
 * Return: void
 *
 * Description: Start alarms
 *===================================================================================================================*/
void OsAlarmStart(tOSAlarmTick AlarmCycleInit)
{
    _assert(0 != AlarmCycleInit);
    _assert((cOsTimerPeriodUs * 2UL * cOsHardwareTimerTickUs) ==  cOsAlarmTickUs);

    AlarmCycle = AlarmCycleInit;
    AlarmState &= (tOSAlarmTick) ~((tOSAlarmTick)(AlarmCycle - 1));

    _OsStartHardwareTimer();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Stop alarms
 *===================================================================================================================*/
void OsAlarmStop(void)
{
    _OsStopHardwareTimer();
}


/*=====================================================================================================================
 * Parameters:  pAlarm - Alarm object
 *              Cycle - alarm period in alarm cycles 
 *
 * Return: void
 *
 * Description: Add task to alarm list.
 *===================================================================================================================*/
void OsSetAlarm(tOSAlarm *pAlarm, tOSAlarmTick Cycle)
{
    tOSAlarmTick SlotID;

    if (Cycle != 0)
    {
        SlotID = GetSlot(Cycle);

        // Check if the asked period is 2 to power of x compatible.
        _assert(((tOSAlarmTick)1 << SlotID) == Cycle);

        pAlarm->Period = Cycle;

        _OsSuspendOsInterrupts();
        _OSAddTaskToList(&TasksList[SlotID], pAlarm->TaskID);
        _OsResumeOsInterrupts();
    }
    else
    {
        _assert(cFalse);
    }
}

/*=====================================================================================================================
 * Parameters:  pAlarm - Alarm object
 *
 * Return: void
 *
 * Description: Stop alarm. Remove alarm from task list.
 *===================================================================================================================*/
void OsCancelAlarm(tOSAlarm * pAlarm)
{
    tOSAlarmTick SlotID;

    if (pAlarm->Period != 0)
    {
        SlotID = GetSlot(pAlarm->Period);

        // Check if the asked period is 2 to power of x compatible.
        _assert(((tOSAlarmTick)1 << SlotID) == pAlarm->Period);

        _OsSuspendOsInterrupts();
        _OSRemoveTaskFromList(&TasksList[SlotID],pAlarm->TaskID);
        OSSuspendTask(pAlarm->TaskID);
        _OsResumeOsInterrupts();
    }
    else
    {
        _assert(cFalse);
    }
}

/*=====================================================================================================================
 * Parameters:  void
 *
 * Return: void
 *
 * Description: Alarm callback. Hardware timer call this function every tick defined with cOsHardwareTimerTickUs.
 *===================================================================================================================*/
void OsAlarmTickCallback(void)
{
    AlarmState = ((tOSAlarmTick) (AlarmCycle + AlarmState));

    if(AlarmState != 0)
    {
        tOSAlarmTick SlotID = GetSlot(AlarmState);
        _OSActivateTaskList(&TasksList[SlotID]);
    }
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: Duration - this parameter can only take value of 2 to the power of x.
 *
 * Return: Returns the slot Id corresponding to input parameter Duration.
 *
 * Description: Checks if Duration is different from 0.
 *              Returns the position of the first bit to 1 of the tick counter, starting
 *              with the less significant bit. 
 *===================================================================================================================*/
static tOSAlarmTick GetSlot(tOSAlarmTick Duration)
{
    _assert(Duration != 0);

#if OS_AlarmGetSlotOptimization == 1
    register U16 w0_local asm("w0");

    asm volatile ("ff1r w0, w0");
    asm volatile ("sub  w0, #0x0001, w0");

    return(w0_local);
#else
    tOSAlarmTick SlotID = 0;

    // Checks if Duration is different from 0
    while((Duration & (tOSAlarmTick)0x0001) == 0)
    {
        ++SlotID;
        Duration >>= 1;
    }

    return(SlotID);
#endif
}
