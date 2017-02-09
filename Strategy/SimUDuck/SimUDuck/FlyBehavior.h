#pragma once
#include <iostream> 

using namespace std;

struct IFlyBehavior
{
	virtual ~IFlyBehavior() {};
	virtual void Fly() = 0;
protected:
	int m_countDepartures;
};

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		m_countDepartures += 1;
		cout << "I'm flying with wings!! ";
		cout << "It's my " << m_countDepartures << " flight!" << endl;
	}
};

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override {}
};
