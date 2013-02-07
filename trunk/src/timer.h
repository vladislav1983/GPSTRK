/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __TIMER_H
#define __TIMER_H

/*
** Module Identification
*/
#define __TIMER

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "vuart.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
/* Define here ticks of Timer1 */
#define cTimer1Ticks_us                         (cOsHardwareTimerTickUs/2UL)
#define cTimer1Prescaler                        1

/* Software timer tick */
#define cSoftTimerTick_us                       ((U32)cTimer1Ticks_us)

/*
** Define ID's of timers here
*/
#define cSchedulerTimerId                       0
#define cNumberSoftTimers                       1

#if(cNumberSoftTimers > 16)
    #error "Maximum number of timers reached"
#endif

// 
/*
** ************* Define here list of software timers *************
**
** | -> Highest priority 
** |
** |
** v -> Lowest priority
*/
#define cSoftwareTimerList                                              \
{                                                                       \
    /* cSchedulerTimerId - Scheduler timer */                           \
    {                                                                   \
    /* Timeout ms   */  _TimeToSoftTimTicks(cOsHardwareTimerTickUs),    \
    /* Callback Fct */  OsAlarmTickCallback                             \
    }                                                                   \
}

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef struct
{
    U16       u16TimerTimeout;
    tCallback Callback;
}tsSoftTimerList;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern volatile U16             u16SoftTimerCounter;
extern volatile U16             u16SoftTimerListTicks[];
extern volatile tsSoftTimerList SoftTimerList[];

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
// Convert time in ms to soft timer tics
#define _TimeToSoftTimTicks(Time_Us)            ((Time_Us) / cSoftTimerTick_us)
#define _StopSoftTimer(SoftTimerRef)            (SoftTimerList[(SoftTimerRef)].u16TimerTimeout = 0)
#define _StartSoftTimer(SoftTimerRef, TimeUs)   (SoftTimerList[(SoftTimerRef)].u16TimerTimeout = _TimeToSoftTimTicks(TimeUs))
// Reset soft timer. When is called soft timer tick counter is reset.
#define _ResetSoftTimer(SoftTimerRef)           (u16SoftTimerListTicks[SoftTimerRef] = u16SoftTimerCounter)

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 1*/
#define _EnableIntT1()                      _T1IE = 1
#define _DisableIntT1()                     _T1IE = 0
#define _ClearIntT1()                       _T1IF = 0
#define _SetPriorityIntT1(priority)         _T1IP = priority

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 2*/
#define _EnableIntT2()                      _T2IE = 1
#define _DisableIntT2()                     _T2IE = 0
#define _ClearIntT2()                       _T2IF = 0
#define _SetPriorityIntT2(priority)         _T2IP = priority

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timers 3*/
#define _EnableIntT3()                      _T3IE = 1
#define _DisableIntT3()                     _T3IE = 0
#define _ClearIntT3()                       _T3IF = 0
#define _SetPriorityIntT3(priority)         _T3IP = priority

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 4 */
#define _EnableIntT4()                      _T4IE = 1
#define _DisableIntT4()                     _T4IE = 0
#define _ClearIntT4()                       _T4IF = 0
#define _SetPriorityIntT4(priority)         _T4IP = priority

/* Macros to  Enable/Disable interrupts and set Interrupt priority of Timer 5 */
#define _EnableIntT5()                      _T5IE = 1
#define _DisableIntT5()                     _T5IE = 0
#define _ClearIntT5()                       _T5IF = 0
#define _SetPriorityIntT5(priority)         _T5IP = priority

#define _Timer1Init()                       Timer1Init()
#define _SoftTimersInit()                   SoftTimersInit()
/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void Timer1Init(void);
extern void SoftTimersInit(void);

#endif /* __TIMER_H */
