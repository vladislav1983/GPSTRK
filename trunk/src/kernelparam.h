/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __KERNELPARAM_H
#define __KERNELPARAM_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "alarm.h"
#include "scheduler.h"
#include "kerneltimer.h"
#include "signal.h"
/*
** Include here modules that contains task function
*/
#include "system.h"
#include "dio.h"
#include "nmea_main.h"
#include "vtime.h"
#include "app_statemachine.h"
#include "fsio_main.h"
#include "measure.h"
#include "aprs.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
/*
** ************* Define task ID here *************
*/
/*0 */#define cIdleTaskId                           ((tOSTaskID)(0x00000000)) /* Idle task always have ID = 0 */
/*1 */#define cRefreshWatchDogTaskId                ((tOSTaskID)(1UL<<(0UL)))
/*2 */#define cSysTimeTaskId                        ((tOSTaskID)(1UL<<(1UL)))
/*3 */#define cAprsTaskId                           ((tOSTaskID)(1UL<<(2UL)))
/*4 */#define cMeasureTaskId                        ((tOSTaskID)(1UL<<(3UL)))
/*5 */#define cFSIOTaskId                           ((tOSTaskID)(1UL<<(4UL)))
/*6 */#define cDioTaskId                            ((tOSTaskID)(1UL<<(5UL)))
/*7 */#define cNMEAMainDecodeTaskID                 ((tOSTaskID)(1UL<<(6UL)))
/*8 */#define cAppStatemachineTaskId                ((tOSTaskID)(1UL<<(7UL)))
/*9 */#define cOsTimerTaskId                        ((tOSTaskID)(1UL<<(8UL)))
///*10*/ #define cxxxTaskId                         ((tOSTaskID)(1UL<<(9UL)))   // (0x00000200)
///*11*/ #define cxxxTaskId                         ((tOSTaskID)(1UL<<(10UL)))  // (0x00000400)
///*12*/ #define cxxxTaskId                         ((tOSTaskID)(1UL<<(11UL)))  // (0x00000800)
///*13*/ #define cxxxTaskId                         ((tOSTaskID)(1UL<<(12UL)))  // (0x00001000)
/*
** ************* Define task number here - include idle task *************
*/
#define cOsTaskNumber                               10UL
/*
** ************* Define task list here *************
**
** | -> Lowest task priority
** |
** |
** v -> Highest task priority
** Order tasks according their ID's
*/
#define OSTaskListInit \
{\
/* Task Id  |Task Fct                               Description                         */\
/* 0 */      OsIdleTask,                        /*	IDLE task is only at position 0     */\
/* 1 */      RefreshWatchDogTask,               /*	Refresh WatchDog task               */\
/* 2 */      VTime_Task,                        /*	System time task                    */\
/* 3 */      Aprs_Task,                         /*	APRS transmission task              */\
/* 4 */      Measure_Task,                      /*	Analog measurements task            */\
/* 5 */      FSIO_Task,                         /*	SD Card polling task                */\
/* 6 */      DioTask,                           /* 	DIO task                            */\
/* 7 */      NMEAMain_DecodeTask,               /* 	NMEA decoder                        */\
/* 8 */      App_StatemachineTask,              /* 	Application state machine task      */\
/* 9 */      OsTimerTask                        /* 	OS timer task - Highest priority    */\
}

/*
** Define here OS interrupts level. This is maximum level of interrupt priority which OS will operate.
*/
#define cOsInterruptLevel               4
/*
** Define this to use scheduler stack
** Define cOsSchedulerStackMargin -> Margin of stack size
*/
#define NO_DYNAMIC_DATA
#define cOsSchedulerStackMargin         0

/*
** Alarm Parameters
*/
/* Define here hardware timer tick us */
#define cOsHardwareTimerTickUs          2500UL

/* Alarm tick definition 
**
*/
#define cOsAlarmTickUs                  5000UL
/*
** Define here OS timer period in us
*/
#define cOsTimerTickUs                  10000UL
/*
** Kernel options
*/
#define OS_AlarmGetSlotOptimization     1   // Optimize get slot function with dsPIC/PIC24 special instruction
/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
/* 
** Define here services to suspend/resume OS interrupts
*/
#define _OsSuspendOsInterrupts()        { tCPUItState CPUItState; SET_AND_SAVE_CPU_IPL(CPUItState, cOsInterruptLevel);
#define _OsResumeOsInterrupts()           RESTORE_CPU_IPL(CPUItState); }

/*
** Define here services to enable/disable all interrupts
*/
#define _DisableAllInterrupts()         DisableAllInterrupts(7)
#define _EnableAllInterrupts()          EnableAllInterrupts()

/*
** Define here service to toggle OS interrupt
*/
#define _OSToggleOSInterrupts()                                         \
                                        do{                             \
                                            _EnableAllInterrupts();     \
                                            Nop();                      \
                                            _DisableAllInterrupts();    \
                                        }while(0)
/*
** Define here services to start/stop OS timer
*/
#define _OsStopHardwareTimer()          _StopSoftTimer(cSchedulerTimerId)
#define _OsStartHardwareTimer()         _StartSoftTimer(cSchedulerTimerId, cOsHardwareTimerTickUs)

/*
** Define here service to reset CPU
*/
#define _OsResetCpu()                   asm("goto __resetPRI")

/*
** Define here service to halt CPU
*/
#define _OsHaltCpu()                    Idle()

/*
** Define here OS startup hook function
** System init sequence - HAL_Init -> APPL_Init
*/
#define _OsStartupHook()                

/*
** Define here external idle task
*/
#define _OsIdleTaskExternal()           IdleTask()



/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/


#endif /* __KERNELPARAM_H */
