#pragma once

#include "IBeverage.h"

// ������� ���������� �������, ��������������� ��� ��������
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// ����
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description)
	{}

	double GetCost() const override
	{
		return 60;
	}
};

// ���������
class CCapuccino : public CCoffee
{
public:
	CCapuccino()
		:CCoffee("Capuccino")
	{}

	double GetCost() const override
	{
		return 80;
	}
};

// �����
class CLatte : public CCoffee
{
public:
	CLatte()
		:CCoffee("Latte")
	{}

	double GetCost() const override
	{
		return 90;
	}
};

// ���
class CTea : public CBeverage
{
public:
	CTea()
		:CBeverage("Tea")
	{}

	double GetCost() const override
	{
		return 30;
	}
};

// �������� ��������
class CMilkshake : public CBeverage
{
public:
	CMilkshake()
		:CBeverage("Milkshake")
	{}

	double GetCost() const override
	{
		return 80;
	}
};