/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __BASEDEF_H
#define __BASEDEF_H

/* 
** Module Identification
*/
#define __BASEDEF

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
#define cSYS_CLK_Hz     (32000000UL)
#define cFCY_Hz         (cSYS_CLK_Hz/2UL)
#define cFCY_MHz        (16UL)
#define cTcy_Ns         (1000UL/cFCY_MHz)

/* FCY is used by library to calculate delay functions */
#ifndef FCY
    #define FCY     cFCY_Hz
#else
    #error "FCY must be defined here!"
#endif

/*
** INTERRUPT PRIORITY LEVELS
** DO NOT USE LEVEL 7 ISR PRIORITY
*/
#define cTIMER3_ISR_Priority            (5U) // -> Highest ISR priority, above kernel ISR level!
#define cTIMER1_ISR_Priority            (4U)
#define cUART2_RX_ISR_Priority          (3U)
#define cUART2_TX_ISR_Priority          (0U)



/*
** Firmware version
*/
#define FIRMWARE_BASE_VERSION		    1000
#define FIRMWARE_SUB_VERSION		    10

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef unsigned char       U8;
typedef unsigned int        U16;
typedef unsigned long       U32;
typedef unsigned long long  U64;
typedef unsigned int        tCPUItState;

typedef signed char         S8;
typedef signed int          S16;
typedef signed long         S32;
typedef S16                 Q15;

typedef float               F32;
typedef long double         F64;
typedef U16                 tCtrl;
typedef U16                 tAddress;

typedef U8          	    BOOL;
#define cFalse              ((BOOL)(0))
#define cTrue        	    ((BOOL)(!cFalse))
typedef U16          	    HRESULT;
#define S_OK                ((HRESULT)0x00u)
#define S_FALSE             ((HRESULT)0x01u)
#define E_INVALIDARG        ((HRESULT)0x02u)
#define E_FAIL              ((HRESULT)0x03u)
#define S_NOK               ((HRESULT)0x04u)

typedef struct
{
    void* pBuff;
    U16   Lng;
}tMsg;

typedef U8 tControl;
/*
** Callback functions
*/
typedef void (*tCallback)();
typedef void (*tCallbackCtrl)(tCtrl);
typedef void (*tCallbackData)(tMsg);
typedef void (*tCallbackDataCtrl)(tCtrl, tMsg);
typedef void (*tFunc)();
typedef void (*tFuncData)(U8);
typedef void (*tFuncCallbackData)(U8);

#if !defined NULL
    #define NULL ((void*)0)
#endif

/* 
** Function parameters flow define
*/
#define _IN_ 
#define _OUT_ 

/*
** Compiler specific macros
*/
#define _DECLARE_ISR(funct)         void __attribute__((__interrupt__,no_auto_psv)) (funct)(void)
#define _DECLARE_ISRFAST(funct)     void __attribute__((__interrupt__,shadow)) (funct)(void)
/* 
** System debug definitions
*/
#if defined(__DEBUG)
    #define SMART_BEACONING_DEBUG
    //#define APRS_MSG_DEBUG
    //#define APRS_DATA_DEBUG
    #define HALT_TO_DEBUGGER
#endif


/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/


/*=====================================================================================================================
 * Included files to resolve specific definitions in project                        				                        
 *===================================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "p24FJ128GA308.h"   /* CPU header */
#include "tools.h"
#include "gps_main.h"
#include "periph_features_mcp.h"
#include "dio.h"
#include "api.h"            /* Shared API declarations */
#include "traps.h"          /* CPU traps */
#include "system.h"


#endif /* __BASEDEF_H */
