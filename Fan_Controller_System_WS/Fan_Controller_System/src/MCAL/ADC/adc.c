/*******************************************************************************
 *
 *  [   Module  ]: ADC's Modules
 *
 *  [ File Name ]: adc.c
 *
 *  [Description]: Source File For AVR_ADC Module.
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "adc.h"
#include "adc_private.h"
#include "../../utils/common_macros.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/

volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                                 ADC_ISR
 *******************************************************************************/
ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC_REG;
}

/*******************************************************************************
 *                         Implementation FUNCTIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: ADC_Init
 * [DISCRIPTION]  : This function is responsible to initialization ADC.
 * [Args]  : void
 * [RUTURN]: Void
 */
void ADC_Init(void)
{
	/* Select to connect external reference voltage */
	/* Select Vref = AREF */
#if ADC_VOLTAGE_REFERENCE_SELECTOR == AREF_VOLT
	ADMUX_REG &= ADC_VOLTAGE_REFERENCE_CLR;
	ADMUX_REG |= AREF_VOLT;

	/* Select Vref = AVCC */
#elif ADC_VOLTAGE_REFERENCE_SELECTOR == AVCC_VOLT
	ADMUX_REG &= ADC_VOLTAGE_REFERENCE_CLR;
	ADMUX_REG |= AVCC_VOLT;

	/* Select Vref = INTERNAL */
#elif ADC_VOLTAGE_REFERENCE_SELECTOR == INTERNAL_VOLT
	ADMUX_REG &= ADC_VOLTAGE_REFERENCE_CLR;
	ADMUX_REG |= INTERNAL_VOLT;

#else
#error("You Chose Wrong Voltage Reference Selections for ADC!")

#endif

	/* select adjust result */
	/* select right adjust result */
#if ADC_ADJUST_RESULT_SELECTOR == RIGHT_ADJUST
	ADMUX_REG &= ADC_ADJUST_RESULT_CLR;
	ADMUX_REG |= RIGHT_ADJUST;

	/* select left adjust result */
#elif ADC_ADJUST_RESULT_SELECTOR == LEFT_ADJUST
	ADMUX_REG &= ADC_ADJUST_RESULT_CLR;
	ADMUX_REG |= LEFT_ADJUST;

#else
#error ("You Choose Wrong ADC Adjust Result!")
#endif


#if ADC_AUTO_TRIGGER_EN == ENABLE
	SET_BIT(ADCSRA_REG, ADCSRA_ADATE); /* Enable of trigger */

#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= FREE_RUNNING;

#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= ANALOG_COMPARATOR;

#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQUEST0
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= EXTERNAL_INTERRUPT_REQUEST0;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER0_COMPARE_MATCH
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER0_COMPARE_MATCH;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER0_OVERFLOW
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER0_OVERFLOW;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_COMPARE_MATCH_B
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER1_COMPARE_MATCH_B;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER1_OVERFLOW;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER1_OVERFLOW;

#elif ADC_AUTO_TRIGGER_SOURCE == TIMER1_CAPTURE_EVENT
	SFIOR_REG &= ADC_ADJUST_RESULT_CLR;
	SFIOR_REG |= TIMER1_CAPTURE_EVENT;

#else
#error("You Choose Wrong ADC Auto Trigger Source!")
#endif

#elif ADC_AUTO_TRIGGER_EN == DISABLE
	/* disable of trigger & Select single conversion */
	CLEAR_BIT(ADCSRA_REG, ADCSRA_ADATE);

#else
#error("You Choose Wrong ADC Auto Trigger!")
#endif

	/* ADC interrupt disable */
	CLEAR_BIT(ADCSRA_REG, ADCSRA_ADIE);

	/* ADC Prescaler */
	/* ADC must operate in range 50-200Khz */
	ADCSRA_REG &= ADC_PRESCALER_CLR;
	ADCSRA_REG |= ADC_PRESCALER_SELECTOR;

	/* Enable ADC */
	SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}

/*
 * [FUNCTION NAME]: ADC_readChannelSynch
 * [DISCRIPTION]  : This function is responsible to Start ADC Conversion Synchronous.
 * [Args]  : uint8 Number of Channel
 * [RUTURN]: uint16 the digital value
 */
uint16 ADC_readChannelSynch(uint8 channel_num)
{
	channel_num &= ADC_CHANNEL_CLR; /* Input channel number must be from 0 --> 7 */
	ADMUX_REG &= ADC_MUX_CHANNEL_CLR; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX_REG |= channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC); /* Start conversion write '1' to ADSC */
	while((GET_BIT(ADCSRA_REG, ADCSRA_ADIF)) == 0); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA_REG, ADCSRA_ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC_REG; /* Read the digital value from the data register */
}

/*
 * [FUNCTION NAME]: ADC_readChannelAsynch
 * [DISCRIPTION]  : This function is responsible to Start ADC Conversion Asynchronous.
 * [Args]  : uint8 Number of Channel
 * [RUTURN]: void
 */
void ADC_readChannelAsynch(uint8 channel_num)
{
	channel_num &= ADC_CHANNEL_CLR; /* Input channel number must be from 0 --> 7 */
	ADMUX_REG &= ADC_MUX_CHANNEL_CLR; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX_REG |= channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA_REG, ADCSRA_ADSC); /* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA_REG, ADCSRA_ADIE);
}

