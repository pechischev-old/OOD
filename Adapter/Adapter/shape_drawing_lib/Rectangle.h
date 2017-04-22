#pragma once
#include "Point.h"
#include "ICanvasDrawable.h"


struct graphics_lib::ICanvas;

namespace shape_drawing_lib
{

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point & leftTop, int width, int height);

	void Draw(graphics_lib::ICanvas & canvas)const override;
private:
	// TODO: дописать приватную часть 
};
};