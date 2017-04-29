#pragma once
#include "ICanvasDrawablePro.h"


struct graphics_lib_pro::ICanvas;

namespace shape_drawing_lib_pro
{

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const Point & p1, const Point & p2, const Point & p3, uint32_t color);

	void Draw(graphics_lib_pro::ICanvas & canvas)const override;
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
	uint32_t m_color;
};

};