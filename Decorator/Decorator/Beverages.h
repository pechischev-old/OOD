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
	CCoffee(const std::string& description = "Coffee")
		: CBeverage(description)
	{}

	double GetCost() const override
	{
		return 60;
	}
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

static std::string const & GetTeaDescription(TeaType type)
{
	std::string description;
	switch (type)
	{
	case TeaType::Green:
		description = "Green";
		break;
	case TeaType::Black:
		description = "Black";
		break;
	case TeaType::Indian:
		description = "Indian";
		break;
	case TeaType::Leaf:
		description = "Leaf";
		break;
	}
	return description;
};

// Чай
class CTea : public CBeverage
{
public:
	CTea(TeaType type)
		:CBeverage(GetTeaDescription(type) + " Tea")
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

static std::string const & GetMilkshakesDescription(ServingSizeMilkshakes type)
{
	std::string description;
	switch (type)
	{
	case ServingSizeMilkshakes::Small:
		description = "Small";
		break;
	case ServingSizeMilkshakes::Medium:
		description = "Medium";
		break;
	case ServingSizeMilkshakes::Big:
		description = "Big";
		break;
	}	return description;
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ServingSizeMilkshakes servingSize)
		:CBeverage(GetMilkshakesDescription(servingSize) + " Milkshake")
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

