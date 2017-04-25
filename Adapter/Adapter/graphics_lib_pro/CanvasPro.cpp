#include "../stdafx.h"
#include "CanvasPro.h"

#include <iostream>

namespace graphics_lib_pro
{

	void CCanvasPro::SetColor(uint32_t rgbColor)
	{
		std::cout << "SetColor " << "(#" << rgbColor << ")" << std::endl;
	}
	void CCanvasPro::MoveTo(int x, int y)
	{
		std::cout << "moveTo " << x << " " << y << std::endl;
	}
	void CCanvasPro::LineTo(int x, int y)
	{
		std::cout << "LineTo " << x << " " << y << std::endl;
	}
};