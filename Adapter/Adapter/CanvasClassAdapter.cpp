#include "stdafx.h"
#include "CanvasClassAdapter.h"

namespace app 
{

CCanvasClassAdapter::CCanvasClassAdapter(std::ostream & strm)
	: modern_graphics_lib::CModernGraphicsRenderer(strm)
	, m_x(0)
	, m_y(0)
{
	BeginDraw();
}


CCanvasClassAdapter::~CCanvasClassAdapter()
{
	EndDraw();
}

void CCanvasClassAdapter::MoveTo(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CCanvasClassAdapter::LineTo(int x, int y)
{
	DrawLine({ m_x, m_y }, { x, y });
	MoveTo(x, y);
}

}