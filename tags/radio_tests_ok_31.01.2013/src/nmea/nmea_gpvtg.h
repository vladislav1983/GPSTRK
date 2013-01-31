/*=====================================================================================================================
 * 
 * Repository path:     $HeadURL$
 * Last committed:      $Revision$
 * Last changed by:     $Author$
 * Last changed date:   $Date$
 * ID:                  $Id$
 *
 *===================================================================================================================*/
#ifndef __NMEA_GPVTG_H
#define __NMEA_GPVTG_H

/*=====================================================================================================================
 * Included files to resolve specific definitions in this file                
 *===================================================================================================================*/
#include "basedef.h"
#include "gps_main.h"

/*=====================================================================================================================
 * Constant data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported type                                                             
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported data                                                              
 *===================================================================================================================*/

/*=====================================================================================================================
 * Constant exported data                                                     
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported Macros                                                            
 *===================================================================================================================*/

/*=====================================================================================================================
 * Exported functions                     				                        
 *===================================================================================================================*/
extern tGpsMask NMEAVtg_Decoder(U8 *pu8GpsField[], tNMEA_GPS_Data* GpsData, tGpsMask GpsStat);


#endif /* __NMEA_GPVTG_H */
