#pragma once
#include "graphics_lib\ICanvas.h"
#include "modern_graphics_lib\ModernGraphicsRenderer.h"

namespace app
{

class CCanvasAdapter : public graphics_lib::ICanvas
{
public:
	CCanvasAdapter(modern_graphics_lib::CModernGraphicsRenderer & renderer);
	~CCanvasAdapter();

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	modern_graphics_lib::CModernGraphicsRenderer & m_renderer;
	int m_x;
	int m_y;
};

}
