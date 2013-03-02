/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __GPX_H
#define __GPX_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/
typedef struct tsGpsGpxData
{
    U8 GpxLatitudeDec[15];
    U8 GpxLongitudeDec[15];
    U8 GpxTime[20];       // ISO 8601 time format
}tGpsGpxData;
/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/
#define _Gpx_Init()         Gpx_Init()

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern HRESULT Gpx_WritePosition(tNMEA_GPS_Data *GpsData);
extern void Gpx_Init(void);

#endif /* __GPX_H */