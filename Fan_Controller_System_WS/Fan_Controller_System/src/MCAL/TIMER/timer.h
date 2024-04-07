/*******************************************************************************
 *
 *  [   Module  ]: Timer's Modules
 *
 *  [ File Name ]: timer.h
 *
 *  [Description]: Header File for AVR_Timer Module
 *
 *  [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_TIMER_TIMER_H_
#define SRC_MCAL_TIMER_TIMER_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/

#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/* Enable The Timer's required */
/* NOTE : Timer0 and Timer1 share the same PreScaler Module */
#define TIMER0				ENABLE
#define TIMER1				DISABLE
#define TIMER2				DISABLE

/*
 * After Enabled required Timer's
 * Start Configure :
 * 				--> [Mode]
 * 				--> [OCn Behavior]
 * 				--> [PreScaler]
 *				--> [Interrupt]
 */

/*------------------------------------------------------------------------------
 *                             [TIMER0 Configurations]
 *------------------------------------------------------------------------------*/

/*
 * [Description]: To configure Timer0 mode just copy Mask of mode and paste in Mode selector.
 *
 * [Example]: #define TIMER0_MODE_SELECTOR   TIMER0_MODE_CTC_MSK
 *            like this you configure Timer0 to work with CTC mode.
 *
 * [SELECT TIMER0 Mode's]:
 * 			--> [TIMER0_MODE_OVF_MSK] --> (Normal Mode)
 * 			--> [TIMER0_MODE_PWM_PHASECORRECT_MSK]
 * 			--> [TIMER0_MODE_CTC_MSK]
 * 			--> [TIMER0_MODE_FASTPWM_MSK]
 */
#define TIMER0_MODE_SELECTOR                 TIMER0_MODE_PWM_PHASECORRECT_MSK

/*-----------------------                               -----------------------*
 *------------------                                         ------------------*
 *-------------                                                   -------------*
 *---------   [NOW Go To Configure OC0 Pin Behavior Depend on Mode]   ---------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*
 *-----------------------                               -----------------------*/

/*
 * [Description]: To configure OC0 pin behavior in Timer0 just copy Mask of pin behavior
 *                and paste in Behavior selector.
 *
 * [Example]:
 *           #define TIMER0_OC0_BEHAVIOR_SELECTOR       TIMER0_OC0_CLR_MSK
 *           like this you configure OC0 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER0 OC0 pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER0_OC0_clr_MSK]   	  -->  (Normal port operation, OC0 disconnected)
 * --> [TIMER0_OC0_TOGGLE_MSK]    -->  (Toggle OC0 on compare match)
 * --> [TIMER0_OC0_CLR_MSK]       -->  (Clear OC0 on compare match)
 * --> [TIMER0_OC0_SET_MSK]       -->  ( Set OC0 on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER0_OC0_NON_INVERTING_MSK]    --> (FAST_PWM          -> Clear OC0 on compare match, set OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Clear OC0 on compare match when count-up, set OC0 on compare match when count-down)
 * --> [TIMER0_OC0_INVERTING_MSK]        --> (FAST_PWM          -> Set OC0 on compare match, clear OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Set OC0 on compare match when count-up, Clear OC0 on compare match when count-down)
 */
#define TIMER0_OC0_BEHAVIOR_SELECTOR         TIMER0_OC0_NON_INVERTING_MSK

/*-----------------------                              -----------------------*
 *------------------                                        ------------------*
 *-------------                                                  -------------*
 *---------   [NOW Go To Select The PreScaler required for TIMER0]   ---------*
 *-------------                                                  -------------*
 *------------------                                        ------------------*
 *-----------------------                              -----------------------*/

/*
 * [Description]: To Configure PreScaler in Timer0 just copy Mask of
 *                required PreScaler and paste it at PreScaler Selector .
 *
 * [Example]:
 *           #define TIMER0_PRESCALER_SELECTOR       TIMER0_CLK_WITH_8_PRESCALER_MSK
 *           like this you configure TIMER0 To work with PreScaler 8 .
 *
 * [Select the required TIMER0 PreScaler From]:
 *
 * --> [TIMER0_CLK_WITH_NO_PRESCALER_MSK]
 * --> [TIMER0_CLK_WITH_8_PRESCALER_MSK]
 * --> [TIMER0_CLK_WITH_64_PRESCALER_MSK]
 * --> [TIMER0_CLK_WITH_256_PRESCALER_MSK]
 * --> [TIMER0_CLK_WITH_1024_PRESCALER_MSK]
 *
 * --> [TIMER0_EXTERNAL_CLK_WITH_FALLING_EDGE_MSK]
 * --> [TIMER0_EXTERNAL_CLK_WITH_RISING_EDGE_MSK]
 */
#define TIMER0_PRESCALER_SELECTOR             TIMER0_CLK_WITH_8_PRESCALER_MSK

/*-----------------------                              		   -----------------------*
 *------------------                                        		------------------*
 *-------------                                                          -------------*
 *---------   [NOW Go To Enable The Type Of Interrupt Required for TIMER0]   ---------*
 *-------------                                                 		 -------------*
 *------------------                                        		------------------*
 *-----------------------                              		   -----------------------*/

/*
 * [Description]: To Configure Interrupt in Timer0 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER0_OVF_INT_EN      ENABLE
 *
 * [TIMER0 Enterrupt's]:
 *
 * --> [TIMER0_OVF_INT_EN]
 * --> [TIMER0_COMP_INT_EN]
 */
#define TIMER0_OVF_INT_EN               DISABLE
#define TIMER0_COMP_INT_EN              DISABLE

/*-----------------------                               -----------------------*
 *------------------                                    	 ------------------*
 *-------------                                                   -------------*
 *---------   [NOW Go To Initialize TIMER0 Value And Compare Value]   ---------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*
 *-----------------------                               -----------------------*/

/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to Enable more than one timer at the same time .
 */
#define TIMER0_INITIAL_VALUE                        0
#define TIMER0_COMPARE_VALUE                        0


#define TIMER0_OC0_PORT			PORTB_ID
#define TIMER0_OC0_Pin			PIN3_ID


/*------------------------------------------------------------------------------
 *                             [TIMER1 Configurations]
 *------------------------------------------------------------------------------*/

/*
 * [Description]: To configure Timer1 mode just copy Mask of mode and paste in Mode selector .
 *
 * [Example]: #define TIMER1_MODE_SELECTOR   TIMER1_MODE_CTC_MSK
 *            like this you configure Timer1 to work with CTC mode .
 *
 * [SELECT TIMER1 Mode's]:
 *
 * --> [TIMER1_MODE_OVF_MSK]  -->  (Normal Mode)
 * --> [TIMER1_MODE_PWM_PHASECORRECT_8_BIT_MSK]
 * --> [TIMER1_MODE_PWM_PHASECORRECT_9_BIT_MSK]
 * --> [TIMER1_MODE_PWM_PHASECORRECT_10_BIT_MSK]
 * --> [TIMER1_MODE_CTC_MSK]
 * --> [TIMER1_MODE_FASTPWM_8_BIT_MSK]
 * --> [TIMER1_MODE_FASTPWM_9_BIT_MSK]
 * --> [TIMER1_MODE_FASTPWM_10_BIT_MSK]
 * --> [TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_MSK]
 * --> [TIMER1_MODE_PWM_PHASE_CORRECT_MSK]
 * --> [TIMER1_MODE_FAST_PWM_MSK]
 */
#define TIMER1_MODE_SELECTOR                TIMER1_MODE_FAST_PWM_MSK

/*-----------------------                              		  -----------------------*
 *------------------                                        	   ------------------*
 *-------------                                                         -------------*
 *---------   [NOW Go To Configure OC1A/OC1B Pin Behavior Depend on Mode]   ---------*
 *-------------                                                 	    -------------*
 *------------------                                        	   ------------------*
 *-----------------------                              		  -----------------------*/

/*
 * [Description]: To configure OC1A/OC1B pin behavior in Timer1 just copy Mask
 *                Of pin behavior and paste in Behavior selector .
 *
 * [Example]:
 *           #define TIMER1_OC1_BEHAVIOR_SELECTOR       TIMER1_OC1_CLR_MSK
 *           like this you configure OC1 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER1 OC1A/OC1B pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER1_OC1_TOGGLE_MSK]                     -->  (Toggle OC1A/OC1B on compare match)
 * --> [TIMER1_OC1_CLR_MSK]                        -->  (Clear OC1A/OC1B on compare match)
 * --> [TIMER1_OC1_SET_MSK]                        -->  (Set OC1A/OC1B on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER1_OC1_NON_INVERTING_MSK]              --> (Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM)
 * --> [TIMER1_OC1_INVERTING_MSK]                  --> (Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM)
 *
 *
 * [Special TIMER1 OC1A/OC1B pin behavior]:
 *
 * (Fast PWM):
 * --> [TIMER1_OC1_SPECIAL_TOGGLE_FASTPWM_MSK]          --> (WGM13:0 = 15: Toggle OC1A on Compare Match,OC1B disconnected (normal port operation).)
 *                                                      --> (Other Value For WGM13:0 The OCnA/OCnB will be disconnected)
 * (Phase Correct and Phase and Frequency Correct PWM):
 * --> [TIMER1_OC1_SPECIAL_TOGGLE_PHASE_CORRECT_MSK]    --> (WGM13:0 = 9 or 14: Toggle OCnA on Compare Match, OCnB disconnected (normal port operation).)                                                    --> (Other Value For WGM13:0 The OC1A/OC1B will be disconnected)
 */
#define TIMER1_OC1_BEHAVIOR_SELECTOR         TIMER1_OC1_NON_INVERTING_MSK

/*
 * Enable Required OC1 Pins
 *
 * [TIMER1 OCn Pin's]:
 *
 * --> [TIMER1_OC1A_SELECT]
 * --> [TIMER1_OC1B_SELECT]
 *
 * [NOTE]: You Can Enable Two Output Compare Pins OC1A And OC1B
 */
#define TIMER1_OC1A_SELECT                   ENABLE
#define TIMER1_OC1B_SELECT                   ENABLE

/*-----------------------                          	   -----------------------*
 *------------------                                        ------------------*
 *-------------                                                  -------------*
 *---------   [NOW Go To Select The PreScaler required for TIMER1]   ---------*
 *-------------                                             	 -------------*
 *------------------                                        ------------------*
 *-----------------------                              -----------------------*/

/*
 * [Description]: To Configure PreScaler in Timer1 just copy Mask of
 *                required PreScaler and paste it at PreScaler Selector .
 *
 * [Example]:
 *           #define TIMER1_PRESCALER_SELECTOR       TIMER1_CLK_WITH_8_PRESCALER_MSK
 *           like this you configure TIMER1 To work with PreScaler 8 .
 *
 * [Select the required TIMER1 PreScaler From]:
 *
 * --> [TIMER1_CLK_WITH_NO_PRESCALER_MSK]
 * --> [TIMER1_CLK_WITH_8_PRESCALER_MSK]
 * --> [TIMER1_CLK_WITH_64_PRESCALER_MSK]
 * --> [TIMER1_CLK_WITH_256_PRESCALER_MSK]
 * --> [TIMER1_CLK_WITH_1024_PRESCALER_MSK]
 *
 * --> [TIMER1_EXTERNAL_CLK_WITH_FALLING_EDGE_MSK]
 * --> [TIMER1_EXTERNAL_CLK_WITH_RISING_EDGE_MSK]
 */
#define TIMER1_PRESCALER_SELECTOR            TIMER1_CLK_WITH_8_PRESCALER_MSK

/*-----------------------                          	   		   -----------------------*
 *------------------                                        		------------------*
 *-------------                                                 		 -------------*
 *---------   [NOW Go To Enable The Type Of Interrupt Required for TIMER1]   ---------*
 *-------------                                             	 		 -------------*
 *------------------                                        		------------------*
 *-----------------------                              		   -----------------------*/

/*
 * [Description]: To Configure Interrupt in Timer1 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER1_OVF_INT_EN      ENABLE
 *
 * [TIMER1 Enterrupt's]:
 *
 * --> [TIMER1_OVF_INT_EN]
 * --> [TIMER1_COMPA_INT_EN]
 * --> [TIMER1_COMPB_INT_EN]
 */
#define TIMER1_OVF_INT_EN               DISABLE
#define TIMER1_COMPA_INT_EN             DISABLE
#define TIMER1_COMPB_INT_EN             DISABLE

/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to initialize more than one timer
 */
#define TIMER1_INITIAL_VALUE                         0
#define TIMER1_COMPARE_A_VALUE                       2499
#define TIMER1_COMPARE_B_VALUE                       0


#define TIMER1_OC1A_PORT			PORTD_ID
#define TIMER1_OC1A_Pin				PIN5_ID

#define TIMER1_OC1B_PORT			PORTD_ID
#define TIMER1_OC1B_Pin				PIN4_ID


/*------------------------------------------------------------------------------
 *                             [TIMER2 Configurations]
 *------------------------------------------------------------------------------*/

/*
 * [Description]: To configure Timer2 mode just copy Mask of mode and paste in Mode selector .
 *
 * [Example]: #define TIMER2_MODE_SELECTOR   TIMER2_MODE_CTC_MSK
 *            like this you configure Timer2 to work with CTC mode .
 *
 * [SELECT TIMER2 Mode's]:
 *
 * --> [TIMER2_MODE_OVF_MSK] -->  (Normal Mode)
 * --> [TIMER2_MODE_PWM_PHASECORRECT_MSK]
 * --> [TIMER2_MODE_CTC_MSK]
 * --> [TIMER2_MODE_FASTPWM_MSK]
 */
#define TIMER2_MODE_SELECTOR                 TIMER2_MODE_OVF_MSK

/*-----------------------                          	    -----------------------*
 *------------------                                         ------------------*
 *-------------                                                   -------------*
 *---------   [NOW Go To Configure OC2 Pin Behavior Depend on Mode]   ---------*
 *-------------                                         	 	  -------------*
 *------------------                                         ------------------*
 *-----------------------                               -----------------------*/

/*
 * [Description]: To configure OC2 pin behavior in Timer2 just copy Mask of pin behavior
 *                and paste in Behavior selector .
 *
 * [Example]:
 *           #define TIMER2_OC2_BEHAVIOR_SELECTOR       TIMER2_OC2_CLR_MSK
 *           like this you configure OC2 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER2 OC2 pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER2_OC2_TOGGLE_MSK]    -->  (Toggle OC2 on compare match)
 * --> [TIMER2_OC2_CLR_MSK]       -->  (Clear OC2 on compare match)
 * --> [TIMER2_OC2_SET_MSK]       -->  ( Set OC2 on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER2_OC2_NON_INVERTING_MSK]    --> (     FAST_PWM     -> Clear OC0 on compare match, set OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Clear OC0 on compare match when count-up, set OC0 on compare match when count-down)
 * --> [TIMER2_OC2_INVERTING_MSK]        --> (     FAST_PWM     -> Set OC0 on compare match, clear OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Set OC0 on compare match when count-up, Clear OC0 on compare match when count-down)
 */
#define TIMER2_OC2_BEHAVIOR_SELECTOR         TIMER2_OC2_NON_INVERTING_MSK

/*-----------------------                          	    -----------------------*
 *------------------                                         ------------------*
 *-------------                                                   -------------*
 *---------   [NOW Go To Select The PreScaler required for TIMER2]   ---------*
 *-------------                                         	 	  -------------*
 *------------------                                         ------------------*
 *-----------------------                               -----------------------*/

/*
 * [Description]: To Configure PreScaler in Timer2 just copy Mask of
 *                required PreScaler and paste it at PreScaler Selector.
 *
 * [Example]:
 *           #define TIMER2_PRESCALER_SELECTOR       TIMER2_CLK_WITH_8_PRESCALER_MSK
 *           like this you configure TIMER2 To work with PreScaler 8 .
 *
 * [Select the required TIMER2 PreScaler From]:
 *
 * --> [TIMER2_CLK_WITH_NO_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_8_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_32_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_64_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_128_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_256_PRESCALER_MSK]
 * --> [TIMER2_CLK_WITH_1024_PRESCALER_MSK]
 */
#define TIMER2_PRESCALER_SELECTOR               TIMER2_CLK_WITH_1024_PRESCALER_MSK

/*-----------------------                          	    	   -----------------------*
 *------------------                                         		------------------*
 *-------------                                                  		 -------------*
 *---------   [NOW Go To Enable The Type Of Interrupt Required for TIMER2]   ---------*
 *-------------                                         	 	 		 -------------*
 *------------------                                         		------------------*
 *-----------------------                               	   -----------------------*/

/*
 * [Description]: Easy to Configure Interrupt in Timer2 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER2_OVF_INT_EN      ENABLE
 *
 * [TIMER2 Enterrupt's]:
 *
 * --> [TIMER2_OVF_INT_EN]
 * --> [TIMER2_COMP_INT_EN]
 */
#define TIMER2_OVF_INT_EN               ENABLE
#define TIMER2_COMP_INT_EN              DISABLE

/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to Enable more than one timer at the same time .
 */
#define TIMER2_INITIAL_VALUE              0
#define TIMER2_COMPARE_VALUE              0


#define TIMER2_OC2_PORT			PORTD_ID
#define TIMER2_OC2_Pin			PIN7_ID


/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: TIMER_Init
 * [DISCRIPTION]  : This function is responsible to initialization one or more than one timer at
 *                  The same time from Configuration of timer .
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_Init(void);

/*
 * [FUNCTION NAME]: TIMER_DeInit
 * [DISCRIPTION]  : This function is responsible to De-initialization all Timers
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_DeInit(void);

/*
 * [FUNCTION NAME]: TIMER_SetCallBack
 * [DISCRIPTION]  : This function's is responsible to set the Call Back function address.
 *                  Every set callback function follow specific Timer.
 * [Args]  : Pointer To Function take void and return void
 * [RUTURN]: Void
 */
void TIMER0_SetCallBack(void (*Ptr_To_fun)(void));
void TIMER1_SetCallBack(void (*Ptr_To_fun)(void));
void TIMER2_SetCallBack(void (*Ptr_To_fun)(void));

/*
 * [FUNCTION NAME]: TIMER_EnableInterrupt
 * [DISCRIPTION]  : This function is responsible to Enable The required Type of Interrupt
 *                  Depend on Timer That you made it Enable.
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_EnableInterrupt(void);

/*
 * [FUNCTION NAME]: Timer0_PWM_DutyCycle
 * [DISCRIPTION]  :  Initialize the PWM module by:
 * 					 1. Trigger Timer0 with TIMER0_MODE_FASTPWM_MSK.
 *					 2. Setup the PWM behavior.
 *					 3. Setup the prescaler.
 *					 4. Setup the compare value based on the required input duty cycle.
 *					 5. Setup the direction for OC0 as output pin.
 * [Args]  : required input duty cycle
 * [RUTURN]: Void
 */
void Timer0_PWM_DutyCycle(uint8 duty_cycle);

/*
 * [FUNCTION NAME]: Timer1_PWM_DutyCycle
 * [DISCRIPTION]  :  Initialize the PWM module by:
 * 					 1. Trigger Timer1 with TIMER1_MODE_FAST_PWM_MSK.
 *					 2. Setup the PWM behavior.
 *					 3. Setup the prescaler.
 *					 4. Setup the compare value based on the required input duty cycle.
 *					 5. Setup the direction for OC1B as output pin.
 * [Args]  : required input duty cycle
 * [RUTURN]: Void
 */
void Timer1_PWM_DutyCycle(uint16  duty_cycle);

/*
 * [FUNCTION NAME]: Timer2_PWM_DutyCycle
 * [DISCRIPTION]  :  Initialize the PWM module by:
 * 					 1. Trigger Timer0 with TIMER2_MODE_FASTPWM_MSK.
 *					 2. Setup the PWM behavior.
 *					 3. Setup the prescaler.
 *					 4. Setup the compare value based on the required input duty cycle.
 *					 5. Setup the direction for OCR2 as output pin.
 * [Args]  : required input duty cycle
 * [RUTURN]: Void
 */
void Timer2_PWM_DutyCycle(uint8 duty_cycle);

#endif /* SRC_MCAL_TIMER_TIMER_H_ */
