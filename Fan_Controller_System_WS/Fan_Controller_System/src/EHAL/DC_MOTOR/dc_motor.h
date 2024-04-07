/*******************************************************************************
 * [ File Name ]: dc_motor.h
 *
 * [Description]: Header File that contain functions prototypes DC-Motor.
 *
 * [   Author  ]: Mohamed Saeed
 *
 *********************************************************************************/


#ifndef SRC_EHAL_DC_MOTOR_DC_MOTOR_H_
#define SRC_EHAL_DC_MOTOR_DC_MOTOR_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/

#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                              Definitions
 -------------------------------------------------------------------------------*/

typedef enum
{
	MOTOR_ID_1
}EN_MororID_t;

typedef enum
{
	DC_MOTOR_STOP,
	DC_MOTOR_ON,
	DC_MOTOR_CLOCKWISE,
	DC_MOTOR_ANTI_CLOCKWISE
}EN_DcMotorState_t;

/*------------------------------------------------------------------------------
 *                             	 Configuration
 -------------------------------------------------------------------------------*/

#define DC_MOTOR_ID_1_PORT       PORTB_ID

#define DC_MOTOR_ID_1_PIN1		 PIN0_ID
#define DC_MOTOR_ID_1_PIN2		 PIN1_ID

/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/

/*
 * [FUNCTION NAME]: DcMotor_Init
 * [DISCRIPTION]  :  Initialize the DC Motor by:
 * 					 1. Setup the direction of the two motor pins as output by send the request to GPIO driver.
 * 					 2. Stop the motor at the beginning
 * [Args]  : Enum to select Motor ID
 * [RUTURN]: Void
 */
void DcMotor_Init(EN_MororID_t MOTOR_ID);

/*
 * [FUNCTION NAME]: DcMotor_Init
 * [DISCRIPTION]  :  Rotate  or Stop the motor according to the state input variable.
 * [Args]  : 1- Enum to select Motor ID
 * 			 2- Enum to select State
 * 			 3- uint8 to select Speed
 * [RUTURN]: Void
 */
void DcMotor_Rotate(EN_MororID_t MOTOR_ID, EN_DcMotorState_t state, uint8 speed);

#endif /* SRC_EHAL_DC_MOTOR_DC_MOTOR_H_ */
