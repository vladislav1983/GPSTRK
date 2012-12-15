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
 * Callback channels                                                              
 *===================================================================================================================*/
/*
** GPS MAIN 
*/
extern void NmeaMain_RxCharCallback(void);

/*
** APRS 
*/
//controls
#define cAprsCtrlStartTrmt                  0
#define cAprsCtrlStop                       1
// callback controls
#define cAprsCallbackCtrlOK                 0
#define cAprsCallbackCtrlError              1
// callback funct
extern void Aprs_TransmitCallback(tCtrl Ctrl);
/*
** Application state machine
*/
extern void AppStatemachine_GpsMsgReceivedCallback(void);

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/

#endif /* __API_H */
