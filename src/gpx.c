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
#include "FSIO.h"
#include "gpx.h"
#include "gps_main.h"
#include "fsio_main.h"
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
static BOOL bNewTrackRequest;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/
static const char u8XmlHeader[] = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n\
<gpx\r\n\
  version=\"1.0\"\r\n\
  creator=\"GPX embedded writer by _maker_ (vladislav_1@abv.bg)\"\r\n\
  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\r\n\
  xmlns=\"http://www.topografix.com/GPX/1/0\"\r\n\
  xsi:schemaLocation=\"http://www.topografix.com/GPX/1/0 http://www.topografix.com/GPX/1/0/gpx.xsd\">\r\n\r\n";


static const char u8XmlTrackHeader[] = "\
<trk>\r\n\
<name>ACTIVE LOG %02d-%02d-%04d %02d:%02d:%02d </name>\r\n\
<trkseg>\r\n";

static const char u8XmlPosHeader[] = "\
<trkpt lat=\"%s\" lon=\"%s\">\r\n\
<ele>%d</ele>\r\n\
<time>%s</time>\r\n";

static const char u8XmlPosCloseHeader[]   = "</trkpt>\r\n";
static const char u8XmpTrackCloseHeader[] = "</trkseg>\r\n</trk>\r\n";
static const char u8XmlCloseHeader[]      = "</gpx>\r\n";

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
static void    Gpx_Lat_Lon_Conversion(tNMEA_GPS_Data *GpsData                     );
static void    Gpx_PrepareGpsData    (tNMEA_GPS_Data *GpsData                     );
static BOOL    Gpx_IsFileEmpty       (U16             u16HederLength, FSFILE *file);
static HRESULT Gpx_WriteFileData     (tNMEA_GPS_Data *GpsData                     );


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
void Gpx_Init(void)
{
    // start by track default
    bNewTrackRequest = cTrue;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
HRESULT Gpx_WritePosition(tNMEA_GPS_Data *GpsData)
{
    HRESULT res = S_NOK;

    Gpx_PrepareGpsData(GpsData);

    res = Gpx_WriteFileData(GpsData);

    return res;
}

/*=====================================================================================================================
 *                                                                            
 *                                     L O C A L    F U N C T I O N S                   
 *                                                                            
 *===================================================================================================================*/
static HRESULT Gpx_WriteFileData(tNMEA_GPS_Data *GpsData)
{
    HRESULT res = S_NOK;
    FSFILE* gpx_file = NULL;
    // filename example: 2013-02-18_log.gpx
    U8 u8GpxFileName[19+1];
    BOOL bFileIsEmpty = cTrue;
    U8 u8OutBuff[200];
    U16 u16Index = 0;
    U8 u8Size;

    // compose filename
    sprintf((char*) u8GpxFileName, "%04d-%02d-%02d_log.gpx", GpsData->DateTime.tm_year, GpsData->DateTime.tm_mon, GpsData->DateTime.tm_mday);

    gpx_file = FSfopen((const char*)u8GpxFileName, FS_APPEND);

    if(NULL != gpx_file)
    {
        // check that file is empty or not
        bFileIsEmpty = Gpx_IsFileEmpty(sizeof(u8XmlHeader), gpx_file);

        if(cTrue == bFileIsEmpty)
        {
            // write header
            if(0 < FSfwrite(u8XmlHeader, 1, (sizeof(u8XmlHeader)-1), gpx_file))
                res = S_OK;
            else
                res = S_NOK;

            // start track by default
             u16Index = sprintf((char*)&u8OutBuff[0], (const char*)u8XmlTrackHeader, GpsData->DateTime.tm_mday,
                                                                                     GpsData->DateTime.tm_mon,
                                                                                     GpsData->DateTime.tm_year,
                                                                                     GpsData->DateTime.tm_hour,
                                                                                     GpsData->DateTime.tm_min,
                                                                                     GpsData->DateTime.tm_sec);
        }

        if (cFalse == bFileIsEmpty)
        {
            u8Size  = strlen(u8XmpTrackCloseHeader);
            u8Size += strlen(u8XmlCloseHeader);

            if(0 == FSfseek(gpx_file, (u8Size+1), SEEK_END))
                res = S_OK;
            else
                res = S_NOK; 
        }

        u16Index += sprintf((char*)&u8OutBuff[u16Index], (const char*)u8XmlPosHeader, GpsGpxData.GpxLatitudeDec,
                                                                                      GpsGpxData.GpxLongitudeDec,
                                                                                      GpsData->u16Altitude,
                                                                                      GpsGpxData.GpxTime);


        u16Index += sprintf((char*)&u8OutBuff[u16Index], "%s", u8XmlPosCloseHeader);
        u16Index += sprintf((char*)&u8OutBuff[u16Index], "%s", u8XmpTrackCloseHeader);
        u16Index += sprintf((char*)&u8OutBuff[u16Index], "%s", u8XmlCloseHeader);

        if(0 < FSfwrite(u8OutBuff, 1, u16Index, gpx_file))
            res = S_OK;
        else
            res = S_NOK;
    }

    _assert(u16Index < sizeof(u8OutBuff));

    if(0 == FSfclose(gpx_file))
        res = S_OK;
    else
        res = S_NOK;

    return res;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static BOOL Gpx_IsFileEmpty(U16 u16HederLength, FSFILE *file)
{
    BOOL bRet = cTrue;
    U32 u32CurrentPos;

    if(file != NULL && u16HederLength != 0)
    {
        // check that end of file location is bigger or equal than gpx header
        u32CurrentPos = FSftell(file);

        if(u16HederLength <= u32CurrentPos)
        {
            // we are sure that file is not empty
            bRet = cFalse;
        }
    }

    return bRet;
}


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
                           |NMEA       |  Decimal
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
    sprintf((char*)GpsGpxData.GpxLatitudeDec, "%2.8f", f64LatF);

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
    sprintf((char*)GpsGpxData.GpxLongitudeDec, "%2.8f", f64LonF);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/

