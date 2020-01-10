/** \file
 * Main robot class.
 *
 * The RhsRobot class is the main robot class. It inherits from RhsRobotBase and MUST define the Init() function, the Run() function, and
 * the OnStateChange() function.  Messages from the DS are processed and commands.
 */
#ifndef RHS_ROBOT_H
#define RHS_ROBOT_H

#include "RhsRobotBase.h"
#include "frc/WPILib.h"

#include "Drive.h"

class RhsRobot : public RhsRobotBase
{
public:
	RhsRobot();
	virtual ~RhsRobot();

private:
	std::vector<ComponentBase *> ComponentSet;

	frc::Joystick* pControllerDriver;
	frc::Joystick* pControllerOperator;

	RobotMessage lastMessage;
	RobotMessage maxMessage;

	void Init();
	void OnStateChange();
	void Run();
	void MonitorPDB();

	Drive *pDrive;

	int iLoop;
};

#endif //RHS_ROBOT_H
