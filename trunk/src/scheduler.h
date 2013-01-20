/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __SCHEDULER_H
#define __SCHEDULER_H

/*
** Module Identification
*/
#define __SCHEDULER

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "kernelparam.h"
#include "kernel.h"

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
#define _OSClearTaskList(pTaskList)                 (*(pTaskList) = 0)
#define _OSActivateTaskList(pTaskList)              (OSActivateTask(*(pTaskList)))
#define _OSAddTaskToList(pTaskList,TaskId)          ((*(pTaskList)) |= (TaskId))
#define _OSRemoveTaskFromList(pTaskList,TaskId)     ((*(pTaskList)) &= (tOSTaskID)(~(TaskId)))

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void                           OSActivateTask(tOSTaskID TaskId);
extern void                           OSSuspendTask(tOSTaskID TaskId);
extern void                           OSShutdown(void);
extern void __attribute__((noreturn)) OsStartup(void);
extern void                           OSSchedule(void);
extern void                           OsIdleTask(void);
extern void                           OSHalt(void);
extern void                           SuspendOsInterrupts(U8 Level);
extern void                           ResumeOsInterrupts(void);
extern void                           DisableAllInterrupts(U8 Level);
extern void                           EnableAllInterrupts(void);

#endif /* __SCHEDULER_H */
