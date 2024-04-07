/*******************************************************************************
 * [ File Name ]: lcd.h
 *
 * [Description]: Header File that contain functions prototypes for the LCD driver.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *******************************************************************************/

#ifndef SRC_EHAL_LCD_LCD_H_
#define SRC_EHAL_LCD_LCD_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                          Definitions & Configuration
 -------------------------------------------------------------------------------*/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE			   8

#if ((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

//#define LCD_LAST_PORT_PINS

#if (LCD_DATA_BITS_MODE == 4)
/* if LCD_LAST_PORT_PINS is defined in the code, the LCD driver will use the last 4 pins in the GPIO port for data.
 * To use the first four pins in the GPIO port for data just remove LCD_LAST_PORT_PINS
 */
#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_PORT_PIN_ID		   PIN4_ID
#else
#define LCD_FIRST_PORT_PIN_ID		   PIN0_ID
#endif

#endif

/* LCD HW Ports and Pins Ids */
/* Register Select */
#define LCD_RS_PORT_ID				   PORTD_ID
#define LCD_RS_PIN_ID				   PIN0_ID
/* Read and Write Control bus */
#define LCD_RW_PORT_ID				   PORTD_ID
#define LCD_RW_PIN_ID				   PIN1_ID
/* Data Enable */
#define LCD_E_PORT_ID				   PORTD_ID
#define LCD_E_PIN_ID				   PIN2_ID
/* Data bus */
#define LCD_DATA_PORT_ID			   PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND			   0x01
#define LCD_GO_TO_HOME				   0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_init
 [DISCRIPTION]:	Initialize the LCD:
 	 	 	 1. Setup the LCD pins directions by use the GPIO driver.
  	  	  	 2. Setup the LCD Data Mode 4-bits or 8-bits.
 [Args]: void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_init(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_sendCommand
 [DISCRIPTION]:	Send the required command to the screen
  [Args]: uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_sendCommand(uint8 command);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayCharacter
 [DISCRIPTION]:	Display the required character on the screen
  [Args]: uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayCharacter(uint8 data);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayString
 [DISCRIPTION]:	Display the required string on the screen
  [Args]: pointer to uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayString(const char *Str);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_moveCursor
 [DISCRIPTION]:	Move the cursor to a specified row and column index on the screen
  [Args]:  uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_moveCursor(uint8 row,uint8 col);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_displayStringRowColumn
 [DISCRIPTION]:	Display the required string in a specified row and column index on the screen
  [Args]:  uint8
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_intgerToString
 [DISCRIPTION]:	Display the required decimal value on the screen
  [Args]:  uint832
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_intgerToString(int data);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: LCD_clearScreen
 [DISCRIPTION]:	Send the clear screen command
  [Args]:  void
 [RUTURN]: void
 ---------------------------------------------------------------------------------------*/
void LCD_clearScreen(void);

#endif /* SRC_EHAL_LCD_LCD_H_ */
