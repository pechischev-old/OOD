#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include "WeatherData.h"



class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	struct SStatData
	{
		double minMark = std::numeric_limits<double>::infinity();
		double maxMark = -std::numeric_limits<double>::infinity();
		double accMark = 0;
		unsigned countAcc = 0;
	};

	void CalculateStatData(SStatData & statData, double const& mark)
	{
		if (statData.minMark > mark)
		{
			statData.minMark = mark;
		}
		if (statData.maxMark < mark)
		{
			statData.maxMark = mark;
		}
		statData.accMark += mark;
		++statData.countAcc;
	}

	void PrintStatData(SStatData & statData, std::string const & nameMark)
	{
		std::cout << "Max " + nameMark + " " << statData.maxMark << std::endl;
		std::cout << "Min " + nameMark + " " << statData.minMark << std::endl;
		std::cout << "Average " + nameMark + " " << (statData.accMark/ statData.countAcc) << std::endl;
		std::cout << "---" << std::endl;
	}

	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		CalculateStatData(tempData, data.temperature);
		PrintStatData(tempData, "Temp");

		CalculateStatData(humidityData, data.humidity);
		PrintStatData(humidityData, "Humidity");

		CalculateStatData(pressureData, data.pressure);
		PrintStatData(pressureData, "Pressure");

		std::cout << "-------------" << std::endl;
	}

	SStatData tempData;
	SStatData humidityData;
	SStatData pressureData;
};