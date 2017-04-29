#include "stdafx.h"
#include "CanvasAdapterPro.h"


namespace app
{

CCanvasAdapterPro::CCanvasAdapterPro(std::ostream & strm)
	: modern_graphics_lib_pro::CModernGraphicsRendererPro(strm)
	, m_x(0)
	, m_y(0)
	, m_color({ 0.f, 0.f, 0.f, 1.f })
{
	BeginDraw();
}

CCanvasAdapterPro::~CCanvasAdapterPro()
{
	EndDraw();
}

void CCanvasAdapterPro::SetColor(uint32_t rgbColor)
{
	auto red = ((rgbColor >> 16) & 0x0000FF) / 255.f;
	auto green = ((rgbColor >> 8) & 0x0000FF) / 255.f;
	auto blue = (rgbColor & 0x0000FF) / 255.f;

	m_color = { red, green, blue, 1.f };
}

void CCanvasAdapterPro::MoveTo(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CCanvasAdapterPro::LineTo(int x, int y)
{
	DrawLine({ m_x, m_y }, { x, y }, m_color);
	MoveTo(x, y);
}

}