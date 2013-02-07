/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __VUART_H
#define __VUART_H

/*
** Module Identification
*/
#define __VUART

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "vuart_mcp.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/
/*
** Component config
*/
#define UART1                   0
#define UART2                   1
#define cUartModulesUsedCnt     2

// Define here UART module used
#define UART1_USED              1
#define UART2_USED              1
#define UART3_USED              0
#define UART4_USED              0

#define cUartRxFifoLevel        4

// UART driver callbacks structure initialization
#define cUART_DrvInit()                                 \
{                                                       \
    {                                                   \
        .UartInitFct    = Uart1_Init,                   \
        .UartRxCallback = GpsMain_RxCallback,           \
        .UartTxCallback = NULL,                         \
        .UartTxByte     = Uart1_TxByte                  \
    },                                                  \
    {                                                   \
        .UartInitFct    = Uart2_Init,                   \
        .UartRxCallback = GpsMain_RxCallback,           \
        .UartTxCallback = NULL,                         \
        .UartTxByte     = Uart2_TxByte                  \
    }                                                   \
}


/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef void (*tFctUartInit)(U32 u32Baudrate, U16 u16DataBitsAndParity, U16 u16StopBits, U8 u8RxPriority, U8 u8TxPriority);
typedef U8   (*tFctUartTx)(U8 u8Data);

typedef struct tsUartDrv
{
    tFctUartInit      UartInitFct;
    tFuncCallbackData UartRxCallback;
    tFuncCallbackData UartTxCallback;
    tFctUartTx        UartTxByte;
}sUartDrv;

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/
extern sUartDrv UartDrv[];

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _Uart_Init()            Uart_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern void Uart_Init(void);
extern void Uart1_Init(U32 u32Baudrate, U16 u16DataBitsAndParity, U16 u16StopBits, U8 u8RxPriority, U8 u8TxPriority);
extern void Uart2_Init(U32 u32Baudrate, U16 u16DataBitsAndParity, U16 u16StopBits, U8 u8RxPriority, U8 u8TxPriority);
extern U8   Uart1_TxByte(U8 u8Byte);
extern U8   Uart2_TxByte(U8 u8Byte);

#endif /* __VUART */
