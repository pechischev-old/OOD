// Factory.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Designer.h"
#include "PictureDraft.h"
#include "Painter.h"
#include "ShapeFactory.h"
#include "Canvas.h"


int main()
{
	CShapeFactory factory;
	CDesigner designer(factory);
	CPainter painter;
	CCanvas canvas(std::cout);
	
	auto draft = designer.CreateDraft(std::cin);

	painter.DrawPicture(draft, canvas);

    return 0;
}

