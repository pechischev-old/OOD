#include "../stdafx.h"
#include "ModernGraphicsRendererPro.h"


// ѕространство имен обновленной современной графической библиотеки (недоступно дл€ изменени€)
namespace modern_graphics_lib_pro
{

	
CModernGraphicsRendererPro::CModernGraphicsRendererPro(std::ostream & strm)
	: m_out(strm)
{
}

CModernGraphicsRendererPro::~CModernGraphicsRendererPro()
{
	if (m_drawing) // «авершаем рисование, если оно было начато
	{
		EndDraw();
	}
}

// Ётот метод должен быть вызван в начале рисовани€
void CModernGraphicsRendererPro::BeginDraw()
{
	if (m_drawing)
	{
		throw std::logic_error("Drawing has already begun");
	}
	m_out << "<draw>" << std::endl;
	m_drawing = true;
}

// ¬ыполн€ет рисование линии
void CModernGraphicsRendererPro::DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color)
{
	if (!m_drawing)
	{
		throw std::logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
	}
	m_out << boost::format(R"(  <line fromX="%1%" fromY="%2%" toX="%3%" toY="%4%">)") % start.x % start.y % end.x % end.y << std::endl;
	m_out << boost::format(R"(  \t<color r="%1%" g="%2%" b="%3%" a="%4%"/>)") % color.a % color.g % color.b % color.a << std::endl;
	m_out << R"(  </line>)" << std::endl;
}

// Ётот метод должен быть вызван в конце рисовани€
void CModernGraphicsRendererPro::EndDraw()
{
	if (!m_drawing)
	{
		throw std::logic_error("Drawing has not been started");
	}
	m_out << "</draw>" << std::endl;
	m_drawing = false;
}
};
