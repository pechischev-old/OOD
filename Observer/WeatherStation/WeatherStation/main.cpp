#include "stdafx.h"
#include "Displays.h"



int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display, 1);

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, 2);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(&statsDisplay);

	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);
    return 0;
}

