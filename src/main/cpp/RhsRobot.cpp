/** \file
 * Main robot class.
 *
 * The RhsRobot class is the main robot class. It inherits from RhsRobotBase and MUST define the Init() function, the Run() function, and
 * the OnStateChange() function.  Messages from the DS are processed and commands sent to the subsystems
 * that implement behaviors for each part for the robot.
 */

#include "ComponentBase.h"
#include "RhsRobot.h"
#include "RobotParams.h"
#include "frc/WPILib.h"

// The constructor sets the pointer to our objects to NULL.  We use pointers so we
// can control when the objects are instantiated.  It looks kinda old school but is
// standard practice in embedded systems.

RhsRobot::RhsRobot() {
	pControllerDriver = NULL;
	pControllerOperator = NULL;
	pDrive = NULL;

	memset( &lastMessage, 0, sizeof(lastMessage));
	memset( &maxMessage, 0, sizeof(maxMessage));
	memset( &robotMessage, 0, sizeof(robotMessage));

	iLoop = 0;            // a helpful little loop counter
}

// This will never get used but we make it functional anyways.  We iterate through our objects
// (with messaging) then delete the system objects.

RhsRobot::~RhsRobot() {
	std::vector<ComponentBase *>::iterator nextComponent = ComponentSet.begin();

	for(; nextComponent != ComponentSet.end(); ++nextComponent)
	{
		delete (*nextComponent);
	}

	// delete other system objects here (but not our message-based objects)

	delete pControllerDriver;
	delete pControllerOperator;
}

void RhsRobot::Init() {
	/* 
	 * Set all pointers to null and then allocate memory and construct objects
	 * EXAMPLE:	pDrive = NULL; (in constructor)
	 * 			pDrive = new Drivetrain(); (in RhsRobot::Init())
	 */

	
	pControllerDriver = new frc::Joystick(0);
	pControllerOperator = new frc::Joystick(1);

	pDrive = new Drive();

	std::vector<ComponentBase *>::iterator nextComponent = ComponentSet.begin();

	if(pDrive)
	{
		nextComponent = ComponentSet.insert(nextComponent, pDrive);
	}

	// instantiate our other objects here
}


// this method iterates through all our objects (in our message infrastructure) and sends
// them a message, it is used mostly for telling every object the robot state has changed

void RhsRobot::OnStateChange() {
	std::vector<ComponentBase *>::iterator nextComponent;

	for(nextComponent = ComponentSet.begin();
			nextComponent != ComponentSet.end(); ++nextComponent)
	{
		(*nextComponent)->SendMessage(&robotMessage);
	}
}

// this method is where the magic happens.  It is called every time we get a new message from th driver station

void RhsRobot::Run() {
	/* Poll for control data and send messages to each subsystem. Surround blocks with if(component) so entire components can be disabled
	   by commenting out their construction.
	   
	   if(pDrive)
	   {
			robotMessage.command  = COMMAND_DRIVETRAIN_RUN_ARCADE;
						robotMessage.params.adrive.left = (ARCADE_DRIVE_LEFT * ARCADE_DRIVE_LEFT * ARCADE_DRIVE_LEFT);
						robotMessage.params.adrive.right = (ARCADE_DRIVE_RIGHT * ARCADE_DRIVE_RIGHT * ARCADE_DRIVE_RIGHT);
						pDrive->SendMessage(&robotMessage);
		}
	 */

		if(pDrive)
		{
			robotMessage.command  = COMMAND_DRIVE_RUN_ARCADE;
						robotMessage.params.adrive.left = (ARCADE_DRIVE_LEFT * ARCADE_DRIVE_LEFT * ARCADE_DRIVE_LEFT);
						robotMessage.params.adrive.right = (ARCADE_DRIVE_RIGHT * ARCADE_DRIVE_RIGHT * ARCADE_DRIVE_RIGHT);
						pDrive->SendMessage(&robotMessage);
		}

}

HAL_Bool HAL_Initialize(int32_t timeout, int32_t mode);

//START_ROBOT_CLASS(RhsRobot) // why is this giving an error Mr. B :(

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<RhsRobot>(); }
#endif

