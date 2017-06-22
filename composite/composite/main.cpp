#include "stdafx.h"

#include "CommonTypes.h"
#include "Canvas.h" 
#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Slide.h"
#include "StrokeStyle.h"
#include "Group.h"

int main()
{
	CRectangle rect({ 0, 0, 50, 100 }, std::make_shared<CStyle>(true, 0x454545), std::make_shared<CStrokeStyle>(true, 0xFF0000, 1.f));
	CEllipse ellipse({ 50, 60, 50, 70 }, std::make_shared<CStyle>(true, 0x454545), std::make_shared<CStrokeStyle>(true, 0xFF0000, 1.f));
	CTriangle triangle({ 40, 100, 40, 40 });

	CGroup group;
	group.InsertShape(std::make_shared<CRectangle>(rect));
	group.InsertShape(std::make_shared<CTriangle>(triangle));

	group.SetFrame({100, 110, 90, 80});

	CSlide slide(800, 600);
	slide.AddShape(std::make_shared<CRectangle>(rect));
	slide.AddShape(std::make_shared<CEllipse>(ellipse));
	slide.AddShape(std::make_shared<CTriangle>(triangle));
	slide.AddShape(std::make_shared<CGroup>(group));


	CCanvas canvas(std::cout);
	slide.Draw(canvas);
}
