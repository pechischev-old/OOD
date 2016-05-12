#pragma once
#include <map>

#include "IBeverage.h"


// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		: m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};


enum class PortionType
{
	Standard,
	Twin
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee", PortionType type = PortionType::Standard)
		: CBeverage(description)
		, m_type(type)
	{}

	double GetCost() const override
	{
		return 60;
	}
private:
	PortionType m_type;
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino(PortionType type)
		: CCoffee(m_type == PortionType::Standard ? "Capuccino" : "Double Capuccino")
		, m_type(type)
	{}

	double GetCost() const override
	{
		return (m_type == PortionType::Standard ? 80 : 120);
	}
private:
	PortionType m_type;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(PortionType type)
		: CCoffee(m_type == PortionType::Standard ? "Latte" : "Double Latte")
		, m_type(type)
	{}

	double GetCost() const override
	{
		return (m_type == PortionType::Standard ? 90 : 130);
	}
private:
	PortionType m_type;
};


enum class TeaType
{
	Green,
	Black,
	Indian,
	Leaf
};

static const std::map<TeaType, std::string> TEA_TYPE
{
	{ TeaType::Green, "Green"},
	{ TeaType::Black, "Black" },
	{ TeaType::Indian, "Indian" },
	{ TeaType::Leaf, "Leaf" }
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType type)
		:CBeverage(TEA_TYPE.find(type)->second + " Tea")
		, m_type(type)
	{}

	double GetCost() const override
	{
		return 8;
	}
private:
	TeaType m_type;
};


enum class ServingSizeMilkshakes
{
	Small,
	Medium,
	Big
};

static const std::map<ServingSizeMilkshakes, std::string> SERVING_SIZE
	{ {ServingSizeMilkshakes::Small, "Small"},
	{ ServingSizeMilkshakes::Medium, "Medium" },
	{ ServingSizeMilkshakes::Big, "Big" } };

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ServingSizeMilkshakes servingSize)
		:CBeverage(SERVING_SIZE.find(servingSize)->second + " Milkshake")
		, m_servingSize(servingSize)
	{}

	double GetCost() const override
	{
		switch (m_servingSize)
		{
		case ServingSizeMilkshakes::Big:
			return 80;
		case ServingSizeMilkshakes::Medium:
			return 60;
		case ServingSizeMilkshakes::Small:
			return 50;
		default:
			return 0;
		}
		
	}
private:
	ServingSizeMilkshakes m_servingSize;
};

