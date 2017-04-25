#pragma once
#include "../graphics_lib/ICanvas.h"



namespace shape_drawing_lib
{

class ICanvasDrawable;

class CCanvasPainter
{
public:
	CCanvasPainter(graphics_lib::ICanvas & canvas);
	void Draw(const ICanvasDrawable & drawable);

private:
	// TODO: дописать приватную часть
	graphics_lib::ICanvas & m_canvas;
};
};