/*******************************************************************************
 * [   Module  ]: Timer's Register Modules
 *
 * [ File Name ]: timer_private.h
 *
 * [Description]: Header File for ATmega32 Timer's Register.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_TIMER_TIMER_PRIVATE_H_
#define SRC_MCAL_TIMER_TIMER_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Timer 0 */

/* Definition for TCCR0 (Timer/Counter Control Register) */
#define TCCR0_REG   	(*(volatile uint8 *)0x53)
/* Definition for TCNT0 (Timer/Counter Register) */
#define TCNT0_REG   	(*(volatile uint8 *)0x52)
/* Definition for OCR0 (Output Compare Register) */
#define OCR0_REG    	(*(volatile uint8 *)0x5C)
/* Definition for TIMSK (Timer/Counter Interrupt Mask Register) */
#define TIMSK_REG   	(*(volatile uint8 *)0x59)
/* Definition for TIFR (Timer/Counter Interrupt Flag Register) */
#define TIFR_REG    	(*(volatile uint8 *)0x58)

/* Bit numbers */

/* TCCR0 */
#define TCCR0_FOC0    7
#define TCCR0_WGM00   6
#define TCCR0_COM01   5
#define TCCR0_COM00   4
#define TCCR0_WGM01   3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0
/* TIMSK */
#define TIMSK_OCIE0   1
#define TIMSK_TOIE0   0
/* TIFR */
#define TIFR_OCF0     1
#define TIFR_TOV0     0


/* Timer 1 */

/* Definition for TCCR1A (Timer/Counter1 Control Register A) */
#define TCCR1A_REG   	(*(volatile uint8 *)0x4F)
/* Definition for TCCR1B (Timer/Counter1 Control Register B) */
#define TCCR1B_REG   	(*(volatile uint8 *)0x4E)
/* Definition for TCNT1 (Timer/Counter1) */
#define TCNT1_REG    	(*(volatile uint16 *)0x4C)
/* Definition for TCNT1L (Timer/Counter1 Low) */
#define TCNT1L_REG   	(*(volatile uint8 *)0x4C)
/* Definition for TCNT1H (Timer/Counter1 High) */
#define TCNT1H_REG   	(*(volatile uint8 *)0x4D)
/* Definition for OCR1A (Output Compare Register 1 A) */
#define OCR1A_REG   	(*(volatile uint16 *)0x4A)
/* Definition for OCR1AL (Output Compare Register 1 A Low) */
#define OCR1AL_REG   	(*(volatile uint8 *)0x4A)
/* Definition for OCR1AH (Output Compare Register 1 A High) */
#define OCR1AH_REG   	(*(volatile uint8 *)0x4B)
/* Definition for OCR1B (Output Compare Register 1 B) */
#define OCR1B_REG   	(*(volatile uint16 *)0x48)
/* Definition for OCR1BL (Output Compare Register 1 B Low) */
#define OCR1BL_REG   	(*(volatile uint8 *)0x48)
/* Definition for OCR1BH (Output Compare Register 1 B High) */
#define OCR1BH_REG   	(*(volatile uint8 *)0x49)
/* Definition for ICR1 (Input Capture Register) */
#define ICR1_REG   		(*(volatile uint16 *)0x46)
/* Definition for ICR1L (Input Capture Register Low) */
#define ICR1L_REG   	(*(volatile uint8 *)0x46)
/* Definition for ICR1H (Input Capture Register High) */
#define ICR1H_REG   	(*(volatile uint8 *)0x47)

/* Bit numbers */

/* TCCR1A */
#define TCCR1A_COM1A1  	7
#define TCCR1A_COM1A0  	6
#define TCCR1A_COM1B1  	5
#define TCCR1A_COM1B0  	4
#define TCCR1A_FOC1A   	3
#define TCCR1A_FOC1B   	2
#define TCCR1A_WGM11   	1
#define TCCR1A_WGM10   	0
/* TCCR1B */
#define TCCR1B_WGM13   	4
#define TCCR1B_WGM12   	3
#define TCCR1B_CS12    	2
#define TCCR1B_CS11    	1
#define TCCR1B_CS10    	0
/* TIMSK */
#define TIMSK_OCIE1A  	4
#define TIMSK_OCIE1B  	3
#define TIMSK_TOIE1   	2
/* TIFR */
#define TIFR_OCF1A   	4
#define TIFR_OCF1B   	3
#define TIFR_TOV1    	2


/* Timer 2 */

/* Definition for TCCR2 (Timer/Counter Control Register) */
#define TCCR2_REG   	(*(volatile uint8 *)0x45)
/* Definition for TCNT2 (Timer/Counter Register) */
#define TCNT2_REG   	(*(volatile uint8 *)0x44)
/* Definition for OCR2 (Output Compare Register) */
#define OCR2_REG   		(*(volatile uint8 *)0x43)

/* Bit numbers */

/* TCCR2 */
#define TCCR2_FOC2    	7
#define TCCR2_WGM20   	6
#define TCCR2_COM21   	5
#define TCCR2_COM20   	4
#define TCCR2_WGM21   	3
#define TCCR2_CS22    	2
#define TCCR2_CS21    	1
#define TCCR2_CS20    	0
/* TIMSK */
#define TIMSK_OCIE2   7
#define TIMSK_TOIE2   6
/* TIFR */
#define TIFR_OCF2    7
#define TIFR_TOV2    6


/* Interrupt vectors */

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			_VECTOR(11)
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		_VECTOR(10)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			_VECTOR(9)
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		_VECTOR(8)
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		_VECTOR(7)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		_VECTOR(4)
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			_VECTOR(5)


/* Interrupt Handler (ISR) */
#define _VECTOR(N) 			__vector_ ## N
#define ISR(vector) \
	void vector (void) __attribute__ ((signal)); \
	void vector (void)

/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                            [Masks For Timer's Mode]
 * -----------------------------------------------------------------------------*/

/*
 * Timer's Mode Select
 */

/* TIMER0 Mode's */
/* FOC0 bit is active in ovf/ctc mode */
#define TIMER0_MODE_clr_MSK                           0xB7
#define TIMER0_MODE_OVF_MSK                           0x80  /* Normal Mode */
#define TIMER0_MODE_PWM_PHASECORRECT_MSK              0x40
#define TIMER0_MODE_CTC_MSK                           0x88
#define TIMER0_MODE_FASTPWM_MSK                       0x48

/* TIMER1 Mode's */
/* FOC1A & FOC1B bit is active in ovf/ctc mode */
#define TIMER1_MODE_clr_A_MSK                         0xFC
#define TIMER1_MODE_clr_B_MSK                         0xE7

#define TIMER1_MODE_OVF_MSK                           0x00  /* Normal Mode */
#define TIMER1_MODE_OVF_A_MSK                         0xC0
#define TIMER1_MODE_OVF_B_MSK                         0x00

#define TIMER1_MODE_PWM_PHASECORRECT_8_BIT_MSK        0x01
#define TIMER1_MODE_PWM_PHASECORRECT_8_BIT_A_MSK      0x01
#define TIMER1_MODE_PWM_PHASECORRECT_8_BIT_B_MSK      0x00

#define TIMER1_MODE_PWM_PHASECORRECT_9_BIT_MSK        0x02
#define TIMER1_MODE_PWM_PHASECORRECT_9_BIT_A_MSK      0x02
#define TIMER1_MODE_PWM_PHASECORRECT_9_BIT_B_MSK      0x00

#define TIMER1_MODE_PWM_PHASECORRECT_10_BIT_MSK       0x03
#define TIMER1_MODE_PWM_PHASECORRECT_10_BIT_A_MSK     0x03
#define TIMER1_MODE_PWM_PHASECORRECT_10_BIT_B_MSK     0x00

#define TIMER1_MODE_CTC_MSK                           0x04
#define TIMER1_MODE_CTC_A_MSK                         0x0C
#define TIMER1_MODE_CTC_B_MSK                         0x08

#define TIMER1_MODE_FASTPWM_8_BIT_MSK                 0x05
#define TIMER1_MODE_FASTPWM_8_BIT_A_MSK               0x01
#define TIMER1_MODE_FASTPWM_8_BIT_B_MSK               0x08

#define TIMER1_MODE_FASTPWM_9_BIT_MSK                 0x06
#define TIMER1_MODE_FASTPWM_9_BIT_A_MSK               0x02
#define TIMER1_MODE_FASTPWM_9_BIT_B_MSK               0x08

#define TIMER1_MODE_FASTPWM_10_BIT_MSK                0x07
#define TIMER1_MODE_FASTPWM_10_BIT_A_MSK              0x03
#define TIMER1_MODE_FASTPWM_10_BIT_B_MSK              0x08

#define TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_MSK   0x09
#define TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_A_MSK 0x01
#define TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_B_MSK 0x10

#define TIMER1_MODE_PWM_PHASE_CORRECT_MSK             0x0B
#define TIMER1_MODE_PWM_PHASE_CORRECT_A_MSK           0x03
#define TIMER1_MODE_PWM_PHASE_CORRECT_B_MSK           0x10

#define TIMER1_MODE_FAST_PWM_MSK                      0x0F
#define TIMER1_MODE_FAST_PWM_A_MSK                    0x03
#define TIMER1_MODE_FAST_PWM_B_MSK                    0x18

/* TIMER2 Mode's */
/* FOC2 bit is active in ovf/ctc mode */
#define TIMER2_MODE_clr_MSK                           0xB7
#define TIMER2_MODE_OVF_MSK                           0x80  /* Normal Mode */
#define TIMER2_MODE_PWM_PHASECORRECT_MSK              0x40
#define TIMER2_MODE_CTC_MSK                           0x88
#define TIMER2_MODE_FASTPWM_MSK                       0x48


/*
 * Timer's Clock Select
 */

/* TIMER0 Clock and PreScaler */
#define TIMER0_CLK_WITH_PRESCALER_clr_MSK              0xF8
#define TIMER0_CLK_WITH_NO_PRESCALER_MSK               0x01
#define TIMER0_CLK_WITH_8_PRESCALER_MSK                0x02
#define TIMER0_CLK_WITH_64_PRESCALER_MSK               0x03
#define TIMER0_CLK_WITH_256_PRESCALER_MSK              0x04
#define TIMER0_CLK_WITH_1024_PRESCALER_MSK             0x05

#define TIMER0_EXTERNAL_CLK_WITH_FALLING_EDGE_MSK      0x06
#define TIMER0_EXTERNAL_CLK_WITH_RISING_EDGE_MSK       0x07

/* TIMER1 Clock and PreScaler */
#define TIMER1_CLK_WITH_PRESCALER_clr_MSK              0xF8
#define TIMER1_CLK_WITH_NO_PRESCALER_MSK               0x01
#define TIMER1_CLK_WITH_8_PRESCALER_MSK                0x02
#define TIMER1_CLK_WITH_64_PRESCALER_MSK               0x03
#define TIMER1_CLK_WITH_256_PRESCALER_MSK              0x04
#define TIMER1_CLK_WITH_1024_PRESCALER_MSK             0x05

#define TIMER1_EXTERNAL_CLK_WITH_FALLING_EDGE_MSK      0x06
#define TIMER1_EXTERNAL_CLK_WITH_RISING_EDGE_MSK       0x07

/* TIMER2 Clock and PreScaler */
#define TIMER2_CLK_WITH_PRESCALER_clr_MSK              0xF8
#define TIMER2_CLK_WITH_NO_PRESCALER_MSK               0x01
#define TIMER2_CLK_WITH_8_PRESCALER_MSK                0x02
#define TIMER2_CLK_WITH_32_PRESCALER_MSK               0x03
#define TIMER2_CLK_WITH_64_PRESCALER_MSK               0x04
#define TIMER2_CLK_WITH_128_PRESCALER_MSK              0x05
#define TIMER2_CLK_WITH_256_PRESCALER_MSK              0x06
#define TIMER2_CLK_WITH_1024_PRESCALER_MSK             0x07


/*
 * Timer's Behavior Selector
 */

/* TIMER0 Behavior */
#define TIMER0_OC0_clr_MSK                           0xCF
#define TIMER0_OC0_TOGGLE_MSK                        0x10
#define TIMER0_OC0_CLR_MSK                           0x20
#define TIMER0_OC0_SET_MSK                           0x30
#define TIMER0_OC0_NON_INVERTING_MSK                 0x20
#define TIMER0_OC0_INVERTING_MSK                     0x30

/* TIMER1 Behavior */
#define TIMER1_OC1_TOGGLE_MSK                        0x01
#define TIMER1_OC1_CLR_MSK                           0x02
#define TIMER1_OC1_SET_MSK                           0x03
#define TIMER1_OC1_NON_INVERTING_MSK                 0x04
#define TIMER1_OC1_INVERTING_MSK                     0x05

#define TIMER1_OC1_SPECIAL_TOGGLE_FASTPWM_MSK        0x06
#define TIMER1_OC1_SPECIAL_TOGGLE_PHASE_CORRECT_MSK  0x07

#if TIMER1_OC1A_SELECT == ENABLE
#define TIMER1_OC1A_clr_MSK                           0x3F
#define TIMER1_OC1A_TOGGLE_MSK                        0x40
#define TIMER1_OC1A_CLR_MSK                           0x80
#define TIMER1_OC1A_SET_MSK                           0xC0
#define TIMER1_OC1A_NON_INVERTING_MSK                 0x80
#define TIMER1_OC1A_INVERTING_MSK                     0xC0

#define TIMER1_OC1A_SPECIAL_TOGGLE_FASTPWM_MSK        0x40
#define TIMER1_OC1A_SPECIAL_TOGGLE_PHASE_CORRECT_MSK  0x40
#endif

#if TIMER1_OC1B_SELECT == ENABLE
#define TIMER1_OC1B_clr_MSK                           0xCF
#define TIMER1_OC1B_TOGGLE_MSK                        0x10
#define TIMER1_OC1B_CLR_MSK                           0x20
#define TIMER1_OC1B_SET_MSK                           0x30
#define TIMER1_OC1B_NON_INVERTING_MSK                 0x20
#define TIMER1_OC1B_INVERTING_MSK                     0x30

#define TIMER1_OC1B_SPECIAL_TOGGLE_FASTPWM_MSK        0x10
#define TIMER1_OC1B_SPECIAL_TOGGLE_PHASE_CORRECT_MSK  0x10
#endif

/* TIMER2 Behavior */
#define TIMER2_OC2_clr_MSK                           0xCF
#define TIMER2_OC2_TOGGLE_MSK                        0x10
#define TIMER2_OC2_CLR_MSK                           0x20
#define TIMER2_OC2_SET_MSK                           0x30
#define TIMER2_OC2_NON_INVERTING_MSK                 0x20
#define TIMER2_OC2_INVERTING_MSK                     0x30

#endif /* SRC_MCAL_TIMER_TIMER_PRIVATE_H_ */
