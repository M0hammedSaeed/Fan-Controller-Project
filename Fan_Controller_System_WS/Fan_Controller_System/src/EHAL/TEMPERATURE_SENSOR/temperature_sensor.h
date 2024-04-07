/*
 * temperature_sensor.h
 *
 *  Created on: Mar 18, 2024
 *      Author: Compu Tech
 */

/*******************************************************************************
 * [ File Name ]: temperature_sensor.h
 *
 * [Description]:  Header file for Declaration and config the temperature sensor Functionality.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_
#define SRC_EHAL_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                         DEFINITIONS AND CONFIGURATION
 *------------------------------------------------------------------------------*/

#define SENSOR_CHANNEL_ID 			ADC_CHANNEL2
#define SENSOR_MAX_VOLT_VALUE     	1.5
#define SENSOR_MAX_TEMPERATURE    	150

/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: TEMP_Init
 [DISCRIPTION]:	This function is responsible to Initialized the ADC
 	 	 	 	to read the temperature.
 [Args]: void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void TEMP_Init(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: TEMP_getValue
 [DISCRIPTION]:	This function is responsible for calculate the temperature from the ADC digital value.
 [Args]: void
 [RUTURN]: uint8  temperature value
 ---------------------------------------------------------------------------------------*/
uint8 TEMP_getValue(void);

#endif /* SRC_EHAL_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_ */
