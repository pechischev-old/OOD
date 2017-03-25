// SimUDuckFunc.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "StrategyFunc.h"

using namespace std;


class Duck
{
public:
	Duck(Function const & fly, Function const & quack, Function const & dance)
		: m_quackBehavior(quack)
		, m_danceBehavior(dance)
		, m_flyBehavior(fly)
	{
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		m_flyBehavior();
	}
	void Dance()
	{
		m_danceBehavior();
	}
	void SetFlyBehavior(Function const & flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	Function m_flyBehavior;
	Function m_quackBehavior;
	Function m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyBehavior::FlyWithWings, QuackBehavior::Quack, DanceBehavior::DanceWalts)
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyBehavior::FlyWithWings(), QuackBehavior::Quack, DanceBehavior::DanceMinuet)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};
class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(FlyBehavior::FlyNoWay, QuackBehavior::MuteQuack, DanceBehavior::NotDance)
	{
	}
	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}
};
class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyBehavior::FlyNoWay, QuackBehavior::Quack, DanceBehavior::NotDance)
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyBehavior::FlyNoWay, QuackBehavior::Quack, DanceBehavior::NotDance)
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
	cout << "----------" << endl;
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	DrawDuck(duck);
}

void FlyFly(Duck & duck)
{
	duck.Fly();
	duck.Fly();
	duck.Fly();
}


void main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	PlayWithDuck(redheadDuck);
	PlayWithDuck(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;

	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	FlyFly(modelDuck);
	PlayWithDuck(modelDuck);
}