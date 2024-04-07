/*******************************************************************************
 * [ File Name ]: temperature_sensor.c
 *
 * [Description]: Source file for implementing the temperature sensor Functionality.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../MCAL/ADC/adc.h"
#include "temperature_sensor.h"
#include <util/delay.h> /* For the delay functions */

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: TEMP_Init
 [DISCRIPTION]:	This function is responsible to Initialized the ADC
 	 	 	 	to read the temperature.
 [Args]: void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void TEMP_Init(void)
{
	ADC_Init();
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: TEMP_getValue
 [DISCRIPTION]:	This function is responsible for calculate the temperature from the ADC digital value.
 [Args]: void
 [RUTURN]: uint8  temperature value
 ---------------------------------------------------------------------------------------*/
uint8 TEMP_getValue(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannelSynch(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

//uint8 TEMP_getValue(void)
//{
//	uint8 temp_value = 0;
//
//	/* Read ADC channel where the temperature sensor is connected */
//	ADC_readChannelAsynch(SENSOR_CHANNEL_ID);
//
//	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
//	_delay_ms(5);
//
//	/* Calculate the temperature from the ADC value*/
//	temp_value = (uint8)(((uint32)g_adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
//
//	return temp_value;
//}
