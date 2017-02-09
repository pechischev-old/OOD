#pragma once
#include <iostream>

using namespace std;

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0;
};

class DanceWalts : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm dancing walts" << endl;
	}
};

class DanceMinuet : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm dancing minuet" << endl;
	}
};

class NotDance : public IDanceBehavior
{
public:
	void Dance() override
	{
		cout << "I'm not dancing" << endl;
	}
};