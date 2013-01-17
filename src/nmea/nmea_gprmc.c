/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
// $GPRMC
// 
// Recommended minimum specific GPS/Transit data

// eg3. $GPRMC,220516,A,5133.82,N,00042.24,W,173.8,231.8,130694,004.2,W*70
// 1    2    3    4    5     6    7    8      9     10  11 12
// 
// 
// 1   220516     Time Stamp
// 2   A          validity - A-ok, V-invalid
// 3   5133.82    current Latitude
// 4   N          North/South
// 5   00042.24   current Longitude
// 6   W          East/West
// 7   173.8      Speed in knots
// 8   231.8      True course
// 9   130694     Date Stamp
// 10  004.2      Variation
// 11  W          East/West
// 12  *70        checksum
// 
// 
// eg4. $GPRMC,hhmmss.ss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,ddmmyy,x.x,a*hh
// 1    = UTC of position fix
// 2    = Data status (V=navigation receiver warning)
// 3    = Latitude of fix
// 4    = N or S
// 5    = Longitude of fix
// 6    = E or W
// 7    = Speed over ground in knots
// 8    = Track made good in degrees True
// 9    = UT date
// 10   = Magnetic variation degrees (Easterly var. subtracts from true course)
// 11   = E or W
// 12   = Checksum

/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __NMEA_GPRMC_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __NMEA_GPRMC_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "nmea_gprmc.h"
#include "vtime.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cRMC_TimeIndex                   1
#define cRMC_FixStatusIndex              2
#define cRMC_LatitudeIndex               3
#define cRMC_LongitudeIndex              5
#define cRMC_SpeedIndex                  7
#define cRMC_CourseIndex                 8
#define cRMC_DateIndex                   9

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
 * Description: Recommend Minimum Course Specific GPS/TRANSIT Data
                 RMC,225446.33,A,4916.45,N,12311.12,W,000.5,054.7,191194,020.3,E,A*68
                 225446.33    Time of fix 22:54:46 UTC
                 A            Status of Fix A = Autonomous, valid; D = Differential, valid; V = invalid
                 4916.45,N    Latitude 49 deg. 16.45 min North
                 12311.12,W   Longitude 123 deg. 11.12 min West
                 000.5        Speed over ground, Knots
                 054.7        Course Made Good, True north
                 191194       Date of fix  19 November 1994
                 020.3,E      Magnetic variation 20.3 deg East
                 A            FAA mode indicator (NMEA 2.3 and later) A=autonomous, D=differential, E=Estimated,
                                                                      N=not valid, S=Simulator, M=Manual input mode
                 *68          mandatory nmea_checksum
                 fields[]
                 0: $GPRMC,
                 1: 185248.000, - time
                 2: A,
                 3: 4240.2146,  - lat
                 4: N,          - lat
                 5: 02317.7143, - lon
                 6: E,          - lon
                 7: 0.01,       - speed
                 8: 14.70,      - course
                 9: 241012,     - date
                 ,,A
 *===================================================================================================================*/
tGpsMask NMEARmc_Decoder(U8 *pu8GpsField[], tNMEA_GPS_Data* GpsData, tGpsMask GpsStat)
{
    tGpsMask GpsStatLocal = GpsStat;
    U8 u8Char;

    if(*pu8GpsField[cRMC_FixStatusIndex] == 'V') 
    {
        // Invalid fix
        if(GpsData->u8GpsFixStatus != cGPS_STATUS_NO_FIX)
        {
            GpsData->u8GpsFixStatus = cGPS_STATUS_NO_FIX;
            GpsStatLocal |= cGPS_STAT_ONLINE_SET;
        }

        if(GpsData->u8GpsMode >= cGPS_MODE_2D)
        {
            GpsData->u8GpsMode = cGPS_MODE_NO_FIX;
            GpsStatLocal |= cGPS_STAT_MODE_SET;
        }
    }
    else if(*pu8GpsField[cRMC_FixStatusIndex] == 'A')
    {
        // Valid fix
        // get latitude, longitude
        if(    ((GpsStatLocal & cGPS_STAT_LATLON_SET) ==   0)
            && (*pu8GpsField[cRMC_LatitudeIndex]     != '\0')
            && (*pu8GpsField[cRMC_LongitudeIndex]    != '\0') )
        {
            memcpy(GpsData->AX25_GPS_Data.u8Latitude, pu8GpsField[cRMC_LatitudeIndex], (sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1));
            GpsData->AX25_GPS_Data.u8Latitude[(sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1)] = *pu8GpsField[cRMC_LatitudeIndex+1]; /* N/S */

            memcpy(GpsData->AX25_GPS_Data.u8Longitude, pu8GpsField[cRMC_LongitudeIndex], (sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1));
            GpsData->AX25_GPS_Data.u8Longitude[(sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1)] = *pu8GpsField[cRMC_LongitudeIndex+1]; /* E/W */

            GpsStatLocal |= cGPS_STAT_LATLON_SET;
        }

        // get speed
        if(((GpsStatLocal & cGPS_STAT_SPEED_SET) == 0) && (*pu8GpsField[cRMC_SpeedIndex] != '\0'))
        {
            GpsData->u16GpsSpeed = atoi((const char*)pu8GpsField[cRMC_SpeedIndex]);
            
            memset(GpsData->AX25_GPS_Data.u8Speed, '0', sizeof(GpsData->AX25_GPS_Data.u8Speed));
            // for ax15 it need a leading zeros.
            while(((u8Char = *pu8GpsField[cRMC_SpeedIndex]++) != '.') && (u8Char != '\0'))
            {
                GpsData->AX25_GPS_Data.u8Speed[0] = GpsData->AX25_GPS_Data.u8Speed[1];
                GpsData->AX25_GPS_Data.u8Speed[1] = GpsData->AX25_GPS_Data.u8Speed[2];
                GpsData->AX25_GPS_Data.u8Speed[2] = u8Char;
            }

            GpsStatLocal |= cGPS_STAT_SPEED_SET;
        }

        // get course
        if(((GpsStatLocal & cGPS_STAT_COURSE_SET) == 0) && (*pu8GpsField[cRMC_CourseIndex] != '\0'))
        {
            GpsData->u16GpsCouse = atoi((const char*)pu8GpsField[cRMC_CourseIndex]);

            memset(GpsData->AX25_GPS_Data.u8Course, '0', sizeof(GpsData->AX25_GPS_Data.u8Course));
            // for ax15 it need a leading zeros.
            while(((u8Char = *pu8GpsField[cRMC_CourseIndex]++) != '.') && (u8Char != '\0'))
            {
                GpsData->AX25_GPS_Data.u8Course[0] = GpsData->AX25_GPS_Data.u8Course[1];
                GpsData->AX25_GPS_Data.u8Course[1] = GpsData->AX25_GPS_Data.u8Course[2];
                GpsData->AX25_GPS_Data.u8Course[2] = u8Char;
            }

            GpsStatLocal |= cGPS_STAT_COURSE_SET;
        }

        // get date
        if(((GpsStatLocal & cGPS_STAT_DATE_SET) == 0) && (*pu8GpsField[cRMC_DateIndex] != '\0'))
        {
            VTime_GpsSet_ddmmyy(pu8GpsField[cRMC_DateIndex], GpsData);

            GpsStatLocal |= cGPS_STAT_DATE_SET;
        }

        // get time
        if(((GpsStatLocal & cGPS_STAT_TIME_SET) == 0) && (*pu8GpsField[cRMC_TimeIndex] != '\0'))
        {
            VTime_GpsSet_hhmmss(pu8GpsField[cRMC_TimeIndex], GpsData);

            GpsStatLocal |= cGPS_STAT_TIME_SET;
        }

        if(GpsData->u8GpsFixStatus == cGPS_STATUS_NO_FIX)
        {
            GpsData->u8GpsFixStatus = cGPS_STATUS_FIX;
            GpsStatLocal |= cGPS_STAT_STATUS_SET;
        }

        if(GpsData->u8GpsMode <= cGPS_MODE_2D)
        {
            GpsData->u8GpsMode = cGPS_MODE_2D;
            GpsStatLocal |= cGPS_STAT_MODE_SET;
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

