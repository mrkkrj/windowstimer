#include "stdafx.h"

#include "WindowsTimer.hpp"
#include <iostream>


void testTimerCallback();

int volatile someFlag = 0; // we are using c++89 with MSVC, thus it's as good as an atomic<>


int main()
{
	std::cout << "started (" << WindowsTimer::currTimeStrgSeconds() << ")..." << std::endl;

	// OPEN TODO:: if(argc > 1) { TEST:: "21:00" ... XXXXX

	WindowsTimer timer;
	timer.setCallback(testTimerCallback);

	bool cyclic = false;
	int secondsToStop = 10;
	std::cout << " - timeout=" << secondsToStop << " [secs]" << std::endl;

	timer.start(secondsToStop, cyclic);

	while (true) 
	{
		if (someFlag == 1) 
		{
			break;
		}

		Sleep(250);
	}

	// ready
	std::cout << "exiting (" << WindowsTimer::currTimeStrgSeconds() << ")" << std::endl;

    return 0;
}

void testTimerCallback()
{
	std::cout << "in testTimerCallback" << std::endl;
	someFlag = 1;
}
