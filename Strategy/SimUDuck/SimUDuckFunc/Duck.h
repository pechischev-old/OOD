#pragma once
#include "stdafx.h"

class Duck
{
public:
	Duck(std::unique_ptr<IFlyBehavior> && flyBehavior, std::unique_ptr<IQuackBehavior> && quackBehavior, std::unique_ptr<IDanceBehavior> && danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
		, m_danceBehavior(std::move(danceBehavior))
		, m_flyBehavior(std::move(flyBehavior))
	{
		assert(m_quackBehavior);
		assert(m_danceBehavior);
		assert(m_flyBehavior);
	}
	void Quack() const
	{
		m_quackBehavior->Quack();
	}
	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}
	void Fly()
	{
		m_flyBehavior->Fly();
	}
	virtual void Dance()
	{
		m_danceBehavior->Dance();
	}
	void SetFlyBehavior(std::unique_ptr<IFlyBehavior> && flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}
	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>(), std::make_unique<DanceWalts>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(std::make_unique<FlyWithWings>(), std::make_unique<QuackBehavior>(), std::make_unique<DanceMinuet>())
	{
	}
	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};
class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(std::make_unique<FlyNoWay>(), std::make_unique<MuteQuackBehavior>(), std::make_unique<NotDance>())
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
		: Duck(make_unique<FlyNoWay>(), make_unique<QuackBehavior>(), make_unique<NotDance>())
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
		: Duck(make_unique<FlyNoWay>(), make_unique<QuackBehavior>(), make_unique<NotDance>())
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
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;

	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);

	modelDuck.SetFlyBehavior(make_unique<FlyWithWings>());
	FlyFly(modelDuck);
	PlayWithDuck(modelDuck);
}
