#pragma once
#include <iostream>
#include "shape_drawing_lib/CanvasPainter.h"



// Пространство имен приложения (доступно для модификации)
namespace app
{

	void PaintPicture(shape_drawing_lib::CCanvasPainter & painter);

	void PaintPictureOnCanvas();

	void PaintPictureOnModernGraphicsRenderer();
}