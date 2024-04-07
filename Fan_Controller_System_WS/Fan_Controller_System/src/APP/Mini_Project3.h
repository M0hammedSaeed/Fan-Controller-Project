/*******************************************************************************
* [File Name]:   Mini_Project3.h
*
* [Description]: Header file for Declaration and configuration the System control
* 				 fan speed based on the room temperature Functionality.
*
* [Author]:      Mohamed Saeed
*
********************************************************************************/

#ifndef SRC_APP_MINI_PROJECT3_H_
#define SRC_APP_MINI_PROJECT3_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/

#include "../EHAL/DC_MOTOR/dc_motor.h"
#include "../EHAL/LCD/lcd.h"
#include "../EHAL/TEMPERATURE_SENSOR/temperature_sensor.h"

/*------------------------------------------------------------------------------
 *                                    TYPES
 *------------------------------------------------------------------------------*/

typedef enum
{
	FAN_OFF,
	FAN_ON
}Fan_State_t;

/*------------------------------------------------------------------------------
 *                             Functions Declaration
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [Function Name]: applicationInit
 [Description]:	This function is responsible to Initialize the Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void applicationInit(void);

/*--------------------------------------------------------------------------------------
 [Function Name]: applicationStart
 [Description]:	This function is responsible to Start the Application
 [Args]:   void
 [Return]: Void
 ---------------------------------------------------------------------------------------*/
void applicationStart(void);

#endif /* SRC_APP_MINI_PROJECT3_H_ */
