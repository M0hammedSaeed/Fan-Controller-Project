/*******************************************************************************
 * [   Module  ]: ADC's Modules
 *
 * [ File Name ]: adc_private.h
 *
 * [Description]: Header File for ATmega32 ADC Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ADC_ADC_PRIVATE_H_
#define SRC_MCAL_ADC_ADC_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Definition for ADMUX (ADC Multiplexer) */
#define ADMUX_REG				(*(volatile uint8 *)0x27)

/* Definition for ADCSRA (ADC Control and Status Register A) */
#define ADCSRA_REG				(*(volatile uint8 *)0x26)

/* Definition for ADCH (ADC Data Register) */
#define ADCH_REG				(*(volatile uint8 *)0x25)

/* Definition for ADCL (ADC Data Register) */
#define ADCL_REG				(*(volatile uint8 *)0x24)

/* Definition for ADC (ADC Data Register) */
#define ADC_REG					(*(volatile uint16 *)0x24)

/* Definition for SFIOR (Special Function IO Register) */
#define SFIOR_REG			  	(*(volatile uint8 *)0x50)

/* Bit numbers */

/* ADMUX */
#define ADMUX_REFS1    7
#define ADMUX_REFS0    6
#define ADMUX_ADLAR    5
#define ADMUX_MUX4     4
#define ADMUX_MUX3     3
#define ADMUX_MUX2     2
#define ADMUX_MUX1     1
#define ADMUX_MUX0     0

/* ADCSRA */
#define ADCSRA_ADEN    7
#define ADCSRA_ADSC    6
#define ADCSRA_ADATE   5
#define ADCSRA_ADIF    4
#define ADCSRA_ADIE    3
#define ADCSRA_ADPS2   2
#define ADCSRA_ADPS1   1
#define ADCSRA_ADPS0   0

/* SFIOR */
#define SFIOR_ADTS2    7
#define SFIOR_ADTS1    6
#define SFIOR_ADTS0    5

/* Interrupt vectors */

/* ADC Conversion Complete */
#define ADC_vect			_VECTOR(16)
/* ADC ISR attribute */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)


/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

/*
 * - Input channel number must be from 0 --> 7
 * - Clear first 5 bits in the ADMUX (channel number MUX4:0 bits)
 * before set the required channel
 */
#define ADC_CHANNEL_CLR				0x07
#define ADC_MUX_CHANNEL_CLR			0xE0

/*
 * Voltage Reference Selections for ADC mask.
 */
#define ADC_VOLTAGE_REFERENCE_CLR		0x3F
#define AREF_VOLT						0x00
#define AVCC_VOLT						0x40
#define INTERNAL_VOLT					0xC0

/*
 * ADC Adjust Result mask.
 */
#define ADC_ADJUST_RESULT_CLR			0xDF
#define LEFT_ADJUST      				0x20
#define RIGHT_ADJUST     				0x00

/*
 * ADC Prescaler Selections mask.
 */
#define ADC_PRESCALER_CLR				0xF8
#define DIV_FACTOR_2        			0x01
#define DIV_FACTOR_4   	    			0x02
#define DIV_FACTOR_8        			0x03
#define DIV_FACTOR_16       			0x04
#define DIV_FACTOR_32       			0x05
#define DIV_FACTOR_64       			0x06
#define DIV_FACTOR_128      			0x07

/*
 *  ADC Auto Trigger Source Selections mask.
 */
#define ADC_AUTO_TRIGGER_CLR			0x1F
#define FREE_RUNNING 					0x00
#define ANALOG_COMPARATOR				0x20
#define EXTERNAL_INTERRUPT_REQUEST0		0x40
#define TIMER0_COMPARE_MATCH			0x60
#define TIMER0_OVERFLOW					0x80
#define TIMER1_COMPARE_MATCH_B			0xA0
#define TIMER1_OVERFLOW					0xC0
#define TIMER1_CAPTURE_EVENT			0xE0

#endif /* SRC_MCAL_ADC_ADC_PRIVATE_H_ */
