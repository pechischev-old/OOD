#pragma once
#include "ICanvasDrawablePro.h"


struct graphics_lib_pro::ICanvas;

namespace shape_drawing_lib_pro
{

class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(const Point & leftTop, int width, int height, uint32_t color);

	void Draw(graphics_lib_pro::ICanvas & canvas)const override;

private:
	Point m_leftTop;
	uint32_t m_color;
	int m_width;
	int m_height;
};
}