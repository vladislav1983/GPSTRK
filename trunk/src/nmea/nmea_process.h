/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __NMEA_PROCESS_H
#define __NMEA_PROCESS_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "gps_main.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define cAprsProcNotSend                ((tAprsTrmtCmd)(0u))
#define cAprsProcSendData               ((tAprsTrmtCmd)(1u))
#define cAprsProcSendTrackerInfo        ((tAprsTrmtCmd)(2u))

// references to smart beaconing structures
#define cAprsSmartBeaconingRef()                                                        \
{                                                                                       \
    .u16BeaconTimeStamp         =  0,                                                   \
    .s16CourseChangeSinceBeacon =  0,                                                   \
    .u16SmartBeaconingRateSec   =  0,                                                   \
    .s16LastCourse              = -1,                                                   \
    .u8TurnThreshold            =  0,                                                   \
    .pu16SbInterval_sec         = &DeviceConfigParams.u16ConfAprsSbInterval_sec,        \
    .pu8SbPositFast_sec         = &DeviceConfigParams.u8ConfAprsSbPositFast_sec,        \
    .pu8SbPositSlow_min         = &DeviceConfigParams.u8ConfAprsSbPositSlow_min,        \
    .pu8SbLowSpeedLimit_kmh     = &DeviceConfigParams.u8ConfAprsSbLowSpeedLimit_kmh,    \
    .pu8SbHighSpeedLimit_kmh    = &DeviceConfigParams.u8ConfAprsSbHighSpeedLimit_kmh    \
}
#define cGpxSmartBeaconingRef()                                                         \
{                                                                                       \
    .u16BeaconTimeStamp         =  0,                                                   \
    .s16CourseChangeSinceBeacon =  0,                                                   \
    .u16SmartBeaconingRateSec   =  0,                                                   \
    .s16LastCourse              = -1,                                                   \
    .u8TurnThreshold            =  0,                                                   \
    .pu16SbInterval_sec         = &DeviceConfigParams.u16ConfGpxSbInterval_sec,         \
    .pu8SbPositFast_sec         = &DeviceConfigParams.u8ConfGpxSbPositFast_sec,         \
    .pu8SbPositSlow_min         = &DeviceConfigParams.u8ConfGpxSbPositSlow_min,         \
    .pu8SbLowSpeedLimit_kmh     = &DeviceConfigParams.u8ConfGpxSbLowSpeedLimit_kmh,     \
    .pu8SbHighSpeedLimit_kmh    = &DeviceConfigParams.u8ConfGpxSbHighSpeedLimit_kmh     \
}


/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef U8 tAprsTrmtCmd;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
typedef struct tsSmartBeaconingRef
{
    U16 u16BeaconTimeStamp;
    S16 s16CourseChangeSinceBeacon;
    U16 u16SmartBeaconingRateSec;
    S16 s16LastCourse;
    U8  u8TurnThreshold;
    U16 *pu16SbInterval_sec;
    U8  *pu8SbPositFast_sec;
    U8  *pu8SbPositSlow_min;
    U8  *pu8SbLowSpeedLimit_kmh;
    U8  *pu8SbHighSpeedLimit_kmh;
}tSmartBeaconingRef;
/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _NMEAProc_Init()            NMEAProc_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void NMEAProc_Init(void);
extern tAprsTrmtCmd NMEAProc_AprsProcessingTransmit(tNMEA_GPS_Data *GpsData);
extern BOOL NMEAProc_PositioningWriteProcess(tNMEA_GPS_Data *GpsData);

#endif /* __NMEA_PROCESS_H */
