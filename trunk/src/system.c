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
#ifdef __SYSTEM_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __SYSTEM_C 
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "system.h"
#include "alarm.h"
#include "kernelparam.h"
#include "nmea_main.h"
#include "pps_mcp.h"
#include "fsio_main.h"
#include "nmea_main.h"
#include "nmea_process.h"
#include "app_statemachine.h"
#include "aprs.h"
#include "ax25.h"
#include "dio.h"
#include "gps_main.h"
#include "hd44780.h"
#include "measure.h"
#include "timer.h"
#include "vadc.h"
#include "vtime.h"
#include "vuart.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/
#define cRefreshWatchDogPeriodUs            80E3
#define CLOCK_SWITCH                        0

/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _UnlockPeripherialPinSelect()       __builtin_write_OSCCONL(OSCCON & 0xbf) // unlock PPS
#define _LockPeripherialPinSelect()         __builtin_write_OSCCONL(OSCCON | 0x40) // lock   PPS

/*=====================================================================================================================
 * Local types
 *===================================================================================================================*/

/*=====================================================================================================================
 * Local data
 *===================================================================================================================*/
static tOSAlarm RefreshWatchDogAlarm;

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
#if CLOCK_SWITCH == 1
static void ClockSwitch(U16 u16ClockSouce);
#endif
static void SetupPeripheralPinSelect(void);
static void ClockInit(void);

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
void System_Init(void)
{
// drivers initialization
#ifdef _Timer1Init
    _Timer1Init();
#endif
#ifdef _SoftTimersInit
    _SoftTimersInit();
#endif
#ifdef _Adc_Init
    _Adc_Init();
#endif
#ifdef _Uart_Init
    _Uart_Init();
#endif
#ifdef _AX25_Init
    _AX25_Init();
#endif
#ifdef _HD44780_Init
    _HD44780_Init();
#endif
// application initialization
#ifdef _System_WDT_Init
    _System_WDT_Init();
#endif
#ifdef _FsioMain_Init
    _FsioMain_Init();
#endif
#ifdef _NMEAMain_Init
    _NMEAMain_Init();
#endif
#ifdef _NMEAProc_Init
    _NMEAProc_Init();
#endif
#ifdef _Arps_Init
    _Arps_Init();
#endif
#ifdef _DioInit
    _DioInit();
#endif
#ifdef _GPSMain_Init
    _GPSMain_Init();
#endif

#ifdef _Measure_Init
    _Measure_Init();
#endif
#ifdef _VTime_Init
    _VTime_Init();
#endif
#ifdef _System_StreamsInit
    _System_StreamsInit();
#endif
// application initialization
#ifdef _App_Init
    _App_Init();
#endif
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void System_StreamsInit(void)
{
    //out=fopen("l","w");
    //fprintf(out,"testo");
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void System_EnterSleep(void)
{

}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void System_LeaveSleep(void)
{

}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void _system_lowlevel_init(void)
{   
    _WatchDOgDisable();

    ClockInit();

#if CLOCK_SWITCH == 1
    /* Init CPU clock before startup OS */
    ClockSwitch(FNOSC_FRCPLL); 
#endif

    SetupPeripheralPinSelect();

    _WatchDOgEnable();
} 

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void System_WDT_Init(void)
{
    /* Init refresh watchdog task */
    RefreshWatchDogAlarm.TaskID = cRefreshWatchDogTaskId;
    OsSetAlarm(&RefreshWatchDogAlarm, cRefreshWatchDogPeriodUs/cOsAlarmTickUs);
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void RefreshWatchDogTask(void)
{
    asm volatile ("clrwdt");
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
void IdleTask(void)
{
    
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
 * Description: Peripheral remapping setup
 *===================================================================================================================*/
static void SetupPeripheralPinSelect(void)
{
    _UnlockPeripherialPinSelect();

    /*
    ** This is hardware specific pin remapping
    */
    // RP23 -> U1RX
    iPPSInput(IN_FN_PPS_U1RX, IN_PIN_PPS_RP23);
    // U1TX -> RP24
    iPPSOutput(OUT_PIN_PPS_RP24, OUT_FN_PPS_U1TX);
    // RP21 -> SCK1
    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_SCK1OUT);
    // SDI1 -> RP19
    iPPSInput(IN_FN_PPS_SDI1, IN_PIN_PPS_RP19);
    // SDO1 -> RP26
    iPPSOutput(OUT_PIN_PPS_RP26, OUT_FN_PPS_SDO1);
    // OC1 -> RP10
    iPPSOutput(OUT_PIN_PPS_RP10, OUT_FN_PPS_OC1);

    _LockPeripherialPinSelect();
}

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void ClockInit(void)
{
    CLKDIVbits.ROI = 0;     // 0 = Interrupts have no effect on the DOZEN bit
    CLKDIVbits.DOZE = 0;    // CPU Peripheral Clock Ratio Select bits
    CLKDIVbits.DOZEN = 0;   // CPU peripheral clock ratio set to 1:1
    CLKDIVbits.RCDIV = 0;   // FRC Postscaler Select bits 000 = 8 MHz (divide by 1)
}

#if CLOCK_SWITCH == 1
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
static void ClockSwitch(U16 u16ClockSouce)
{
        // Place the new oscillator selection in W0
        asm volatile ("mov		w0,w1");

        // if NOSC_SOSC, OSCCONL = 0x3, else OSCCONL = 0x1.
        asm volatile ("mov		#0, w2");
        asm volatile ("mov		#4, w4");
        asm volatile ("cpsne	w0, w4");
        asm volatile ("mov.b	#3, w2");
        asm volatile ("ior		#1, w2");
        asm volatile ("mov.b	w2, w4");

        asm volatile ("mov.b 	OSCCONH,WREG");
        asm volatile ("and		#0xF8,w0");
        asm volatile ("ior		w0,w1,w0");

        // OSCCONH(High byte) Unlock Sequence
        asm volatile ("mov 	#OSCCONH, w1");
        asm volatile ("mov 	#0x78, w2");
        asm volatile ("mov 	#0x9a, w3");
        asm volatile ("mov.b 	w2, [w1]");
        asm volatile ("mov.b 	w3, [w1]");

        // Set New Oscillator Selection
        asm volatile ("mov.b 	WREG,OSCCONH");

        // OSCCONL(Low byte) Unlock Sequence
        asm volatile ("mov 	#OSCCONL, w1");
        asm volatile ("mov 	#0x46, w2");
        asm volatile ("mov 	#0x57, w3");
        asm volatile ("mov.b 	w2, [w1]");
        asm volatile ("mov.b 	w3, [w1]");

        // Start Oscillator Switch Operation
        asm volatile ("mov.b	w4, [w1]");

        // wait oscillator switch to complete
        while(OSCCONbits.OSWEN != 0);
}
#endif
