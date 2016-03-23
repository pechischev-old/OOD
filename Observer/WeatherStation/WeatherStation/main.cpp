#include "stdafx.h"
#include "Displays.h"



int main()
{
	CWeatherData in("Room");
	CWeatherData out("Outside");

	CDisplay display;
	in.RegisterObserver(display, 1);
	out.RegisterObserver(display, 5);

	CStatsDisplay statsDisplay;
	in.RegisterObserver(statsDisplay, 2);
	out.RegisterObserver(statsDisplay, 2);

	in.SetMeasurements(3, 0.7, 760);
	in.SetMeasurements(4, 0.8, 761);

	out.SetMeasurements(5, 1.0, 758);	
	out.SetMeasurements(2, 0.9, 757);

	in.RemoveObserver(&statsDisplay);
	out.RemoveObserver(&statsDisplay);

	in.SetMeasurements(10, 0.8, 761);
	in.SetMeasurements(-10, 0.8, 761);
    return 0;
}

