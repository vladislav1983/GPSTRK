/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __APRS_H
#define __APRS_H

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

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void __attribute__((user_init)) Arps_Init(void);
extern void Aprs_Task(void);
extern void Aprs_Control(tControl Control);

#endif /* __APRS_H */
