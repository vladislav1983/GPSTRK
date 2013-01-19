/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __NMEA_MAIN_H
#define __NMEA_MAIN_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "gps_main.h"
#include "nmea_gpgga.h"
#include "nmea_gprmc.h"
#include "nmea_gpvtg.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define cNMEATempBufferSize                 cGPS_NMEA_GGA_BufferLen     // higher buffer size in gps_main.c
#define cNMEAMaxFieldLen                    cGPS_NMEA_GGA_BufferLen     // max length of nmea message

/*
* Setup NMEA decoders in order of message priority
* Message parsing order from low to high i.e. decoder[0] will be execured first!
*/

#define cNMEADecodersInit()                                             \
{                                                                       \
    /* $GPRMC - first parse, will contain almost all data needed!*/     \
    {                                                                   \
        .NmeaDecoder      = NMEARmc_Decoder,                            \
        .uMsgFieldsNumber = 8,                                          \
        .u8BufferIndex    = cGPS_NMEA_RMC_BuffIndex,                    \
        .u8BufferSize     = cGPS_NMEA_RMC_MsgLen                        \
    },                                                                  \
    /* $GPGGA */                                                        \
    {                                                                   \
        .NmeaDecoder      = NMEAGga_Decoder,                            \
        .uMsgFieldsNumber = 13,                                         \
        .u8BufferIndex    = cGPS_NMEA_GGA_BuffIndex,                    \
        .u8BufferSize     = cGPS_NMEA_GGA_MsgLen                        \
    },                                                                  \
    /* $GPVTG */                                                        \
    {                                                                   \
        .NmeaDecoder      = NMEAVtg_Decoder,                            \
        .uMsgFieldsNumber = 8,                                          \
        .u8BufferIndex    = cGPS_NMEA_VTG_BuffIndex,                    \
        .u8BufferSize     = cGPS_NMEA_VTG_MsgLen                        \
    }                                                                   \
}

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern tNMEA_GPS_Data NMEA_GPS_Data;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void NMEAMain_DecodeTask(void);

#endif /* __NMEA_MAIN_H */
