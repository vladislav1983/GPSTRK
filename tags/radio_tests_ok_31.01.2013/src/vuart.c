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
#ifdef __VUART_C
    #error "!!! FileName ID. It should be Unique !!!"
#else
    #define __VUART_C
#endif

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file
 *===================================================================================================================*/
#include "vuart.h"
#include "timer.h"
#include "gps_main.h"


/*=====================================================================================================================
 * Local constants
 *===================================================================================================================*/


/*=====================================================================================================================
 * Local macros
 *===================================================================================================================*/
#define _UART_TxBufferIsNotFull(Uart)                   ((U##Uart##STAbits.UTXBF) == 0)
#define _UART_WriteTxBuffer(Uart, Data)                 (U##Uart##TXREG = (U8)(Data))
#define _UART_IsRxBuffContainData(Uart)                 ((U##Uart##STAbits.URXDA) == 1)
#define _UART_ClearOverrunError(Uart)                   (U##Uart##STAbits.OERR = 0)
#define _UART_GetRxBuffer(Uart)                         (U##Uart##RXREG)
#define _UART_ParityError(Uart)                         ((U##Uart##STAbits.PERR) == 1)
#define _UART_FramingError(Uart)                        ((U##Uart##STAbits.FERR) == 1)



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
sUartDrv UartDrv[cUartModulesUsedCnt] = cUART_DrvInit();

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
 * Description: UART1 module initialization
 *===================================================================================================================*/
void Uart1_Init(U32 u32Baudrate, U16 u16DataBitsAndParity, U16 u16StopBits, U8 u8RxPriority, U8 u8TxPriority)
{
    U1MODE = UxMODE_VALUE;
    U1MODE = (  UART_EN                /* Module enable */
              & UART_IDLE_STOP         /* Stop all functions in IDLE mode*/
              & UART_IrDA_DISABLE      /* IrDA encoder and decoder disabled */
              & UART_MODE_SIMPLEX      /* UxRTS pin in Simplex mode */
              & UART_UEN_00            /* UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLK pins controlled by port latches*/
              & UART_DIS_WAKE          /* Disable Wake-up on START bit Detect during SLEEP Mode bit*/
              & UART_DIS_LOOPBACK      /* Loop back disabled*/
              & UART_DIS_ABAUD         /* Baud rate measurement disabled or completed*/
              & UART_UXRX_IDLE_ONE     /* UxRx Idle state is one */
              & UART_BRGH_SIXTEEN      /* BRG generates 16 clocks per bit period */
              & u16DataBitsAndParity
              & u16StopBits);

    U1BRG = (U16)(((U32)cFCY_Hz / (16UL * u32Baudrate)) - 1UL); // U1BRG = Fcy/16*Baudrate - 1;

    U1STA = UxSTA_VALUE;
    U1STA = (  UART_INT_TX                 /* Interrupt on transfer of every character to TSR */
             & UART_IrDA_POL_INV_ZERO      /* IrDA encoded, UxTX Idel state is '0' */
             & UART_SYNC_BREAK_DISABLED    /* Sync break transmission disabled or completed */
             & UART_TX_ENABLE              /* Transmit enable */
             & UART_INT_RX_CHAR            /* Interrupt on every char received */
             & UART_ADR_DETECT_DIS);       /* address detect disable */

    DisableIntU1RX;
    DisableIntU1TX;
    U1RX_Clear_Intr_Status_Bit;
    U1TX_Clear_Intr_Status_Bit;
    SetPriorityIntU1RX(u8RxPriority);
    SetPriorityIntU1TX(u8TxPriority);
    
    if(u8RxPriority != 0)
        EnableIntU1RX;
    else
        DisableIntU1RX;

    if(u8TxPriority!= 0)
        EnableIntU1TX;
    else
        DisableIntU1TX;
}
#if UART2_USED == 1
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: UART2 module initialization
 *===================================================================================================================*/
void Uart2_Init(U32 u32Baudrate, U16 u16DataBitsAndParity, U16 u16StopBits, U8 u8RxPriority, U8 u8TxPriority)
{
    U2MODE = UxMODE_VALUE;
    U2MODE = (  UART_EN                /* Module enable */
              & UART_IDLE_STOP         /* Stop all functions in IDLE mode*/
              & UART_IrDA_DISABLE      /* IrDA encoder and decoder disabled */
              & UART_MODE_SIMPLEX      /* UxRTS pin in Simplex mode */
              & UART_UEN_00            /* UxTX and UxRX pins are enabled and used; UxCTS and UxRTS/BCLK pins controlled by port latches*/
              & UART_DIS_WAKE          /* Disable Wake-up on START bit Detect during SLEEP Mode bit*/
              & UART_DIS_LOOPBACK      /* Loop back disabled*/
              & UART_DIS_ABAUD         /* Baud rate measurement disabled or completed*/
              & UART_UXRX_IDLE_ONE     /* UxRx Idle state is one */
              & UART_BRGH_SIXTEEN      /* BRG generates 16 clocks per bit period */
              & u16DataBitsAndParity
              & u16StopBits);

    U2BRG = (U16)(((U32)cFCY_Hz / (16UL * u32Baudrate)) - 1); // U1BRG = Fcy/16*Baudrate - 1;

    U2STA = (  UART_INT_TX                 /* Interrupt on transfer of every character to TSR */
             & UART_IrDA_POL_INV_ZERO      /* IrDA encoded, UxTX Idel state is '0' */
             & UART_SYNC_BREAK_DISABLED    /* Sync break transmission disabled or completed */
             & UART_TX_ENABLE              /* Transmit enable */
             & UART_INT_RX_CHAR            /* Interrupt on every char received */
             & UART_ADR_DETECT_DIS);       /* address detect disable */

    DisableIntU2RX;
    DisableIntU2TX;
    U2RX_Clear_Intr_Status_Bit;
    U2TX_Clear_Intr_Status_Bit;
    SetPriorityIntU2RX(u8RxPriority);
    SetPriorityIntU2TX(u8TxPriority);
    
    if(u8RxPriority != 0)
        EnableIntU2RX;
    else
        DisableIntU2RX;

    if(u8TxPriority != 0)
        EnableIntU2TX;
    else
        DisableIntU2TX;
}
#endif
/*=====================================================================================================================
 * Parameters: U8 byte to transmit
 *
 * Return: Transmitted bytes. If transmit buffer is full return 0.
 *
 * Description: Send a single byte via UART
 *===================================================================================================================*/
U8 Uart1_TxByte(U8 u8Byte)
{
    U8 u8TxBytes = 0;

    DisableIntU1RX;

    if(_UART_TxBufferIsNotFull(1) == cTrue)
    {
        _UART_WriteTxBuffer(1, u8Byte);
        ++u8TxBytes;
    }
    EnableIntU1RX;

    return u8TxBytes;
}

#if UART2_USED == 1
/*=====================================================================================================================
 * Parameters: U8 byte to transmit
 *
 * Return: Transmitted bytes. If transmit buffer is full return 0.
 *
 * Description: Send a single byte via UART
 *===================================================================================================================*/
U8 Uart2_TxByte(U8 u8Byte)
{
    U8 u8TxBytes = 0;

    DisableIntU2RX;

    if(_UART_TxBufferIsNotFull(2) == cTrue)
    {
        _UART_WriteTxBuffer(2, u8Byte);
        ++u8TxBytes;
    }

    EnableIntU2RX;

    return u8TxBytes;
}
#endif

/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
_DECLARE_ISR(_U1RXInterrupt)
{
    U8 u8DataCnt = 0;
    U8 u8Data;

    if( (cFalse == _UART_ParityError(1)) && (cFalse == _UART_FramingError(1)) )
    {
        // read useful data
        while(_UART_IsRxBuffContainData(1) && (u8DataCnt < cUartRxFifoLevel))
        {
            u8Data = _UART_GetRxBuffer(1);
            UartDrv[UART1].UartRxCallback(u8Data);
            ++u8DataCnt;
        }
    }
    else
    {
        // read whole buffer to clear framing and parity flags
        while(_UART_IsRxBuffContainData(1) && (u8DataCnt < cUartRxFifoLevel))
        {
            u8Data = _UART_GetRxBuffer(1);
            ++u8DataCnt;
        }
    }

    _UART_ClearOverrunError(1);  // clear overrun error flag

    U1RX_Clear_Intr_Status_Bit;
}

#if UART2_USED == 1
/*=====================================================================================================================
 * Parameters: void
 *
 * Return: void
 *
 * Description: 
 *===================================================================================================================*/
_DECLARE_ISR(_U2RXInterrupt)
{
    U8 u8DataCnt = 0;
    U8 u8Data;

    if( (cFalse == _UART_ParityError(2)) && (cFalse == _UART_FramingError(2)) )
    {
        // read useful data
        while(_UART_IsRxBuffContainData(2) && (u8DataCnt < cUartRxFifoLevel))
        {
            u8Data = _UART_GetRxBuffer(2);
            UartDrv[UART2].UartRxCallback(u8Data);
            ++u8DataCnt;
        }
    }
    else
    {
        // read whole buffer to clear framing and parity flags
        while(_UART_IsRxBuffContainData(2) && (u8DataCnt < cUartRxFifoLevel))
        {
            u8Data = _UART_GetRxBuffer(2);
            ++u8DataCnt;
        }
    }

    _UART_ClearOverrunError(2);  // clear overrun error flag

    U2RX_Clear_Intr_Status_Bit;

}
#endif

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

