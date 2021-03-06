/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __APP_STATEMACHINE_H
#define __APP_STATEMACHINE_H

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
extern U16 u16SYSTEM_FLAGS;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _sd_card_present()                          (_getbit(u16SYSTEM_FLAGS,      0))      /* bit 0 */
#define _set_sd_card_present(x)                     (_putbit((x), u16SYSTEM_FLAGS, 0))      /* bit 0 */

// #define _devconfig_ok()                             (_getbit(u16SYSTEM_FLAGS,      1))      /* bit 1 */
// #define _set_devconfig_ok(x)                        (_putbit((x), u16SYSTEM_FLAGS, 1))      /* bit 1 */


#define _App_Init()                                 App_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void App_Init(void);
extern void App_StatemachineTask(void);

#endif /* __APP_STATEMACHINE_H */
