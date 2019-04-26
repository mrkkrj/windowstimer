#include "stdafx.h"

#include "WindowsTimer.hpp"

#include <iostream>
#include <cassert>


void testTimerCallback();

int volatile someFlag = 0; // we are using c++89 with MSVC, thus it's as good as an atomic<>


int main(int argc, char** argv)
{
    std::cout << "started (" << WindowsTimer::currTimeStrgSeconds() << ")..." << std::endl;

    WindowsTimer timer;
    timer.setCallback(testTimerCallback);
    bool cyclic = false;

    if (argc > 1)
    {
        std::string timeStrg = argv[1];
        WindowsTimer::HourStringCheckStatus ret = WindowsTimer::checkHourStrgFormat(timeStrg);

        switch (ret) 
        {
        case WindowsTimer::BadFormat:
            std::cout << "ERROR: cannot parse, wrong format" << timeStrg << std::endl;
            return 1;
        case WindowsTimer::BadValue:
            std::cout << "ERROR: wrong time value: " << timeStrg << std::endl;
            return 1;
        case WindowsTimer::FormatOk:
            break;
        default:
            assert(false);
            return 1;
        }

        timer.start(timeStrg, cyclic);
    }
    else
    {
        int secondsToStop = 10;
        std::cout << " - timeout=" << secondsToStop << " [secs]" << std::endl;

        timer.start(secondsToStop, cyclic);
    }

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
