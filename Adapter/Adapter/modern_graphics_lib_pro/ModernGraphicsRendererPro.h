#pragma once
#include <iostream>
#include "RGBAColor.h"

// ѕространство имен обновленной современной графической библиотеки (недоступно дл€ изменени€)
namespace modern_graphics_lib_pro
{

class CPoint
{
public:
	CPoint(int x, int y) :x(x), y(y) {}

	int x;
	int y;
};

//  ласс дл€ современного рисовани€ графики
class CModernGraphicsRendererPro
{
public:
	CModernGraphicsRendererPro(std::ostream & strm);

	~CModernGraphicsRendererPro();

	// Ётот метод должен быть вызван в начале рисовани€
	void BeginDraw();

	// ¬ыполн€ет рисование линии
	void DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color);

	// Ётот метод должен быть вызван в конце рисовани€
	void EndDraw();
private:
	std::ostream & m_out;
	bool m_drawing = false;
};
};