/** \file
 *  Defines task parameters, hardware assignments and controller button/axis assignment.
 *
 * This header contains basic parameters for the robot. All parameters must be constants with internal
 * linkage, otherwise the One Definition Rule will be violated..
 */

// TODO: please go over these items with a knowledgeable mentor and check to see what we need/don't need
#ifndef ROBOT_PARAMS_H
#define ROBOT_PARAMS_H

//Robot
#include "JoystickLayouts.h"			//For joystick layouts

//Robot Params
const char* const ROBOT_NAME =		"RhsRobot2019";	//Formal name
const char* const ROBOT_NICKNAME =  "TKB";			//Nickname
const char* const ROBOT_VERSION =	"0.1";			//Version

//Utility Functions - Define commonly used operations here
#define ABLIMIT(a,b)		if(a > b) a = b; else if(a < -b) a = -b;
#define TRUNC_THOU(a)		((int)(1000 * a)) * .001
#define TRUNC_HUND(a)		((int)(100 * a)) * .01
#define PRINTAUTOERROR		printf("Early Death! %s %i \n", __FILE__, __LINE__);

//Task Params - Defines component task priorities relative to the default priority.
//EXAMPLE: const int DRIVETRAIN_PRIORITY = DEFAULT_PRIORITY -2;
const int DEFAULT_PRIORITY      = 50;
const int COMPONENT_PRIORITY 	= DEFAULT_PRIORITY;
const int DRIVE_PRIORITY 		= DEFAULT_PRIORITY;

//Task Names - Used when you view the task list but used by the operating system
//EXAMPLE: const char* DRIVETRAIN_TASKNAME = "tDrive";
const char* const COMPONENT_TASKNAME	= "tComponent";
const char* const DRIVE_TASKNAME		= "tDrive";

//TODO change these variables throughout the code to PIPE or whatever instead  of QUEUE
//Queue Names - Used when you want to open the message queue for any task
//NOTE: 2015 - we use pipes instead of queues
//EXAMPLE: const char* DRIVETRAIN_TASKNAME = "tDrive";

const char* const COMPONENT_QUEUE 	= "/tmp/qComp";
const char* const DRIVE_QUEUE 		= "/tmp/qDrive";

//PWM Channels - Assigns names to PWM ports 1-10 on the Roborio
//EXAMPLE: const int PWM_DRIVETRAIN_FRONT_LEFT_MOTOR = 1;

//const int PWM_DRIVETRAIN_LEFT_MOTOR = 0;
//const int PWM_DRIVETRAIN_RIGHT_MOTOR = 1;

//CAN IDs - Assigns names to the various CAN IDs
//EXAMPLE: const int CAN_PDB = 0;
/** \page motorID Motor Controller IDs
 * \verbatim
0 - PDB
1 - left drive motor
2 - right drive motor
Add more as needed.
 \endverbatim
 */

const int CAN_PCM = 0; // Both must be zero
const int CAN_PDB = 0; // Both must be zero

const int SLOW_HALL_EFFECT_SLOT = 1;
const int STOP_HALL_EFFECT_SLOT = 0;
const int ARM_HALL_EFFECT_SLOT = 9;

// Had to change these, lowkey salty at mechanical ~ Jiff
const int CAN_RIGHT_MASTER = 1;
const int CAN_LEFT_MASTER = 4;

//Relay Channels - Assigns names to Relay ports 1-8 on the roboRio
//EXAMPLE: const int RLY_COMPRESSOR = 1;

//Digital I/O - Assigns names to Digital I/O ports 1-14 on the roboRio
//EXAMPLE: const int DIO_DRIVETRAIN_BEAM_BREAK = 0;

//Solenoid - Assigns names to Solenoid ports 1-8 on the roboRio
//EXAMPLE: const int SOL_DRIVETRAIN_SOLENOID_SHIFT_IN = 1;

//I2C - Assigns names to I2C ports 1-2 on the Roborio
//EXAMPLE: const int IO2C_AUTO_ACCEL = 1;

//Analog I/O - Assigns names to Analog I/O ports 1-8 on the roboRio
//EXAMPLE: const int AIO_BATTERY = 8;

//Relay I/O - Assigns names to Realy I/O ports 1-8 on the roboRio
//EXAMPLE: const int RELAY_LED = 0;

// PDB Channels

//const int PDB_DRIVE_CHANNEL_L1 = 0;
//const int PDB_DRIVE_CHANNEL_R1 = 15;

//Joystick Input Device Counts - used by the listener to watch buttons and axis
const int JOYSTICK_BUTTON_COUNT = 10;
const int JOYSTICK_AXIS_COUNT = 5;

//POV IDs - Assign names to the 9 POV positions: -1 to 7
//EXAMPLE: const int POV_STILL = -1;
const int POV_STILL = -1;

//Primary Controller Mapping - Assigns action to buttons or axes on the first joystick
#undef	USE_X3D_FOR_CONTROLLER_1
#undef	USE_XBOX_FOR_CONTROLLER_1
#define	USE_L310_FOR_CONTROLLER_1

//Secondary Controller Mapping - Assigns action to buttons or axes on the second joystick
#undef	USE_X3D_FOR_CONTROLLER_2
#undef 	USE_XBOX_FOR_CONTROLLER_2
#define USE_L310_FOR_CONTROLLER_2

/** \page joysticks Joystick Layouts
 * \verbatim
 	 +++++ Controller 1 +++++
  	A Button					??
  	B Button					??
  	X Button					??
  	Y Button					??
  	Start Button				??
  	Back Button					??
  	Left Bumper					??
  	Right Bumper				??
  	Left Thumbstick Button		Y axis is speed
  	Right Thumbstick Button		X axis is direction
  	Left Thumbstick				??
  	Right Thumbstick			??
  	D-pad						??
  	Left Trigger				??
  	RightTrigger				??

 	 +++++ Controller 2 +++++
  	A Button					~~
  	B Button					~~
  	X Button					~~
  	Y Button					~~
  	Start Button				~~
  	Back Button					~~
  	Left Bumper					~~
  	Right Bumper				~~
 	Left Thumbstick Button		~~
  	Right Thumbstick Button		~~
  	Left Thumbstick				~~
  	Right Thumbstick			~~
  	D-pad						~~
  	Left Trigger				~~
  	RightTrigger				~~
 \endverbatim
 */
#ifdef USE_XBOX_FOR_CONTROLLER_1
#endif

#ifdef USE_L310_FOR_CONTROLLER_1
#define ARCADE_DRIVE_LEFT			((pControllerDriver->GetRawAxis(L310_THUMBSTICK_LEFT_Y)) + (-1*(pControllerDriver->GetRawAxis(L310_THUMBSTICK_RIGHT_X))))
#define ARCADE_DRIVE_RIGHT			((pControllerDriver->GetRawAxis(L310_THUMBSTICK_LEFT_Y)) - (-1*(pControllerDriver->GetRawAxis(L310_THUMBSTICK_RIGHT_X))))
#endif // USE_L310_FOR_CONTROLLER_1

#ifdef USE_X3D_FOR_CONTROLLER_2
#endif // USE_X3D_FOR_CONTROLLER_2

#ifdef USE_XBOX_FOR_CONTROLLER_2
#endif // USE_XBOX_FOR_CONTROLLER_2

#ifdef USE_L310_FOR_CONTROLLER_2
#endif // USE_L310_FOR_CONTROLLER_2

#endif //ROBOT_PARAMS_H
