/** \file
 * Example of subsystem task declaration.
 *
 * This class is derived from the standard Drive base class and includes
 * initialization for the devices used to control a given subsystem.
 *
 */
#ifndef DRIVE_H
#define DRIVE_H

/**
	A template class for creating new components
 */
#include "ComponentBase.h"			//For ComponentBase class
#include <pthread.h>
#include <string>

//Robot
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"


class Drive : public ComponentBase
{
public:
	Drive();
	virtual ~Drive();
	static void *StartTask(void *pThis, const char* szComponentName, int iPriority)
	{
		pthread_setname_np(pthread_self(), szComponentName);
		pthread_setschedprio(pthread_self(), iPriority);
		((Drive *)pThis)->DoWork();
		return(NULL);
	}

private:
	TalonSRX *pLeftMaster;
	TalonSRX *pRightMaster;

	void OnStateChange();
	void Run();

	void ArcadeDrive(float fLeft, float fRight);
};

#endif			//DRIVE_H
