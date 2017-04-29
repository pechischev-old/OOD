#include "../stdafx.h"
#include "RectanglePro.h"

#include "../graphics_lib_pro/ICanvasPro.h"


namespace shape_drawing_lib_pro
{

CRectangle::CRectangle(const Point & leftTop, int width, int height, uint32_t color)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_color(color)
{
}

void CRectangle::Draw(graphics_lib_pro::ICanvas & canvas)const
{
	int x = m_leftTop.x;
	int y = m_leftTop.y;
	canvas.SetColor(m_color);
	canvas.MoveTo(x, y);
	canvas.LineTo(x + m_width, y);
	canvas.LineTo(x + m_width, y + m_height);
	canvas.LineTo(x, y + m_height);
	canvas.LineTo(x, y);
}
	
}