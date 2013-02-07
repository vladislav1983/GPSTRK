/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __SYSTEM_H
#define __SYSTEM_H

/*
** Module Identification
*/
#define __SYSTEM

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/

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
#define _WatchDOgEnable()               _SWDTEN = 1
#define _WatchDOgDisable()              _SWDTEN = 0
/* 
** Services to enter/leave critical section
*/
#define _EnterCriticalSection()                     { tCPUItState CPUItState; SET_AND_SAVE_CPU_IPL(CPUItState, 7);
#define _LeaveCriticalSection()                                               RESTORE_CPU_IPL(CPUItState); }
#define _ProtectCriticalSectionLevel6(Cycles)       _DisableInterruptsLevel6(Cycles)
/*
** Disable level 6 interrupts for specified number of cycles
** Disable interrupts of priority 0 through priority 6 for (lit14 + 1) instruction
** cycles. Priority 0 through priority 6 interrupts are disabled starting in the
** cycle that DISI executes, and remain disabled for the next (lit 14) cycles.
** The lit14 value is written to the DISICNT register, and the DISI flag
** (INTCON2<14>) is set to ‘1’. This instruction can be used before
** executing time critical code, to limit the effects of interrupts.
*/
#define _DisableInterruptsLevel6(Cycles)            __builtin_disi(Cycles)

#define _System_WDT_Init()                          System_WDT_Init()
#define _System_StreamsInit()                       System_StreamsInit()
/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void System_Init(void);
extern void _system_lowlevel_init(void);
extern void System_WDT_Init(void);
extern void IdleTask(void);
extern void RefreshWatchDogTask(void);
extern void System_EnterSleep(void);
extern void System_LeaveSleep(void);
extern void System_StreamsInit(void);

#endif /* __SYSTEM_H */
