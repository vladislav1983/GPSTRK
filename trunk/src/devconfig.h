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
    .u8ConfAprsTxDelay          = 60,                                                                                   \
    .u8ConfAprsPropath          = 0,                                                                                    \
    .u8ConfigAprsSourceAddr     = "NOCALL0",          	                                                                \
    .u8ConfigAprsDestAddr       = "APERXQ0",         	                                                                \
    .u8ConfigAprsDigipeater     = "RELAY 0",                                                                            \
    .u8ConfAprsSymbolTable      = cAPRS_PrimarySimbolTable,                                                             \
    .u8ConfAprsSymbol           = cAPRS_SimbolTableCar,                                                                 \
    /* smart beaconing settings */                                                                                      \
    .u16ConfAprsSbInterval_sec      = 0,                	                                                            \
    .u8ConfAprsSbPositFast_sec      = 90u,                                                                              \
    .u8ConfAprsSbPositSlow_min      = 20u,                                                                              \
    .u8ConfAprsSbLowSpeedLimit_kmh  = 6u,                                                                               \
    .u8ConfAprsSbHighSpeedLimit_kmh = 90u,                                                                              \
    /* NO user accessible configuration */                                                                              \
    .u8ConfigTrackerVersion     = "GPS tracker by _maker_ V1.02 <vladislav_1@abv.bg>",                                  \
    .u8ConfigBeaconText         = "beacon text"                                                                         \
}

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
struct sDeviceConfigParams
{
    U8 u8ConfAprsTxDelay;
    U8 u8ConfAprsPropath;
    U8 u8ConfigAprsSourceAddr[7+1];
    U8 u8ConfigAprsDestAddr[7+1];
    U8 u8ConfigAprsDigipeater[7+1];
    //---
    U8 u8ConfAprsSymbolTable;
    U8 u8ConfAprsSymbol;
    // smart beaconing settings
    U16 u16ConfAprsSbInterval_sec;
    U8  u8ConfAprsSbPositFast_sec;
    U8  u8ConfAprsSbPositSlow_min;
    U8  u8ConfAprsSbLowSpeedLimit_kmh;
    U8  u8ConfAprsSbHighSpeedLimit_kmh;
    //--- NO user accessible configuration
    U8 u8ConfigTrackerVersion[cAPRS_VersionInfoLength+1];
    U8 u8ConfigBeaconText[cAPRS_BeaconTextLen+1];
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
