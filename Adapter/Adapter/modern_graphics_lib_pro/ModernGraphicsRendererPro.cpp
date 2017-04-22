#include "../stdafx.h"
#include "ModernGraphicsRendererPro.h"


// Пространство имен обновленной современной графической библиотеки (недоступно для изменения)
namespace modern_graphics_lib_pro
{

	
	CModernGraphicsRendererPro::CModernGraphicsRendererPro(std::ostream & strm)
	: m_out(strm)
{
}

	CModernGraphicsRendererPro::~CModernGraphicsRendererPro()
{
	// Реализация остается без изменения
}

// Этот метод должен быть вызван в начале рисования
void CModernGraphicsRendererPro::BeginDraw()
{
	// Реализация остается без изменения
}

// Выполняет рисование линии
void CModernGraphicsRendererPro::DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color)
{
	// TODO: выводит в output инструкцию для рисования линии в виде
	// <line fromX="3" fromY="5" toX="5" toY="17">
	//   <color r="0.35" g="0.47" b="1.0" a="1.0" />
	// </line>
	// Можно вызывать только между BeginDraw() и EndDraw()
}

// Этот метод должен быть вызван в конце рисования
void CModernGraphicsRendererPro::EndDraw()
{
	// Реализация остается без изменения
}
};
