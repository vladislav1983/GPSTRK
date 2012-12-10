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
    size_t len;
    char str[2];

    DeviceConfigParams.u8ConfAprs25BeaconInterval_s = (U8)ini_getl("APRS_settings", "beacon_interval", 5UL, inifile);
    DeviceConfigParams.u8ConfAprsTxDelay = (U8)ini_getl("APRS_settings", "tx_delay", 30UL, inifile);
    DeviceConfigParams.u8ConfAprsPropath = (U8)ini_getl("APRS_settings", "propath", 0UL, inifile);

    // get simbol table
    str[0] = DeviceConfigParams.u8ConfAprsSymbolTable;
    str[1] = '\0';
    len = ini_gets("APRS_settings", 
                   "aprs_simbol_table",
                   (char*)str,
                   (char*)str,
                   sizeof(str),
                   inifile);
    
    DeviceConfigParams.u8ConfAprsSymbolTable = str[0];

    // get aprs symbol
    str[0] = DeviceConfigParams.u8ConfAprsSymbol;
    str[1] = '\0';
    len = ini_gets("APRS_settings", 
                   "aprs_simbol",
                   (char*)str,
                   (char*)str,
                   sizeof(str),
                   inifile);

    DeviceConfigParams.u8ConfAprsSymbol = str[0];

    // get AX25 source address
    len = ini_gets("APRS_settings", 
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
    len = ini_gets("APRS_settings", 
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
    len = ini_gets("APRS_settings", 
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

