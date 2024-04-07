/*******************************************************************************
 * [ File Name ]: dc_motor.c
 *
 * [Description]:  Source File that contain functions prototypes DC-Motor.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *********************************************************************************/

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/

#include "dc_motor.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/TIMER/timer.h"

/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
 *------------------------------------------------------------------------------*/

/*
 * [FUNCTION NAME]: DcMotor_Init
 * [DISCRIPTION]  :  Initialize the DC Motor by:
 * 					 1. Setup the direction of the two motor pins as output by send the request to GPIO driver.
 * 					 2. Stop the motor at the beginning
 * [Args]  : Enum to select Motor ID
 * [RUTURN]: Void
 */
void DcMotor_Init(EN_MororID_t MOTOR_ID)
{
	switch(MOTOR_ID)
	{
	case MOTOR_ID_1:
		/* Setup the motor pins as output pins */
		GPIO_SetPinDir(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, pin_output);
		GPIO_SetPinDir(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, pin_output);

		/* Motor is stopped at the beginning */
		GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, logic_low);
		GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, logic_low);
		break;
	}
}

/*
 * [FUNCTION NAME]: DcMotor_Init
 * [DISCRIPTION]  :  Rotate  or Stop the motor according to the state input variable.
 * [Args]  : 1- Enum to select Motor ID
 * 			 2- Enum to select State
 * 			 3- uint8 to select Speed
 * [RUTURN]: Void
 */
void DcMotor_Rotate(EN_MororID_t MOTOR_ID, EN_DcMotorState_t state, uint8 speed)
{
	switch(MOTOR_ID)
	{
	case MOTOR_ID_1:
		if(state == DC_MOTOR_STOP)
		{
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, logic_low);
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, logic_low);

			Timer0_PWM_DutyCycle(speed);
		}
		else if(state == DC_MOTOR_ON)
		{
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, logic_low);
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, logic_high);
			Timer0_PWM_DutyCycle(speed);
		}
		else if(state == DC_MOTOR_CLOCKWISE)
		{
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, logic_low);
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, logic_high);
			Timer0_PWM_DutyCycle(speed);
		}
		else if(state == DC_MOTOR_ANTI_CLOCKWISE)
		{
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN1, logic_high);
			GPIO_WritePin(DC_MOTOR_ID_1_PORT, DC_MOTOR_ID_1_PIN2, logic_low);
			Timer0_PWM_DutyCycle(speed);
		}
		else
		{
			/* Invalid Input State - Do Nothing */
		}
	}
}
