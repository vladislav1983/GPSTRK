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
#ifdef __DEVCONFIG_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __DEVCONFIG_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "devconfig.h"
#include "minIni.h"
#include "app_statemachine.h"


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
const char inifile[] = "devconfig.ini";

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
struct sDeviceConfigParams DeviceConfigParams = cDeviceConfigParamsInit();

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
 * Description: 
 *===================================================================================================================*/
HRESULT Devconfig_LoadConfig(void)
{
    HRESULT result = S_NOK;
    U16 u16Tmp;
    size_t len;
    char str[2];

    //==================================================================================================================
    // APRS_SETTINGS
    //==================================================================================================================
    DeviceConfigParams.u8ConfAprsTxDelay = (U8)ini_getl("APRS_SETTINGS", "tx_delay", 30UL, inifile);
    DeviceConfigParams.u8ConfAprsPropath = (U8)ini_getl("APRS_SETTINGS", "propath", 0UL, inifile);

    // get simbol table
    str[0] = DeviceConfigParams.u8ConfAprsSymbolTable;
    str[1] = '\0';
    len = ini_gets("APRS_SETTINGS", 
                   "aprs_simbol_table",
                   (char*)str,
                   (char*)str,
                   sizeof(str),
                   inifile);
    
    DeviceConfigParams.u8ConfAprsSymbolTable = str[0];

    // get aprs symbol
    str[0] = DeviceConfigParams.u8ConfAprsSymbol;
    str[1] = '\0';
    len = ini_gets("APRS_SETTINGS", 
                   "aprs_simbol",
                   (char*)str,
                   (char*)str,
                   sizeof(str),
                   inifile);

    DeviceConfigParams.u8ConfAprsSymbol = str[0];

    // get AX25 source address
    len = ini_gets("APRS_SETTINGS", 
                   "src_addr", 
                   (char*)DeviceConfigParams.u8ConfigAprsSourceAddr, 
                   (char*)DeviceConfigParams.u8ConfigAprsSourceAddr,
                   sizeof(DeviceConfigParams.u8ConfigAprsSourceAddr),
                   inifile);
    // fill unspecified bytes with spaces
    if(len < (sizeof(DeviceConfigParams.u8ConfigAprsSourceAddr) - 1))
    {
        memset((U8*)&DeviceConfigParams.u8ConfigAprsSourceAddr[len+1], ' ', (sizeof(DeviceConfigParams.u8ConfigAprsSourceAddr) - len));
        DeviceConfigParams.u8ConfigAprsSourceAddr[sizeof(DeviceConfigParams.u8ConfigAprsSourceAddr)-1] = '\0';
    }

    // get AX25 destination address
    len = ini_gets("APRS_SETTINGS", 
                   "dst_addr", 
                   (char*)DeviceConfigParams.u8ConfigAprsDestAddr, 
                   (char*)DeviceConfigParams.u8ConfigAprsDestAddr,
                   sizeof(DeviceConfigParams.u8ConfigAprsDestAddr),
                   inifile);

    // fill unspecified bytes with spaces
    if(len < (sizeof(DeviceConfigParams.u8ConfigAprsDestAddr) - 1))
    {
        memset((U8*)&DeviceConfigParams.u8ConfigAprsDestAddr[len+1], ' ', (sizeof(DeviceConfigParams.u8ConfigAprsDestAddr) - len));
        DeviceConfigParams.u8ConfigAprsDestAddr[sizeof(DeviceConfigParams.u8ConfigAprsDestAddr)-1] = '\0';
    }

    // get AX25 relay address
    len = ini_gets("APRS_SETTINGS", 
                   "relay_addr", 
                   (char*)DeviceConfigParams.u8ConfigAprsDigipeater, 
                   (char*)DeviceConfigParams.u8ConfigAprsDigipeater,
                   sizeof(DeviceConfigParams.u8ConfigAprsDigipeater),
                   inifile);

    // fill unspecified bytes with spaces
    if(len < (sizeof(DeviceConfigParams.u8ConfigAprsDigipeater) - 1))
    {
        memset((U8*)&DeviceConfigParams.u8ConfigAprsDigipeater[len+1], ' ', (sizeof(DeviceConfigParams.u8ConfigAprsDigipeater) - len));
        DeviceConfigParams.u8ConfigAprsDigipeater[sizeof(DeviceConfigParams.u8ConfigAprsDigipeater)-1] = '\0';
    }

    //==================================================================================================================
    // APRS_SB_SETTINGS
    //==================================================================================================================
    u16Tmp= (U16)ini_getl("APRS_SB_SETTINGS", "sb_interval_min", 5UL, inifile);
    DeviceConfigParams.u16ConfAprsSbInterval_sec  = u16Tmp * 60u;

    DeviceConfigParams.u8ConfAprsSbPositFast_sec = (U8)ini_getl("APRS_SB_SETTINGS",                                     /* \param Section  */
                                                                "sb_posit_fast_sec",                                    /* \param Key      */
                                                                 DeviceConfigParams.u8ConfAprsSbPositFast_sec,          /* \param DefValue */
                                                                 inifile);                                              /* \param Filename */
    DeviceConfigParams.u8ConfAprsSbPositSlow_min = (U8)ini_getl("APRS_SB_SETTINGS",                                     /* \param Section  */
                                                                "sb_posit_slow_min",                                    /* \param Key      */
                                                                 DeviceConfigParams.u8ConfAprsSbPositSlow_min,          /* \param DefValue */
                                                                 inifile);                                              /* \param Filename */
    DeviceConfigParams.u8ConfAprsSbLowSpeedLimit_kmh = (U8)ini_getl("APRS_SB_SETTINGS",                                 /* \param Section  */
                                                                    "sb_low_speed_limit_kmh",                           /* \param Key      */
                                                                     DeviceConfigParams.u8ConfAprsSbLowSpeedLimit_kmh,  /* \param DefValue */
                                                                     inifile);                                          /* \param Filename */
    DeviceConfigParams.u8ConfAprsSbHighSpeedLimit_kmh = (U8)ini_getl("APRS_SB_SETTINGS",                                /* \param Section  */
                                                                     "sb_high_speed_limit_kmh",                         /* \param Key      */
                                                                      DeviceConfigParams.u8ConfAprsSbHighSpeedLimit_kmh,/* \param DefValue */
                                                                      inifile);                                         /* \param Filename */

    //==================================================================================================================
    // GPX_SB_SETTINGS
    //==================================================================================================================
    u16Tmp= (U16)ini_getl("GPX_SB_SETTINGS", "gpx_wr_interval_min", 5UL, inifile);
    DeviceConfigParams.u16ConfGpxSbInterval_sec  = u16Tmp * 60u;

    DeviceConfigParams.u8ConfGpxSbPositFast_sec = (U8)ini_getl("GPX_SB_SETTINGS",                                      /* \param Section  */
                                                                "gpx_wr_posit_fast_sec",                                /* \param Key      */
                                                                 DeviceConfigParams.u8ConfGpxSbPositFast_sec,           /* \param DefValue */
                                                                 inifile);                                              /* \param Filename */
    DeviceConfigParams.u8ConfGpxSbPositSlow_min = (U8)ini_getl("GPX_SB_SETTINGS",                                      /* \param Section  */
                                                                "gpx_wr_posit_slow_min",                                /* \param Key      */
                                                                 DeviceConfigParams.u8ConfGpxSbPositSlow_min,           /* \param DefValue */
                                                                 inifile);                                              /* \param Filename */
    DeviceConfigParams.u8ConfGpxSbLowSpeedLimit_kmh = (U8)ini_getl("GPX_SB_SETTINGS",                                  /* \param Section  */
                                                                    "gpx_wr_low_speed_limit_kmh",                       /* \param Key      */
                                                                     DeviceConfigParams.u8ConfGpxSbLowSpeedLimit_kmh,   /* \param DefValue */
                                                                     inifile);                                          /* \param Filename */
    DeviceConfigParams.u8ConfGpxSbHighSpeedLimit_kmh = (U8)ini_getl("GPX_SB_SETTINGS",                                 /* \param Section  */
                                                                     "gpx_wr_high_speed_limit_kmh",                     /* \param Key      */
                                                                      DeviceConfigParams.u8ConfGpxSbHighSpeedLimit_kmh, /* \param DefValue */
                                                                      inifile);                                         /* \param Filename */

    result = S_OK;

    return(result);
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
