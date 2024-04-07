/*******************************************************************************
* [File Name]:    Mini_Project3.c
*
* [Description]:  Source file for implementing the System control fan speed
* 				  based on the room temperature Functionality.
*
* [Author]:       Mohamed Saeed
*
********************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "Mini_Project3.h"
#include "../utils/std_types.h"

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/

uint8 temp;
Fan_State_t Fan = FAN_OFF;

/*--------------------------------------------------------------------------------------
 [Function Name]: applicationInit
 [Description]:	This function is responsible to Initialize the Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void applicationInit(void)
{
	/* Initialize Motor driver */
	DcMotor_Init(MOTOR_ID_1);

	/* Initialize LCD driver */
	LCD_init();

	/* Initialize Temperature driver */
	TEMP_Init();

	/* Display this string "Temp =   C" only once on LCD at the second row*/
	LCD_moveCursor(1, 2);
	LCD_displayString("Temp =    C");
}

/*--------------------------------------------------------------------------------------
 [Function Name]: applicationStart
 [Description]:	This function is responsible to Start the Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void applicationStart(void)
{
	/* Get the temperature value */
	temp = TEMP_getValue();

	/* Control the duty cycle of the output PWM signal (Fan Speed) based on the temperature value */
	if(temp >= 120)
	{
		Fan = FAN_ON;
		DcMotor_Rotate(MOTOR_ID_1, DC_MOTOR_CLOCKWISE, 100); /* Rotates the motor with 100% from its speed */
	}
	else if(temp >= 90)
	{
		Fan = FAN_ON;
		DcMotor_Rotate(MOTOR_ID_1, DC_MOTOR_CLOCKWISE, 75); /* Rotates the motor with 75% from its speed */
	}
	else if(temp >= 60)
	{
		Fan = FAN_ON;
		DcMotor_Rotate(MOTOR_ID_1, DC_MOTOR_CLOCKWISE, 50); /* Rotates the motor with 50% from its speed */
	}
	else if(temp >= 30)
	{
		Fan = FAN_ON;
		DcMotor_Rotate(MOTOR_ID_1, DC_MOTOR_CLOCKWISE, 25); /* Rotates the motor with 25% from its speed */
	}
	else
	{
		Fan = FAN_OFF;/* Stop the motor */
		DcMotor_Rotate(MOTOR_ID_1, DC_MOTOR_STOP, 0);
	}

	/* Display the temperature and FAN state */
	if(Fan == FAN_OFF)
	{
		LCD_moveCursor(0, 3);
		LCD_displayString("FAN is OFF");
	}
	else
	{
		LCD_moveCursor(0, 3);
		LCD_displayString("FAN is ON ");
	}

	/* Display the temperature value every time at same position */
	LCD_moveCursor(1, 9);
	if(temp >= 100)
	{
		LCD_intgerToString(temp);
	}
	else
	{
		LCD_intgerToString(temp);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}

}
