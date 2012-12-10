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

#define cGPS_NMEA_GGA_MsgLen            72UL
#define cGPS_NMEA_RMC_MsgLen            69UL
#define cGPS_NMEA_VTG_MsgLen            36UL

#define cGPS_NMEA_GGA_BufferLen         (cGPS_NMEA_GGA_MsgLen + 1UL) // + 1 for null terminating character '\0'
#define cGPS_NMEA_RMC_BufferLen         (cGPS_NMEA_RMC_MsgLen + 1UL)
#define cGPS_NMEA_VTG_BufferLen         (cGPS_NMEA_VTG_MsgLen + 1UL)

// GPS status masks
#define cGPS_STAT_ONLINE_SET            0x00000001UL
#define cGPS_STAT_TIME_SET              0x00000002UL
#define cGPS_STAT_DATE_SET              0x00000004UL
#define cGPS_STAT_LATLON_SET            0x00000008UL
#define cGPS_STAT_ALTITUDE_SET          0x00000010UL
#define cGPS_STAT_SPEED_SET             0x00000020UL
#define cGPS_STAT_COURSE_SET            0x00000040UL
#define cGPS_STAT_CLIMB_SET             0x00000080UL
#define cGPS_STAT_STATUS_SET            0x00000100UL
#define cGPS_STAT_MODE_SET              0x00000200UL
#define cGPS_STAT_HDOP_SET              0x00000400UL
#define cGPS_STAT_VDOP_SET              0x00000800UL
#define cGPS_STAT_PDOP_SET              0x00001000UL
#define cGPS_STAT_TDOP_SET              0x00002000UL
#define cGPS_STAT_GDOP_SET              0x00004000UL
#define cGPS_STAT_HERR_SET              0x00008000UL


/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef U16 GpsMask;

typedef struct tsAX25_GPS_Data
{
    U8 u8Latitude[10];
    U8 u8Longitude[11];
    U8 u8Altitude[4];
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
typedef GpsMask (*NmeaDecoderFct)(U8 *pu8GpsField[], tNMEA_GPS_Data *GpsData, GpsMask GpsStat);

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
extern GpsMask GPS_STSTUS_FLAGS;

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/

/*----------------------------------------------------------------
** GPS Status flags macros
**----------------------------------------------------------------
*/
#define _gps_online()                       (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 0))
#define _set_gps_online(x)                  (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 0))

#define _gps_time_set()                     (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 1))
#define _set_gps_time_set(x)                (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 1))

#define _gps_timeerr_set()                  (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 2))
#define _set_gps_timeerr_set(x)             (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 2))

#define _gps_latlon_set()                   (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 3))
#define _set_gps_latlon_set(x)              (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 3))

#define _gps_altitude_set()                 (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 4))
#define _set_gps_altitude_set(x)            (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 4))

#define _gps_speed_set()                    (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 5))
#define _set_gps_speed_set(x)               (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 5))

#define _gps_status_set()                   (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 6))
#define _set_gps_status_set(x)              (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 6))

#define _gps_mode_set()                     (_getbit(     GPS_STSTUS_FLAGS, /*bit*/ 7))
#define _set_gps_mode_set(x)                (_putbit((x), GPS_STSTUS_FLAGS, /*bit*/ 7))




/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void __attribute__((user_init)) GPSMain_Init(void);
extern void    GpsMain_RxCallback(U8 u8Char);
extern U8      GPSMain_GetDataCnt(U8 u8GpsBuffIndex);
extern HRESULT GPSMain_GetMsg(U8 u8GpsBuffIndex, tMsg Msg);
extern void    GPSMain_ClearMsgBuff(U8 u8GpsBuffIndex);


#endif /* __GPS_MAIN_H */
