// Factory.cpp: определяет точку входа для консольного приложения.
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

	CClient client(painter, designer);
	client.DrawPicture(cin);
    return 0;
}

