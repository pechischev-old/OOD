#pragma once
#include <sstream>
#include "graphics_lib\ICanvas.h"
#include "modern_graphics_lib\ModernGraphicsRenderer.h"

namespace app 
{

class CCanvasClassAdapter 
	: public graphics_lib::ICanvas
	, private modern_graphics_lib::CModernGraphicsRenderer
{
public:
	CCanvasClassAdapter(std::ostream & strm);
	~CCanvasClassAdapter();

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	int m_x;
	int m_y;
};
}


