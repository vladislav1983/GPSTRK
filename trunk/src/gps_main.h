/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __GPS_MAIN_H
#define __GPS_MAIN_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "vuart.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
// NMEA start
#define cNMEAHeaserStart                '$'

// GPS UART settings
#define cGPS_UART                       UART1
#define cGPS_Baudrate                   9600UL
#define cGPS_ParityBits                 UART_NO_PAR_8BIT
#define cGPS_StopBits                   UART_1STOPBIT
#define cGPS_UartRxIntPriority          3
#define cGPS_UartTxIntPriority          0

// buffer indexes
#define cGPS_NMEA_GGA_BuffIndex         0
#define cGPS_NMEA_RMC_BuffIndex         1
#define cGPS_NMEA_VTG_BuffIndex         2
#define cGPS_BuffersNb                  3

#define cGPS_NMEA_GGA_MsgLen            80UL
#define cGPS_NMEA_RMC_MsgLen            70UL
#define cGPS_NMEA_VTG_MsgLen            37UL

#define cGPS_NMEA_GGA_BufferLen         (cGPS_NMEA_GGA_MsgLen + 1UL) // + 1 for null terminating character '\0'
#define cGPS_NMEA_RMC_BufferLen         (cGPS_NMEA_RMC_MsgLen + 1UL)
#define cGPS_NMEA_VTG_BufferLen         (cGPS_NMEA_VTG_MsgLen + 1UL)

// GPS status masks
#define cGPS_STAT_ONLINE_SET            0x0001UL
#define cGPS_STAT_TIME_SET              0x0002UL
#define cGPS_STAT_DATE_SET              0x0004UL
#define cGPS_STAT_LATLON_SET            0x0008UL
#define cGPS_STAT_ALTITUDE_SET          0x0010UL
#define cGPS_STAT_SPEED_SET             0x0020UL
#define cGPS_STAT_COURSE_SET            0x0040UL
#define cGPS_STAT_CLIMB_SET             0x0080UL
#define cGPS_STAT_STATUS_SET            0x0100UL
#define cGPS_STAT_MODE_SET              0x0200UL
#define cGPS_STAT_HDOP_SET              0x0400UL
#define cGPS_STAT_VDOP_SET              0x0800UL
#define cGPS_STAT_PDOP_SET              0x1000UL
#define cGPS_STAT_TDOP_SET              0x2000UL
#define cGPS_STAT_GDOP_SET              0x4000UL
#define cGPS_STAT_HERR_SET              0x8000UL


/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef U16 tGpsMask;

typedef struct tsAX25_GPS_Data
{
    U8 u8Latitude[8];
    U8 u8Longitude[9];
    U8 u8Altitude[6];
    U8 u8Course[3];
    U8 u8Speed[3];
}tAX25_GPS_Data;

typedef struct tsNMEA_GPS_Data
{
    // GPS string data 
    tAX25_GPS_Data AX25_GPS_Data;

    // GPS decimal data
    U16 u16GpsSpeed;
    U16 u16GpsCouse;
    U16 u16Altitude;
    U16 u16SatNumber;
    struct tm DateTime;

    // Status of GPS. Get from GGA message
#define cGPS_STATUS_NO_FIX              0	/* no */
#define cGPS_STATUS_FIX                 1	/* yes, without DGPS */
#define cGPS_STATUS_DGPS_FIX            2	/* yes, with DGPS */
    U8 u8GpsFixStatus;

    // GPS mode
#define cGPS_MODE_MODE_NOT_SEEN         0	/* mode update not seen yet */
#define cGPS_MODE_NO_FIX                1	/* none */
#define cGPS_MODE_2D                    2	/* good for latitude/longitude */
#define cGPS_MODE_3D                    3	/* good for altitude/climb too */
    U8 u8GpsMode;

}tNMEA_GPS_Data;

//decoder function
typedef tGpsMask (*NmeaDecoderFct)(U8 *pu8GpsField[], tNMEA_GPS_Data *GpsData, tGpsMask GpsStat);

typedef struct tsNmeaDecoders
{
    NmeaDecoderFct NmeaDecoder;     // Decoder Callback
    U8 uMsgFieldsNumber;            // Number of data fields in NMEA message
    U8 u8BufferIndex;               // NMEA decoder message buffer index in gps_main.c
    U8 u8BufferSize;                // NMEA decoder buffer size
}tNmeaDecoders;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern tGpsMask GPS_STSTUS_FLAGS;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _GPSMain_Init()             GPSMain_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void    GPSMain_Init(void);
extern void    GpsMain_RxCallback(U8 u8Char);
extern U8      GPSMain_GetDataCnt(U8 u8GpsBuffIndex);
extern HRESULT GPSMain_GetMsg(U8 u8GpsBuffIndex, tMsg Msg);
extern void    GPSMain_ClearMsgBuff(U8 u8GpsBuffIndex);


#endif /* __GPS_MAIN_H */
