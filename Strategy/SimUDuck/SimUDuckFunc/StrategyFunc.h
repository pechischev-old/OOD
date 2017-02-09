#pragma once
#include "stdafx.h"
#include <functional>

using Function = std::function<void()>;


namespace FlyBehavior 
{
	void FlyWithWings()
	{
		std::cout << "I'm flying with wings!! ";
	}

	void FlyNoWay() {}
};

namespace DanceBehavior
{
	void DanceWalts()
	{
		std::cout << "I'm dancing walts" << std::endl;
	}

	void DanceMinuet()
	{
		std::cout << "I'm dancing minuet" << std::endl;
	}

	void NotDance()
	{
		std::cout << "I'm not dancing" << std::endl;
	}
};

namespace QuackBehavior
{
	void Quack()
	{
		std::cout << "Quack Quack!!!" << std::endl;
	}

	void Squeak()
	{
		std::cout << "Squeek!!!" << std::endl;
	}
	void MuteQuack() {}
};