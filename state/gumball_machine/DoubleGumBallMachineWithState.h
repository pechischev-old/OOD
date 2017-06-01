#pragma once
#include <iostream>
#include <memory>

namespace with_state
{

struct IState
{
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;
	virtual void Refill(unsigned numBalls) = 0;
	virtual std::string ToString()const = 0;
	virtual ~IState() = default;
};

struct IDoubleGumballMachine
{
	virtual void ReleaseBall() = 0;
	virtual unsigned GetBallCount()const = 0;
	virtual unsigned GetCoinsCount()const = 0;

	virtual void AddBalls(unsigned numBalls) = 0;
	virtual void AddCoin() = 0;
	virtual void UseCoin() = 0;
	virtual void ReturnCoins() = 0;

	virtual void Refill(unsigned numBalls) = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual ~IDoubleGumballMachine() = default;
};

class CSoldState : public IState
{
public:
	CSoldState(IDoubleGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}
	void InsertQuarter() override
	{
		std::cout << "Please wait, we're already giving you a gumball\n";
	}
	void EjectQuarter() override
	{
		std::cout << "Sorry you already turned the crank\n";
	}
	void TurnCrank() override
	{
		std::cout << "Turning twice doesn't get you another gumball\n";
	}
	void Dispense() override
	{
		m_gumballMachine.ReleaseBall();
		if (m_gumballMachine.GetBallCount() == 0)
		{
			std::cout << "Oops, out of gumballs\n";
			m_gumballMachine.SetSoldOutState();
		}
		else
		{
			m_gumballMachine.SetNoQuarterState();
		}
	}
	void Refill(unsigned numBall) override
	{
		m_gumballMachine.AddBalls(numBall);
	}
	std::string ToString() const override
	{
		return "delivering a gumball";
	}
private:
	IDoubleGumballMachine & m_gumballMachine;
};

class CSoldOutState : public IState
{
public:
	CSoldOutState(IDoubleGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		std::cout << "You can't insert a quarter, the machine is sold out\n";
	}
	void EjectQuarter() override
	{
		if (m_gumballMachine.GetCoinsCount() == 0)
		{
			std::cout << "You can't eject, you haven't inserted a quarter yet\n";
		}
		else
		{
			m_gumballMachine.ReturnCoins();
			m_gumballMachine.SetNoQuarterState();
		}
	}
	void TurnCrank() override
	{
		std::cout << "You turned but there's no gumballs\n";
	}
	void Dispense() override
	{
		std::cout << "No gumball dispensed\n";
	}
	std::string ToString() const override
	{
		return "sold out";
	}

	void Refill(unsigned numBall) override
	{
		m_gumballMachine.AddBalls(numBall);
		if (m_gumballMachine.GetBallCount() == 0)
		{
			return;
		}
		if (m_gumballMachine.GetCoinsCount() > 0)
		{
			m_gumballMachine.SetHasQuarterState();
		}
		else
		{
			m_gumballMachine.SetNoQuarterState();
		}
	}
private:
	IDoubleGumballMachine & m_gumballMachine;
};

class CHasQuarterState : public IState
{
public:
	CHasQuarterState(IDoubleGumballMachine & gumballMachine)
		:m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		m_gumballMachine.AddCoin();
	}
	void EjectQuarter() override
	{
		m_gumballMachine.ReturnCoins();
		m_gumballMachine.SetNoQuarterState();
	}
	void TurnCrank() override
	{
		std::cout << "You turned...\n";
		m_gumballMachine.UseCoin();
		m_gumballMachine.SetSoldState();
	}
	void Dispense() override
	{
		std::cout << "No gumball dispensed\n";
	}
	std::string ToString() const override
	{
		return "waiting for turn of crank";
	}
	void Refill(unsigned numBall) override
	{
		m_gumballMachine.AddBalls(numBall);
	}
private:
	IDoubleGumballMachine & m_gumballMachine;
};

class CNoQuarterState : public IState
{
public:
	CNoQuarterState(IDoubleGumballMachine & gumballMachine)
		: m_gumballMachine(gumballMachine)
	{}

	void InsertQuarter() override
	{
		m_gumballMachine.AddCoin();
		m_gumballMachine.SetHasQuarterState();	
	}
	void EjectQuarter() override
	{
		std::cout << "You haven't inserted a quarter\n";
	}
	void TurnCrank() override
	{
		std::cout << "You turned but there's no quarter\n";
	}
	void Dispense() override
	{
		std::cout << "You need to pay first\n";
	}
	void Refill(unsigned numBall) override
	{
		m_gumballMachine.AddBalls(numBall);
	}
	std::string ToString() const override
	{
		return "waiting for quarter";
	}
private:
	IDoubleGumballMachine & m_gumballMachine;
};

class CDoubleGumballMachine : private IDoubleGumballMachine
{
public:
	CDoubleGumballMachine(unsigned numBalls)
		: m_ballCount(numBalls)
		, m_coins(0)
	{
		if (m_ballCount > 0)
		{
			SetNoQuarterState();
		}
		else
		{
			SetSoldOutState();
		}
	}
	void EjectQuarter()
	{
		m_state->EjectQuarter();
	}
	void InsertQuarter()
	{
		m_state->InsertQuarter();
	}
	void TurnCrank()
	{
		m_state->TurnCrank();
		m_state->Dispense();
	}
	std::string ToString()const
	{
		auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016 (with state)
Inventory: %1% gumball%2%
Machine is %3%
)");
		return (fmt % m_ballCount % (m_ballCount != 1 ? "s" : "") % m_state->ToString()).str();
	}
private:
	unsigned GetBallCount() const override
	{
		return m_ballCount;
	}

	unsigned GetCoinsCount()const override
	{
		return m_coins;
	}

	void ReleaseBall() override
	{
		if (m_ballCount != 0)
		{
			std::cout << "A gumball comes rolling out the slot...\n";
			--m_ballCount;
		}
	}

	void AddCoin() override 
	{
		if (m_coins > 5)
		{
			++m_coins;
			std::cout << "You added a coin" << std::endl;
		}
		else
		{
			std::cout << "Can't add more than 5 coins" << std::endl;
		}
	}

	void AddBalls(unsigned numBalls) override
	{
		m_ballCount += numBalls;
	}

	void UseCoin() override
	{
		if (m_coins != 0)
		{
			--m_coins;
		}
	}

	void ReturnCoins() override
	{
		std::cout << boost::format(R"(%1% coin%2% returned)") % m_coins % (m_coins != 1 ? "s" : "") << std::endl;
		m_coins = 0;
	}

	void Refill(unsigned numBall) override
	{
		m_state->Refill(numBall);
	}

	void SetSoldOutState() override
	{
		m_state.reset(new CSoldOutState(*this));
	}
	void SetNoQuarterState() override
	{
		m_state.reset(new CNoQuarterState(*this));
	}
	void SetSoldState() override
	{
		m_state.reset(new CSoldState(*this));
	}
	void SetHasQuarterState() override
	{
		m_state.reset(new CHasQuarterState(*this));
	}
private:
	unsigned m_ballCount = 0;
	unsigned m_coins = 0;
	std::unique_ptr<IState> m_state;
};

}
