/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __DEVCONFIG_H
#define __DEVCONFIG_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define cAPRS_VersionInfoLength         55   // by standard: (max 62 chars if no timestamp, or 55 chars if there is a timestamp)
#define cAPRS_BeaconTextLen             16
#define cAPRS_PrimarySimbolTable        (U8)'/'
#define cAPRS_SimbolTableCar            (U8)'>'

/*
** Default configuration values
*/
#define cDeviceConfigParamsInit()                   	                                                                \
{                                                   	                                                                \
    .u8ConfAprs25BeaconInterval_s = 100,                	                                                            \
    .u8ConfAprsTxDelay          = 30,                                                                                   \
    .u8ConfAprsPropath          = 0,                                                                                    \
    .u8ConfigAprsSourceAddr     = "NOCALL0",          	                                                                \
    .u8ConfigAprsDestAddr       = "APERXQ0",         	                                                                \
    .u8ConfigAprsDigipeater     = "RELAY 0",                                                                            \
    .u8ConfAprsSymbolTable      = cAPRS_PrimarySimbolTable,                                                             \
    .u8ConfAprsSymbol           = cAPRS_SimbolTableCar,                                                                 \
    .u8ConfigTrackerVersion     = "GPS tracker by _maker_ V1.01 <vladislav_1@abv.bg>",                                  \
    .u8ConfigBeaonText          = "beacon text"                                                                         \
}



/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
struct sDeviceConfigParams
{
    U8 u8ConfAprs25BeaconInterval_s;
    U8 u8ConfAprsTxDelay;
    U8 u8ConfAprsPropath;
    U8 u8ConfigAprsSourceAddr[7+1];
    U8 u8ConfigAprsDestAddr[7+1];
    U8 u8ConfigAprsDigipeater[7+1];
    //---
    U8 u8ConfAprsSymbolTable;
    U8 u8ConfAprsSymbol;
    //--- NO user accessible configuration
    U8 u8ConfigTrackerVersion[cAPRS_VersionInfoLength+1];
    U8 u8ConfigBeaonText[cAPRS_BeaconTextLen+1];
};

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern struct sDeviceConfigParams DeviceConfigParams;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern HRESULT Devconfig_LoadConfig(void);


#endif /* __DEVCONFIG_H */
