/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
/*=====================================================================================================================
 * Body Identification  
 *===================================================================================================================*/
#ifdef __GPX_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __GPX_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
// let start with this funny component
#include <math.h>
#include <stdlib.h>
#include "gpx.h"
#include "gps_main.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/

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
tGpsGpxData GpsGpxData;


/*=====================================================================================================================
 * Local Functions Prototypes
 *===================================================================================================================*/
static void Gpx_Lat_Lon_Conversion(tNMEA_GPS_Data *GpsData);
static void Gpx_PrepareGpsData(tNMEA_GPS_Data *GpsData);


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
 * Description: 
 *===================================================================================================================*/
HRESULT Gpx_WritePosition(tNMEA_GPS_Data *GpsData)
{
    HRESULT res = S_OK;

    Gpx_PrepareGpsData(GpsData);





    return res;
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
/*=====================================================================================================================
 * Parameters: GpsData
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void Gpx_PrepareGpsData(tNMEA_GPS_Data *GpsData)
{
    // GPS data processing ... heavy computations are made there ... really
    Gpx_Lat_Lon_Conversion(GpsData);

    // copy altitude -> in gpx format it meaning elevation
    memcpy(GpsGpxData.GpxAltitude, GpsData->AX25_GPS_Data.u8Altitude, sizeof(GpsData->AX25_GPS_Data.u8Altitude));

    // compose time according to ISO 8601 time format (who knows this shit? i don't)
    // YYYY-MM-DDTHH:MM:SSZ -> 2010-03-26T11:25:31Z
    sprintf((char*) GpsGpxData.GpxTime, 
                    "%04d-%02d-%02dT%02d:%02d:%02dZ",
                     GpsData->DateTime.tm_year,
                     GpsData->DateTime.tm_mon,
                     GpsData->DateTime.tm_mday,
                     GpsData->DateTime.tm_hour,
                     GpsData->DateTime.tm_min,
                     GpsData->DateTime.tm_sec);
    // let finish with these nasty constructions ... the end
}

/*=====================================================================================================================
 * Parameters: GpsData
 *
 * Return: void
 *
 * Description: This function should be called "KillThePic", but wow ... observe the naming conventions!
                Conversion from DDMM.MM format to decimal degrees
                some little example:
                           |NMEA          |  Decimal
                ---------------------------------------------------------
                latitude   | 0302.78   | 03  + (02.78/60) = 3.046412
                longitude  | 10141.82  | 101 + (41.82/60) = 101.6971

             Help for dummies! Like me :)
             Func: < modf > Ref: math.h
             Description: Splits a double precision floating-point value into fractional and integer
             parts.
             Prototype:        double modf(double x, double *pint);
             Arguments:        x double precision floating-point value pint pointer to a stored the integer part
             Return Value:     Returns the signed fractional part and pint points to the integer part.
             Remarks:          The absolute value of the fractional part is in the range of 0 (inclusive)
                               to 1 (exclusive). No domain or range error will occur.
 *===================================================================================================================*/
static void Gpx_Lat_Lon_Conversion(tNMEA_GPS_Data *GpsData)
{
    // oh no ... shit, we must working with long double values :( why?
    F64 f64LatF;
    F64 f64LonF;
    volatile F64 f64Integer;
    volatile F64 f64Fract;
    U8 u8TmpBuff[sizeof(GpsData->AX25_GPS_Data.u8Longitude)];   // temp buffer for lat/lon

    //-------------------------------------------------------------------------------------------------------
    // copy only useful (numeric) information from latitude
    memcpy(u8TmpBuff, GpsData->AX25_GPS_Data.u8Latitude, sizeof(GpsData->AX25_GPS_Data.u8Latitude));
    // terminate string
    u8TmpBuff[sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1] = '\0';

    // convert latitude string to value
    (void)sscanf((char*)u8TmpBuff, "%lf", &f64LatF);
    // split double precision floating-point value into fractional and integer
    // DDMM.MM -> DD + (MM.MM/60)
    f64Fract = 100.0 * modf((f64LatF / 100.0), (double*)&f64Integer);
    f64LatF = f64Integer + (f64Fract / 60.0);

    // check where latitude is north (N) or south (S)
    if(GpsData->AX25_GPS_Data.u8Latitude[sizeof(GpsData->AX25_GPS_Data.u8Latitude)-1] == 'S')
    {
        f64LatF = -f64LatF;
    }
    // print to formatted string
    sprintf((char*)GpsGpxData.GpxLatitudeDec, "%f", f64LatF);

    //-------------------------------------------------------------------------------------------------------
    // copy only useful (numeric) information from longitude
    memcpy(u8TmpBuff, GpsData->AX25_GPS_Data.u8Longitude, sizeof(GpsData->AX25_GPS_Data.u8Longitude));
    // terminate string
    u8TmpBuff[sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1] = '\0';

    // convert longitude string to value
    sscanf((char*)u8TmpBuff, "%lf", &f64LonF);
    // split double precision floating-point value into fractional and integer
    // DDDMM.MM -> DDD + (MM.MM/60)
    f64Fract = 100.0 * modf((f64LonF / 100.0), (double*)&f64Integer);
    f64LonF = f64Integer + (f64Fract / 60.0);

    // check where latitude is east (E) or west (W)
    if(GpsData->AX25_GPS_Data.u8Longitude[sizeof(GpsData->AX25_GPS_Data.u8Longitude)-1] == 'W')
    {
        f64LatF = -f64LatF;
    }
    // print to formatted string
    sprintf((char*)GpsGpxData.GpxLongitudeDec, "%f", f64LonF);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/

