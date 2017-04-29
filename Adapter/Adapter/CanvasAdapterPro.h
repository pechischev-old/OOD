#pragma once
#include <iostream>
#include "graphics_lib_pro\ICanvasPro.h"
#include "modern_graphics_lib_pro\ModernGraphicsRendererPro.h"
#include "modern_graphics_lib_pro\RGBAColor.h"

namespace app
{

class CCanvasAdapterPro 
	: public graphics_lib_pro::ICanvas
	, private modern_graphics_lib_pro::CModernGraphicsRendererPro
{
public:
	CCanvasAdapterPro(std::ostream & strm);
	~CCanvasAdapterPro();

	void SetColor(uint32_t rgbColor) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
private:
	modern_graphics_lib_pro::CRGBAColor m_color;
	int m_x;
	int m_y;
};
}