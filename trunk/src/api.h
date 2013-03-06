/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __API_H
#define __API_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Generic constant data                                                              
 *===================================================================================================================*/
// Generic callback controls
#define cCallbackCtrlOK                     0
#define cCallbackCtrlNOK                    1
#define cCallbackCtrlError                  2

// Generic controls
#define cCtrl_Start                         3
#define cCtrl_Stop                          4

/*=====================================================================================================================
 * Callback channels                                                              
 *===================================================================================================================*/


/************************************************************************************************************************
** GPS MAIN 
************************************************************************************************************************/
extern void NmeaMain_RxCharCallback(void);

/************************************************************************************************************************
** APRS 
************************************************************************************************************************/
// AX25 controls
#define cAX25CtrlStartTrmt                  0
#define cAX25CtrlStop                       1
// APRS controls
#define cAprs_NotTransmit                   0
#define cAPRS_TransmitTrackerInfo           1
#define cAPRS_TransmitData                  2

// callback controls
#define cAprsCallbackCtrlOK                 0
#define cAprsCallbackCtrlError              1
// callback functions
extern void Aprs_TransmitCallback(tCtrl Ctrl);
extern void Aprs_AnotherStationTxCallback(void);

/***********************************************************************************************************************
** Application state machine
************************************************************************************************************************/
extern void AppStatemachine_GpsMsgReceivedCallback(tMsg Msg);
extern void  App_Statemachine_AprsMsgTxCallback(tCtrl Control);
extern void App_Statemachine_SD_CardCallback(tCtrl Control);

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/

#endif /* __API_H */
