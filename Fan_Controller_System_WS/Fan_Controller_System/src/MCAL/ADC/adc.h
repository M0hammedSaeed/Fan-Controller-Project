/*******************************************************************************
 *
 *  [   Module  ]: ADC's Modules
 *
 *  [ File Name ]: adc.h
 *
 *  [Description]: Header File for ADC Module
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*
 *  ADC Channel mask.
 */
#define ADC_CHANNEL0		0x00
#define ADC_CHANNEL1		0x01
#define ADC_CHANNEL2		0x02
#define ADC_CHANNEL3		0x03
#define ADC_CHANNEL4		0x04
#define ADC_CHANNEL5		0x05
#define ADC_CHANNEL6		0x06
#define ADC_CHANNEL7		0x07

/*
 * [Description]: To configure Voltage Reference in ADC just copy Mask of required Reference
 *                and paste in Reference selector.
 *
 * [Example]:
 *           #define ADC_VOLTAGE_REFERENCE_SELECTOR 		AREF_VOLT
 *           like this you configure Voltage Reference to work depend on Aref.
 *
 * [Select the required ADC Voltage Reference From]:
 *
 * --> [AREF_VOLT]   	  -->  (AREF, Internal Vref turned off)
 * --> [AVCC_VOLT]    	  -->  (AVCC with external capacitor at AREF pin)
 * --> [INTERNAL_VOLT]    -->  (Internal 2.56V Voltage Reference with external capacitor at AREF pin)
 */
#define ADC_VOLTAGE_REFERENCE_SELECTOR 			INTERNAL_VOLT

/*
 * [Description]: To configure Adjust Result in ADC just copy Mask of required Adjust Result
 *                and paste in Adjust Result selector.
 *
 * [Example]:
 *           #define ADC_ADJUST_RESULT_SELECTOR				RIGHT_ADJUST
 *           like this you configure Adjust Result to presentation of the
 *           ADC conversion result in the ADC Data Register in Left Register
 *           and 2 bit in Right Register.
 *
 * [Select the required ADC Adjust Result From]:
 *
 * --> [LEFT_ADJUST]
 * --> [RIGHT_ADJUST]
 */
#define ADC_ADJUST_RESULT_SELECTOR				RIGHT_ADJUST

/*
 * [Description]: To Configure PreScaler in ADC just copy Mask of
 *                required PreScaler and paste it at PreScaler Selector .
 *
 * [Example]:
 *           #define ADC_PRESCALER_SELECTOR					DIV_FACTOR_128
 *           like this you configure ADC To work with PreScaler 128 .
 *
 * [Note]: ADC must operate in range 50-200Khz.
 *
 * [Select the required ADC PreScaler From]:
 *
 * --> [DIV_FACTOR_2]
 * --> [DIV_FACTOR_4]
 * --> [DIV_FACTOR_8]
 * --> [DIV_FACTOR_16]
 * --> [DIV_FACTOR_32]
 * --> [DIV_FACTOR_64]
 * --> [DIV_FACTOR_128]
 */
#define ADC_PRESCALER_SELECTOR					DIV_FACTOR_8

/* Enable Or Disable The Auto Trigger */
#define ADC_AUTO_TRIGGER_EN						DISABLE

/*
 * [Description]: To Configure Auto Trigger in ADC just copy Mask of
 *                required Auto Trigger and paste it at Auto Trigger Source	 .
 *
 * [Example]:
 *           #define ADC_AUTO_TRIGGER_SOURCE					EXTERNAL_INTERRUPT_REQUEST0
 *           like this you configure Auto Trigger in ADC To work with External Interrupt Request 0.
 *
 * [Select the required ADC Auto Trigger From]:
 *
 * --> [FREE_RUNNING]
 * --> [ANALOG_COMPARATOR]
 * --> [EXTERNAL_INTERRUPT_REQUEST0]
 * --> [TIMER0_COMPARE_MATCH]
 * --> [TIMER0_OVERFLOW]
 * --> [TIMER1_COMPARE_MATCH_B]
 * --> [TIMER1_OVERFLOW]
 * --> [TIMER1_CAPTURE_EVENT]
 */
#define ADC_AUTO_TRIGGER_SOURCE					EXTERNAL_INTERRUPT_REQUEST0

/* Enable Or Disable The ADC Interrupt */
#define ADC_INTERRUPT_EN						DISABLE

/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: ADC_Init
 * [DISCRIPTION]  : This function is responsible to initialization ADC.
 * [Args]  : void
 * [RUTURN]: Void
 */
void ADC_Init(void);

/*
 * [FUNCTION NAME]: ADC_readChannelSynch
 * [DISCRIPTION]  : This function is responsible to Start ADC Conversion Synchronous.
 * [Args]  : uint8 Number of Channel
 * [RUTURN]: uint16 the digital value
 */
uint16 ADC_readChannelSynch(uint8 channel_num);

/*
 * [FUNCTION NAME]: ADC_readChannelAsynch
 * [DISCRIPTION]  : This function is responsible to Start ADC Conversion Asynchronous.
 * [Args]  : uint8 Number of Channel
 * [RUTURN]: void
 */
void ADC_readChannelAsynch(uint8 channel_num);

#endif /* SRC_MCAL_ADC_ADC_H_ */
