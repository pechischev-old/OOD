#pragma once

// ѕространство имен обновленной современной графической библиотеки (недоступно дл€ изменени€)
namespace modern_graphics_lib_pro
{

	// ÷вет в формате RGBA, каждый компонент принимает значени€ от 0.0f до 1.0f
	class CRGBAColor
	{
	public:
		CRGBAColor(float r, float g, float b, float a) :r(r), g(g), b(b), a(a) {}
		float r, g, b, a;
	};
};