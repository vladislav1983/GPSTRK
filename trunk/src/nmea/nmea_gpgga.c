/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
// $GPGGA
// Global Positioning System Fix Data. Time, position and fix related data for a GPS receiver.
// 
// eg2. $--GGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx
// 
// hhmmss.ss = UTC of position 
// llll.ll = latitude of position
// a = N or S
// yyyyy.yy = Longitude of position
// a = E or W 
// x = GPS Quality indicator (0=no fix, 1=GPS fix, 2=Dif. GPS fix) 
// xx = number of satellites in use 
// x.x = horizontal dilution of precision 
// x.x = Antenna altitude above mean-sea-level
// M = units of antenna altitude, meters 
// x.x = Geoidal separation
// M = units of geoidal separation, meters 
// x.x = Age of Differential GPS data (seconds) 
// xxxx = Differential reference station ID 
//
// eg3. $GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
// 1    = UTC of Position
// 2    = Latitude
// 3    = N or S
// 4    = Longitude
// 5    = E or W
// 6    = GPS quality indicator (0=invalid; 1=GPS fix; 2=Diff. GPS fix)
// 7    = Number of satellites in use [not those in view]
// 8    = Horizontal dilution of position
// 9    = Antenna altitude above/below mean sea level (geoid)
// 10   = Meters  (Antenna height unit)
// 11   = Geoidal separation (Diff. between WGS-84 earth ellipsoid and mean sea level.  -=geoid is below WGS-84 ellipsoid)
// 12   = Meters  (Units of geoidal separation)
// 13   = Age in seconds since last update from diff. reference station
// 14   = Diff. reference station ID#
// 15   = Checksum

/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __NMEA_GPGGA_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __NMEA_GPGGA_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include <stdlib.h>
#include "nmea_gpgga.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cGGA_LatitudeIndex              2
#define cGGA_LongitudeIndex             4
#define cGGA_FixQualityIndex            6
#define cGGA_AltitudeIndex              9


/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/


/*=====================================================================================================================
 *
 *                                  E X P O R T E D    F U N C T I O N S
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: Global Positioning System Fix Data

        GGA,123519,4807.0389,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42
           123519       Fix taken at 12:35:19 UTC
           4807.0389,N   Latitude 48 deg 07.0389' N
           01131.324,E  Longitude 11 deg 31.324' E
           1            Fix quality: 0 = invalid, 1 = GPS fix, 2 = DGPS fix, 3=PPS (Precise Position Service),
			                         4=RTK (Real Time Kinematic) with fixed integers, 5=Float RTK, 6=Estimated, 7=Manual, 8=Simulator
           08           Number of satellites being tracked
           0.9          Horizontal dilution of position
           545.4,M      Altitude, Meters above mean sea level
           46.9,M       Height of geoid (mean sea level) above WGS84
                        ellipsoid, in Meters
           (empty field) time in seconds since last DGPS update
           (empty field) DGPS station ID number (0000-1023)
           fields
           0: $GPGGA,
           1: 185248.000,   - time
           2: 4240.2146,    - lat
           3: N,            - lat
           4: 02317.7143,   - lon
           5: E,            - lon
           6: 1,            - fix quality
           7: 10,           - sat number
           8: 0.83,
           9: 599.0,        - alt
           10: M,
           11: 36.7,
           12: M,,
           *66
 *===================================================================================================================*/
GpsMask NMEAGga_Decoder(U8 *pu8GpsField[], tNMEA_GPS_Data* GpsData, GpsMask GpsStat)
{
    GpsMask GpsStatLocal = GpsStat;
    U8 u8Char;

    GpsData->u8GpsFixStatus = atoi((const char*)pu8GpsField[cGGA_FixQualityIndex]);
    GpsStatLocal |= cGPS_STAT_ONLINE_SET;

    if(GpsData->u8GpsFixStatus > cGPS_STATUS_NO_FIX)
    {
        // get latitude, longitude
        if(    ((GpsStatLocal & cGPS_STAT_LATLON_SET) ==   0)
            && (*pu8GpsField[cGGA_LatitudeIndex]      != '\0')
            && (*pu8GpsField[cGGA_LongitudeIndex]     != '\0') )
        {
            memcpy(GpsData->AX25_GPS_Data.u8Latitude, pu8GpsField[cGGA_LatitudeIndex], (sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1));
            GpsData->AX25_GPS_Data.u8Latitude[(sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1)] = *pu8GpsField[cGGA_LatitudeIndex+1]; /* N/S */

            memcpy(GpsData->AX25_GPS_Data.u8Longitude, pu8GpsField[cGGA_LongitudeIndex], (sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1));
            GpsData->AX25_GPS_Data.u8Longitude[(sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1)] = *pu8GpsField[cGGA_LongitudeIndex+1]; /* E/W */

            GpsStatLocal |= cGPS_STAT_LATLON_SET;
        }

        // get altitude
        if(((GpsStatLocal & cGPS_STAT_ALTITUDE_SET) == 0) && (*pu8GpsField[cGGA_AltitudeIndex] != '\0'))
        {
            GpsData->u16Altitude = atoi((const char*)pu8GpsField[cGGA_AltitudeIndex]);

            memset(GpsData->AX25_GPS_Data.u8Altitude, '0', sizeof(GpsData->AX25_GPS_Data.u8Altitude));
            // for ax25 it need a leading zeros.
            while(((u8Char = *pu8GpsField[cGGA_AltitudeIndex]++) != '.') && (u8Char != '\0'))
            {
                GpsData->AX25_GPS_Data.u8Altitude[0] = GpsData->AX25_GPS_Data.u8Altitude[1];
                GpsData->AX25_GPS_Data.u8Altitude[1] = GpsData->AX25_GPS_Data.u8Altitude[2];
                GpsData->AX25_GPS_Data.u8Altitude[2] = GpsData->AX25_GPS_Data.u8Altitude[3];
                GpsData->AX25_GPS_Data.u8Altitude[3] = u8Char;
            }

            GpsStatLocal |= cGPS_STAT_ALTITUDE_SET;
        }
    }

    return GpsStatLocal;
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/

