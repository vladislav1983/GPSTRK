/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __VADC_H
#define __VADC_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/

/*
** Define here analog channels used
*/
#define cAdc_BatteryVoltageChIndex      0
#define cAdc_TempChIndex                1
#define cAdc_ChannelsCnt                2

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
#define _Adc_Init()         Adc_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void Adc_Init(void);
extern void Adc_ConvertChannels(tMsg Msg);

#endif /* __VADC_H */