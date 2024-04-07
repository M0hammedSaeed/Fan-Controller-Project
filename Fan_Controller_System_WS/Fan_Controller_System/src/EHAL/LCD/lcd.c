/*******************************************************************************
 * [ File Name ]: lcd.c
 *
 * [Description]: Source File that contain implementation functions the LCD driver.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/

#include "lcd.h"
#include "../../MCAL/GPIO/gpio.h"
#include "util/delay.h"

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_init
 [DISCRIPTION]:	Initialize the LCD:
 	 	 	 1. Setup the LCD pins directions by use the GPIO driver.
  	  	  	 2. Setup the LCD Data Mode 4-bits or 8-bits.
 [Args]: void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_init(void)
{
	/* Configure the direction for RS, RW and E pins as output pins */
	GPIO_SetPinDir(LCD_RS_PORT_ID, LCD_RS_PIN_ID, pin_output);
	GPIO_SetPinDir(LCD_RW_PORT_ID, LCD_RW_PIN_ID, pin_output);
	GPIO_SetPinDir(LCD_E_PORT_ID, LCD_E_PIN_ID, pin_output);

#if (LCD_DATA_BITS_MODE == 4)

	/* Configure 4 pins in the data port as output pins */
	GPIO_SetPinDir(LCD_DATA_PORT_ID, LCD_FIRST_PORT_PIN_ID, pin_output);
	GPIO_SetPinDir(LCD_DATA_PORT_ID, LCD_FIRST_PORT_PIN_ID+1, pin_output);
	GPIO_SetPinDir(LCD_DATA_PORT_ID, LCD_FIRST_PORT_PIN_ID+2, pin_output);
	GPIO_SetPinDir(LCD_DATA_PORT_ID, LCD_FIRST_PORT_PIN_ID+3, pin_output);

	LCD_sendCommand(LCD_GO_TO_HOME);
	/* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif (LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_SetPortDir(LCD_DATA_PORT_ID, port_output);
	 /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
#endif

	/* cursor off */
	LCD_sendCommand(LCD_CURSOR_OFF);
	/* clear LCD at the beginning */
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_sendCommand
 [DISCRIPTION]:	Send the required command to the screen
  [Args]: uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_sendCommand(uint8 command)
{

	GPIO_WritePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); /* Instruction Mode RS=0 */
	GPIO_WritePin(LCD_RW_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdsw = 190ns */

#if (LCD_DATA_BITS_MODE == 4)
	uint8 lcd_port_value = 0;
	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_ReadPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | (command & 0xF0);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | ((command & 0xF0) >> 4);
#endif
	GPIO_WritePort(LCD_DATA_PORT_ID, lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdsw = 190ns */

	/* out the first 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_ReadPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | ((command & 0x0F) << 4);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | (command & 0x0F);
#endif
	GPIO_WritePort(LCD_DATA_PORT_ID, lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == 8)
	GPIO_WritePort(LCD_DATA_PORT_ID, command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayCharacter
 [DISCRIPTION]:	Display the required character on the screen
  [Args]: uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayCharacter(uint8 data)
{
	GPIO_WritePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* Data Mode RS=1 */
	GPIO_WritePin(LCD_RW_PORT_ID, LCD_RW_PIN_ID, LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdsw = 190ns */

#if (LCD_DATA_BITS_MODE == 4)
	uint8 lcd_port_value = 0;
	/* out the last 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_ReadPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | (data & 0xF0);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | ((data & 0xF0) >> 4);
#endif
	GPIO_WritePort(LCD_DATA_PORT_ID, lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdsw = 190ns */

	/* out the first 4 bits of the required command to the data bus D4 --> D7 */
	lcd_port_value = GPIO_ReadPort(LCD_DATA_PORT_ID);
#ifdef LCD_LAST_PORT_PINS
	lcd_port_value = (lcd_port_value & 0x0F) | ((data & 0x0F) << 4);
#else
	lcd_port_value = (lcd_port_value & 0xF0) | (data & 0x0F);
#endif
	GPIO_WritePort(LCD_DATA_PORT_ID, lcd_port_value);

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif (LCD_DATA_BITS_MODE == 8)
	GPIO_WritePort(LCD_DATA_PORT_ID, data); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayString
 [DISCRIPTION]:	Display the required string on the screen
  [Args]: pointer to uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayString(const char *Str)
{
	while((*Str) != '\0')

	{
		LCD_displayCharacter(*Str);
		Str++;
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_moveCursor
 [DISCRIPTION]:	Move the cursor to a specified row and column index on the screen
  [Args]:  uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address = col;
		break;
	case 1:
		lcd_memory_address = col+0x40;
		break;
	case 2:
		lcd_memory_address = col+0x10;
		break;
	case 3:
		lcd_memory_address = col+0x50;
		break;
	default: ;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayStringRowColumn
 [DISCRIPTION]:	Display the required string in a specified row and column index on the screen
  [Args]:  uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row, col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_intgerToString
 [DISCRIPTION]:	Display the required decimal value on the screen
  [Args]:  uint832
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ASCII result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_clearScreen
 [DISCRIPTION]:	Send the clear screen command
  [Args]:  void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
