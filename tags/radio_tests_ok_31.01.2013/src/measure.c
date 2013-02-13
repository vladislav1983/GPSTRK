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
#ifdef __MEASURE_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __MEASURE_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "measure.h"
#include "alarm.h"
#include "kernelparam.h"
#include "kerneltimer.h"
#include "vadc.h"

/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cMeasureTaskPeriod_us           80E3
#define cAdc_VoltRef_mV                 3300UL

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm MeasureTaskAlarm;
static U16 u16AnaBuff[cAdc_ChannelsCnt];
static U32 u32Vbatt_filt;

/*=====================================================================================================================
 * Constant Local Data
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Data
 *===================================================================================================================*/
U16 u16BatteryVoltage_mv;
U16 u16Tmperature_x10;

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
void __attribute__((user_init)) Measure_Init(void)
{
    MeasureTaskAlarm.TaskID = cMeasureTaskId;
    OsSetAlarm(&MeasureTaskAlarm, (cMeasureTaskPeriod_us/cOsAlarmTickUs));
    u32Vbatt_filt = 0;
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void Measure_Task(void)
{
    tMsg Msg = {&u16AnaBuff[0], sizeof(u16AnaBuff)};

    Adc_ConvertChannels(Msg);

    // battery voltage filtration
#define cBattVoltageFilt_ms     2000UL
    u32Vbatt_filt += (S32)(S32)_mulus(((65.536 * cMeasureTaskPeriod_us ) / cBattVoltageFilt_ms), (u16AnaBuff[cAdc_BatteryVoltageChIndex] - _Hi(u32Vbatt_filt)));
    // battery voltage calculation
    u16BatteryVoltage_mv = _fmul_q15(_Hi(u32Vbatt_filt), cBatteryVoltageMax_mV);

    // temperature calculation
#if cTempSensorTemperatureCoeff == 10UL
    u16Tmperature_x10 = _fmul_q15(u16AnaBuff[cAdc_TempChIndex], cAdc_VoltRef_mV) - (U16)cTempSensorOffsetVoltagemV;
#else
    u16Tmperature_x10 = ((_fmul_q15(u16AnaBuff[cAdc_TempChIndex], cAdc_VoltRef_mV) - (U16)cTempSensorOffsetVoltagemV) / cTempSensorTemperatureCoeff);
#endif
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
