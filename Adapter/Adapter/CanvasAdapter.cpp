#include "stdafx.h"
#include "CanvasAdapter.h"


namespace app 
{

CCanvasAdapter::CCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer & renderer)
	: m_renderer(renderer)
	, m_x(0)
	, m_y(0)
{
	m_renderer.BeginDraw();
}

CCanvasAdapter::~CCanvasAdapter()
{
	m_renderer.EndDraw();
}

void CCanvasAdapter::MoveTo(int x, int y)
{
	m_x = x;
	m_y = y;
}

void CCanvasAdapter::LineTo(int x, int y)
{
	m_renderer.DrawLine({ m_x, m_y }, { x, y });
	MoveTo(x, y);
}

}