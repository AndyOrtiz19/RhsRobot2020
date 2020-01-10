/** \file
 * Example of subsystem task behavior.
 *
 * This class is derived from the standard Drive base class and includes
 * initialization for the devices used to control a given subsystem.
 *
 * The task receives messages from the main robot class and implements behaviors
 * for a given subsystem.
 */

#include "Drive.h"
#include "ComponentBase.h"
#include "RobotParams.h"


//Robot

Drive::Drive()
: ComponentBase(DRIVE_TASKNAME, DRIVE_QUEUE, DRIVE_PRIORITY)
{
	//TODO: add member objects

	pLeftMaster = new TalonSRX(CAN_LEFT_MASTER);
	pRightMaster = new TalonSRX(CAN_RIGHT_MASTER);

	pLeftMaster->Set(ControlMode::PercentOutput, 0.0);
	pRightMaster->Set(ControlMode::PercentOutput, 0.0);
	pRightMaster->SetInverted(true);

	pTask = new std::thread(&Drive::StartTask, this, DRIVE_TASKNAME, DRIVE_PRIORITY);
	wpi_assert(pTask);
}

Drive::~Drive()
{
	//TODO delete member objects

	delete(pTask);
}

void Drive::OnStateChange()	
{
}

void Drive::Run()
{
	switch(localMessage.command)			//Reads the message command
	{
		case COMMAND_DRIVE_RUN_ARCADE:
			ArcadeDrive(localMessage.params.adrive.left, localMessage.params.adrive.right);
			break;

		default:
			break;
		}
}


void Drive::ArcadeDrive(float fLeft, float fRight)
{
	pLeftMaster->Set(ControlMode::PercentOutput, fLeft);	
	pRightMaster->Set(ControlMode::PercentOutput, fRight);	
}