/*******************************************************************************
 * [   Module  ]: General Purpose Input Output Register
 *
 * [ File Name ]: gpio_private.h
 *
 * [Description]: Header File For ATmega32 micro-controller Channels.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_MCAL_GPIO_GPIO_PRIVATE_H_
#define SRC_MCAL_GPIO_GPIO_PRIVATE_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/

/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 *)0x3B)
#define DDRA_REG	(*(volatile uint8 *)0x3A)
#define PINA_REG	(*(volatile const uint8 *)0x39)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 *)0x38)
#define DDRB_REG	(*(volatile uint8 *)0x37)
#define PINB_REG	(*(volatile const uint8 *)0x36)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 *)0x35)
#define DDRC_REG	(*(volatile uint8 *)0x34)
#define PINC_REG	(*(volatile const uint8 *)0x33)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 *)0x32)
#define DDRD_REG	(*(volatile uint8 *)0x31)
#define PIND_REG	(*(volatile const uint8 *)0x30)

#endif /* SRC_MCAL_GPIO_GPIO_PRIVATE_H_ */
