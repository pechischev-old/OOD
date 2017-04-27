#include "stdafx.h"
#include "Application.h"

#include "graphics_lib/Canvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"
#include "shape_drawing_lib/Rectangle.h"
#include "shape_drawing_lib/Triangle.h"
#include "CanvasClassAdapter.h"

namespace app 
{
void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
{
	using namespace shape_drawing_lib;

	CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	CCanvasClassAdapter adapter(std::cout);

	shape_drawing_lib::CCanvasPainter painter(adapter);
	PaintPicture(painter);
}
}