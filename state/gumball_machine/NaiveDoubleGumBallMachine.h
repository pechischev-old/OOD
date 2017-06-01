#pragma once

#include <iostream>
#include <boost/format.hpp>

namespace naive
{
class CDoubleGumballMachine
{
public:
	enum class State
	{
		SoldOut,		// Жвачка закончилась
		NoQuarter,		// Нет монетки
		HasQuarter,		// Есть монетка
		Sold,			// Монетка выдана
	};

	CDoubleGumballMachine(unsigned count)
		: m_ballCount(count)
		, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
		, m_coins(0)
	{
	}

	void InsertQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You can't insert a quarter, the machine is sold out\n";
			break;
		case State::NoQuarter:
			cout << "You inserted a quarter\n";
			m_state = State::HasQuarter;
			AddCoin();
			break;
		case State::HasQuarter:
			AddCoin();
			break;
		case State::Sold:
			cout << "Please wait, we're already giving you a gumball\n";
			break;
		}
	}

	void EjectQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::HasQuarter:
			cout << "Quarter returned\n";
			ReturnCoins();
			m_state = State::NoQuarter;
			break;
		case State::NoQuarter:
			cout << "You haven't inserted a quarter\n";
			break;
		case State::Sold:
			cout << "Sorry you already turned the crank\n";
			break;
		case State::SoldOut:
			if (GetCoinsCount() == 0)
			{
				std::cout << "You can't eject, you haven't inserted a quarter yet\n";
			}
			else
			{
				ReturnCoins();
				m_state = State::NoQuarter;
			}
			break;
		}
	}

	void TurnCrank()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You turned but there's no gumballs\n";
			break;
		case State::NoQuarter:
			cout << "You turned but there's no quarter\n";
			break;
		case State::HasQuarter:
			cout << "You turned...\n";
			m_state = State::Sold;
			UseCoin();
			Dispense();
			break;
		case State::Sold:
			cout << "Turning twice doesn't get you another gumball\n";
			break;
		}
	}

	void Refill(unsigned numBalls)
	{
		m_ballCount = numBalls;
		m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
	}

	std::string ToString()const
	{
		std::string state =
			(m_state == State::SoldOut)    ? "sold out" :
			(m_state == State::NoQuarter)  ? "waiting for quarter" :
			(m_state == State::HasQuarter) ? "waiting for turn of crank"
			                               : "delivering a gumball";
		auto fmt = boost::format(R"(
Mighty Gumball, Inc.
C++-enabled Standing Gumball Model #2016
Inventory: %1% gumball%2%
Machine is %3%
)");
		return (fmt % m_ballCount % (m_ballCount != 1 ? "s" : "") % state).str();
	}

private:
	void Dispense()
	{
		using namespace std;
		switch (m_state)
		{
		case State::Sold:
			cout << "A gumball comes rolling out the slot\n";
			--m_ballCount;
			if (m_ballCount == 0)
			{
				cout << "Oops, out of gumballs\n";
				m_state = State::SoldOut;
			}
			else
			{
				m_state = State::NoQuarter;
			}
			break;
		case State::NoQuarter:
			cout << "You need to pay first\n";
			break;
		case State::SoldOut:
		case State::HasQuarter:
			cout << "No gumball dispensed\n";
			break;
		}
	}

	unsigned GetBallCount() const 
	{
		return m_ballCount;
	}

	unsigned GetCoinsCount()const
	{
		return m_coins;
	}

	void ReleaseBall()
	{
		if (m_ballCount != 0)
		{
			std::cout << "A gumball comes rolling out the slot...\n";
			--m_ballCount;
		}
	}
	void AddCoin()
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
	void UseCoin()
	{
		if (m_coins != 0)
		{
			--m_coins;
		}
	}
	void ReturnCoins()
	{
		std::cout << boost::format(R"(%1% coin%2% returned)") % m_coins % (m_coins != 1 ? "s" : "") << std::endl;
		m_coins = 0;
	}


	unsigned m_ballCount;	// Количество шариков
	unsigned m_coins;
	State m_state = State::SoldOut;
};
}