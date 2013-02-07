/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __VTIME_H
#define __VTIME_H

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
#define _VTime_Init()               VTime_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void VTime_Init(void);
extern void VTime_Task(void);
extern void VTime_GpsSet_ddmmyy(U8 *pu8ddmmyy, tNMEA_GPS_Data *GpsData);
extern void VTime_GpsSet_hhmmss(U8 *pu8hhmmss, tNMEA_GPS_Data *GpsData);
extern U16 VTime_GetSystemTick(void);

#endif /* __VTIME_H */
