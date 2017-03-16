// Factory.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Designer.h"
#include "Painter.h"
#include "ShapeFactory.h"
#include "Client.h"

using namespace std;

int main()
{
	CShapeFactory factory;
	CDesigner designer(factory);
	CPainter painter;

	CClient client(make_unique<CPainter>(), make_unique<CDesigner>(factory));
	client.MakePictureOrder();

    return 0;
}

