#include "stdafx.h"

#include "CommonTypes.h"
#include "Canvas.h" 
#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Slide.h"
#include "StrokeStyle.h"

int main()
{
	CRectangle rect({ 0, 0, 50, 100 });
	CEllipse ellipse({ 50, 60, 50, 70 }, std::make_shared<CStyle>(false, 0x454545), std::make_shared<CStrokeStyle>(true, 0xFF0000, 1.f));
	CTriangle triangle({ 40, 100, 40, 40 });

	CSlide slide(800, 600);
	slide.InsertShape(std::make_shared<CRectangle>(rect));
	slide.InsertShape(std::make_shared<CEllipse>(ellipse));
	slide.InsertShape(std::make_shared<CTriangle>(triangle));

	CCanvas canvas(std::cout);
	slide.Draw(canvas);
}
