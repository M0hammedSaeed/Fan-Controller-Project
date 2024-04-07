/*******************************************************************************
 * [   Module  ]: General Purpose Input Output
 *
 * [ File Name ]: GPIO.c
 *
 * [Description]: Source File For ATmega32 micro-controller Channels.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/
#include "gpio.h"
#include "gpio_private.h"
#include "../../utils/common_macros.h"

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_SetPinDir
 [DISCRIPTION]:	This function is responsible to Setting the direction of a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Direction (input_pin or output_pin)
 [RUTURN]: Void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/

void GPIO_SetPinDir(uint8 PORTn, uint8 PINn, GPIO_PinDirection Dir)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number.
	 */
	if((PORTn >= NUM_OF_PORTS) || (PINn >= NUM_OF_PINS_PER_PORT))
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(PORTn)
		{
		case PORTA_ID:
			if(Dir == pin_output)
			{
				SET_BIT(DDRA_REG,PINn);
			}
			else
			{
				CLEAR_BIT(DDRA_REG,PINn);
			}
			break;
		case PORTB_ID:
			if(Dir == pin_output)
			{
				SET_BIT(DDRB_REG,PINn);
			}
			else
			{
				CLEAR_BIT(DDRB_REG,PINn);
			}
			break;
		case PORTC_ID:
			if(Dir == pin_output)
			{
				SET_BIT(DDRC_REG,PINn);
			}
			else
			{
				CLEAR_BIT(DDRC_REG,PINn);
			}
			break;
		case PORTD_ID:
			if(Dir == pin_output)
			{
				SET_BIT(DDRD_REG,PINn);
			}
			else
			{
				CLEAR_BIT(DDRD_REG,PINn);
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPin
 [DISCRIPTION]:	This function is responsible to Read the value from a specific pin.
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPin(uint8 PORTn, uint8 PINn)
{
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((PORTn >= NUM_OF_PORTS) || (PINn >= NUM_OF_PINS_PER_PORT))
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		/* Read the pin value as required */
		switch(PORTn)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA_REG,PINn))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB_REG,PINn))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC_REG,PINn))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND_REG,PINn))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}
	return pin_value;
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePin
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WritePin(uint8 PORTn, uint8 PINn, STD_LevelType level)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((PORTn >= NUM_OF_PORTS) || (PINn >= NUM_OF_PINS_PER_PORT))
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		/* Write the pin value as required */
		switch(PORTn)
		{
		case PORTA_ID:
			if(level == LOGIC_HIGH)
			{
				SET_BIT(PORTA_REG,PINn);
			}
			else
			{
				CLEAR_BIT(PORTA_REG,PINn);
			}
			break;
		case PORTB_ID:
			if(level == LOGIC_HIGH)
			{
				SET_BIT(PORTB_REG,PINn);
			}
			else
			{
				CLEAR_BIT(PORTB_REG,PINn);
			}
			break;
		case PORTC_ID:
			if(level == LOGIC_HIGH)
			{
				SET_BIT(PORTC_REG,PINn);
			}
			else
			{
				CLEAR_BIT(PORTC_REG,PINn);
			}
			break;
		case PORTD_ID:
			if(level == LOGIC_HIGH)
			{
				SET_BIT(PORTD_REG,PINn);
			}
			else
			{
				CLEAR_BIT(PORTD_REG,PINn);
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPin
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific pin.
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPin(uint8 PORTn, uint8 PINn)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((PORTn >= NUM_OF_PORTS) || (PINn >= NUM_OF_PINS_PER_PORT))
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		/* Flip the pin value as required */
		switch(PORTn)
		{
		case PORTA_ID:
			TOGGLE_BIT(PORTA_REG,PINn);
			break;
		case PORTB_ID:
			TOGGLE_BIT(PORTB_REG,PINn);
			break;
		case PORTC_ID:
			TOGGLE_BIT(PORTC_REG,PINn);
			break;
		case PORTD_ID:
			TOGGLE_BIT(PORTD_REG,PINn);
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_SetPortDir
 [DISCRIPTION]:	This function is responsible to Setting the direction of a specific Port .
 [Args]: PORTn_ID(n=A,B,C,D) and Direction (input_port or output_port)
 [RUTURN]: Void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_SetPortDir(uint8 PORTn, GPIO_PortDirection Dir)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		switch(PORTn)
		{
		case PORTA_ID:
			DDRA_REG = Dir;
			break;
		case PORTB_ID:
			DDRB_REG = Dir;
			break;
		case PORTC_ID:
			DDRC_REG = Dir;
			break;
		case PORTD_ID:
			DDRD_REG = Dir;
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPort
 [DISCRIPTION]:	This function is responsible to Read the value from a specific PORT .
 [Args]: PORTn_ID(n=A,B,C,D)
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPort(uint8 PORTn)
{
	uint8 port_value = LOGIC_LOW;
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		/* Read the port value as required */
		switch(PORTn)
		{
		case PORTA_ID:
			port_value = PINA_REG;
			break;
		case PORTB_ID:
			port_value = PINB_REG;
			break;
		case PORTC_ID:
			port_value = PINC_REG;
			break;
		case PORTD_ID:
			port_value = PIND_REG;
			break;
		}
	}
	return port_value;
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePort
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific port .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WritePort(uint8 PORTn, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		switch(PORTn)
		{
		case PORTA_ID:
			PORTA_REG = value;
			break;
		case PORTB_ID:
			PORTB_REG = value;
			break;
		case PORTC_ID:
			PORTC_REG = value;
			break;
		case PORTD_ID:
			PORTD_REG = value;
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPort
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific port .
 [Args]: PORTn_ID(n=A,B,C,D)
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPort(uint8 PORTn)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		switch(PORTn)
		{
		case PORTA_ID:
			PORTA_REG = ~PORTA_REG;
			break;
		case PORTB_ID:
			PORTB_REG = ~PORTB_REG;
			break;
		case PORTC_ID:
			PORTC_REG = ~PORTC_REG;
			break;
		case PORTD_ID:
			PORTD_REG = ~PORTD_REG;
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WriteLowNibble
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific Low Nibble Port .
 [Args]: PORTn_ID(n=A,B,C,D) and value
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WriteLowNibble(uint8 PORTn, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		value &= 0x0F;

		switch(PORTn)
		{
		case PORTA_ID:
			PORTA_REG &= 0xF0;
			PORTA_REG |= value;

			break;
		case PORTB_ID:
			PORTB_REG &= 0xF0;
			PORTB_REG |= value;
			break;
		case PORTC_ID:
			PORTC_REG &= 0xF0;
			PORTC_REG |= value;
			break;
		case PORTD_ID:
			PORTD_REG &= 0xF0;
			PORTD_REG |= value;
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WriteHighNibble
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific High Nibble Port .
 [Args]: PORTn_ID(n=A,B,C,D) and value
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WriteHighNibble(uint8 PORTn, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(PORTn >= NUM_OF_PORTS)
	{
		/* WILL DO NOTHING Just Prevent The Else To Implement */
	}
	else
	{
		value &= 0xF0;

		switch(PORTn)
		{
		case PORTA_ID:
			PORTA_REG &= 0x0F;
			PORTA_REG |= value;

			break;
		case PORTB_ID:
			PORTB_REG &= 0x0F;
			PORTB_REG |= value;
			break;
		case PORTC_ID:
			PORTC_REG &= 0x0F;
			PORTC_REG |= value;
			break;
		case PORTD_ID:
			PORTD_REG &= 0x0F;
			PORTD_REG |= value;
			break;
		}
	}
}
