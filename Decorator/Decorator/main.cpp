#include "Beverages.h"
#include "Condiments.h"

#include <iostream>
#include <string>
#include <functional>

using namespace std;


/*
�������������� ������, ��������� �������� �������
*/
struct MakeLemon
{
	MakeLemon(unsigned quantity)
		:m_quantity(quantity)
	{}

	auto operator()(IBeveragePtr && beverage)const
	{
		return make_unique<CLemon>(move(beverage), m_quantity);
	}
private:
	unsigned m_quantity;
};

/*
�������, ������������ �������, ��������� �������� �������
*/
function<IBeveragePtr(IBeveragePtr &&)> MakeCinnamon()
{
	return [](IBeveragePtr && b) {
		return make_unique<CCinnamon>(move(b));
	};
}

/*
���������� �������, ������������ ������� ������������ ��������
��������� �������:
Condiment - ����� �������, ����������� �������� � �������� ������� ���������
��������� IBeveragePtr&& �������������� �������
Args - ������ ����� ������ ���������� ������������ (��������, ������)
*/
template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&...args)
{
	// ���������� �������, ������������ �������, ���������� �� � �������� ���������
	// �������������� ��������� ����������, ����������� ������-��������, ����������
	// ������������ ���������� ����� make_unique
	return [=](auto && b) {
		// ������� make_unique �������� b ������ �� ������� ���������� ������� �������
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

/*
������������� ������ ��������� <<, ������� ������������� ��� �������������� �����
��� ������������� ����������
��������� ������� ������� ������������� ������� ����������� ��������� �������:
auto beverage = make_unique<CConcreteBeverage>(a, b, c)
<< MakeCondimentA(d, e, f)
<< MakeCondimentB(g, h);
�������������� ������� MakeCondiment* ���������� ���������, ����������� ��� ��������
����������, � ���������� ��������� �������, ����������� ������������� �������, �������
��� ����� ������ ������� ������ ������ Condiment, ������� ��� ����������� ���������.
�������������:
auto beverage =
make_unique<CConcreteBeverage>(a, b, c)
<< MakeCondimentA(d, e, f)
<< MakeCondimentB(g, h);
��� ���� ���:
auto beverage =
make_unique<CConcreteBeverage>
<< MakeCondiment<CondimentA>(d, e, f)
<< MakeCondiment<CondimentB>(g, h);
� ��������� ������ ��� ������������� ������ ������� ���������� MakeCondimentA � MakeCondimentB, �.�.
����������� ���������� ����������� ����������
������������ ������ ������������ �������� �� ���:
auto baseBeverage = make_unique<CConcretedBeverage>(a, b, c);
auto wrappedWithCondimentA = make_unique<CCondimentA>(move(baseBeverage), d, e, f);
auto beverage = make_unique<CCondimentB>(move(wrappedWithCondimentA), g, h);
���� ���:
auto beverage = make_unique<CCondimentB>(
make_unique<CCondimentA>(
make_unique<CConcreteBeverage>(a, b, c), // �������
d, e, f	// ���. �������� CondimentA
),
g, h		// ���. ��������� CondimentB
);
unique_ptr<CLemon> operator << (IBeveragePtr && lhs, const MakeLemon & factory)
{
return factory(move(lhs));
}
unique_ptr<CCinnamon> operator << (IBeveragePtr && lhs, const MakeCinnamon & factory)
{
return factory(move(lhs));
}
*/
template <typename Component, typename Decorator>
auto operator << (Component && component, const Decorator & decorate)
{
	return decorate(forward<Component>(component));
}


int main()
{
	{
		// �������� ������� �����
		auto latte = make_unique<CLatte>(PortionType::Twin);
		// ��������� ������
		auto cinnamon = make_unique<CCinnamon>(move(latte));
		// ��������� ���� ����� ������
		auto lemon = make_unique<CLemon>(move(cinnamon), 2);
		// ��������� ���� ������� ����
		auto iceCubes = make_unique<CIceCubes>(move(lemon), 2, IceCubeType::Dry);
		// ��������� 2 ������ ���������� ������
		auto beverage = make_unique<CChocolateCrumbs>(move(iceCubes), 2);

		// ���������� ���� ����������
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CChocolateCrumbs>(			// ������� ����: ���������� ������
				make_unique<CIceCubes>(				// | ��� ��� - ������ ����
					make_unique<CLemon>(			// | | ��� ���� �����
						make_unique<CCinnamon>(		// | | | ����� ���� - ������
							make_unique<CLatte>(PortionType::Standard)),	// | | |   � ����� ������ - �����
						2),							// | | 2 ������ ������
					2, IceCubeType::Dry),			// | 2 ������ ������ ����
				2);									// 2 ������ ���������� ������

													// ���������� ���� ����������
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	// ��������� ���������� ������ MakeCondiment � ��������� <<
	{
		// lemon - �������, ����������� "2 ������ ������" � ������ �������
		auto lemon2 = MakeCondiment<CLemon>(2);
		// iceCubes - �������, ����������� "3 ������� ����" � ������ �������
		auto iceCubes3 = MakeCondiment<CIceCubes>(3, IceCubeType::Water);

		auto tea = make_unique<CTea>(TeaType::Green);

		// ���������� ��� ����� �������� ������ � ����� ��������� ����
		auto lemonIceTea = iceCubes3(lemon2(move(tea)));
		/* ���������� ������ ��������� �� �� ��������, ��� � ��������� ���:
		auto lemonIceTea =
		make_unique<CIceCubes>(
		make_unique<CLemon>(
		move(tea),
		2),
		2, IceCubeType::Water);
		*/

		auto oneMoreLemonIceTea =
			make_unique<CTea>(TeaType::Black)	// ����� ���
			<< MakeCondiment<CLemon>(2)	// ��������� ���� ����� ������
			<< MakeCondiment<CIceCubes>(3, IceCubeType::Water); // � 3 ������ ����
																/*
																���������� ����������� ������ �� �� �����, ��� � ���������:
																auto oneMoreLemonIceTea =
																MakeCondiment<CIceCubes>(3, IceCubeType::Water)(
																MakeCondiment<CLemon>(2)(make_unique<CTea>())
																);
																*/
	}

	// ������ ����������� ������� � �������� ��������������� ������
	// ��������������� ����������� << � �������� MakeCondiment
	{
		auto beverage =
			make_unique<CLatte>(PortionType::Standard)					// �������� ������� �����,
			<< MakeCondiment<CCinnamon>()					// ����������� �������,
			<< MakeCondiment<CLemon>(2)						// ��������� ���� ����� ������
			<< MakeCondiment<CIceCubes>(2, IceCubeType::Dry)// ������� ���� ������� ������ ����
			<< MakeCondiment<CChocolateCrumbs>(2);			// �������� ���������� �������

															// ���������� ���� ����������
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}

	{
		auto beverage =
			make_unique<CMilkshake>(ServingSizeMilkshakes::Medium)					// �������� �������� ��������
			<< MakeCondiment<CSyrup>(SyrupType::Maple)	// �������� �������� �������
			<< MakeCondiment<CCoconutFlakes>(8);		// �������� ��������� ��������

														// ���������� ���� ����������
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
	{
		auto beverage =
			make_unique<CMilkshake>(ServingSizeMilkshakes::Small)					// �������� �������� ��������
			<< MakeCondiment<CChocolate>(6)				// ��������� ���������� ������
			<< MakeCondiment<CLiqueur>(LiqueurType::Walnut);		// �������� �������� �����

														// ���������� ���� ����������
		cout << beverage->GetDescription() << " costs " << beverage->GetCost() << endl;
	}
}