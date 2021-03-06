#include "stdafx.h"
#include "Canvas.h"
#include <boost/format.hpp>


namespace CanvasUtils
{
	std::string ConvertUint32ToRGB(uint32_t color)
	{
		auto red = ((color >> 16) & 0x0000FF);
		auto green = ((color >> 8) & 0x0000FF);
		auto blue = (color & 0x0000FF);
		
		return (boost::format(R"(rgb(%1%, %2%, %3%))") % red % green % blue).str();
	}
}

CCanvas::CCanvas(std::ostream & stream)
	: m_stream(stream)
	, m_outlineColor(0xFF0000)
	, m_fillColor(0xFFFFFF)
	, m_x(0.0)
	, m_y(0.0)
	, m_thickness(0.f)
	, m_isFilling(false)
{
	m_stream << "<svg xmlns='http://www.w3.org/2000/svg'>" << std::endl;
}

CCanvas::~CCanvas()
{
	m_stream << "</svg>" << std::endl;
}

void CCanvas::SetLineColor(RGBAColor color)
{
	m_outlineColor = color;
}

void CCanvas::BeginFill(RGBAColor color)
{
	m_fillColor = color; 

	if (m_isFilling)
	{
		throw std::logic_error("filling shape");
	}
	m_isFilling = true;

}

void CCanvas::EndFill()
{
	if (m_isFilling)
	{
		
		auto fillColorRGB = CanvasUtils::ConvertUint32ToRGB(m_fillColor);

		m_isFilling = false;

		std::string polygonStr = "   <polygon points=\"";
		std::for_each(m_filledPoints.begin(), m_filledPoints.end(), [&](auto point) {
			polygonStr += (boost::format(R"(%1$.2f %2$.2f )") % point.first % point.second).str();
		});
		polygonStr += (boost::format(R"(" fill="%1%"/>)") % fillColorRGB).str();
		m_stream << polygonStr << std::endl;

		m_filledPoints.clear();
	}
}

void CCanvas::MoveTo(double x, double y)
{
	m_x = x;
	m_y = y;
	if (m_isFilling)
	{
		m_filledPoints.push_back(std::pair<double, double>(x, y));
	}
}

void CCanvas::LineTo(double x, double y)
{
	auto lineColorRGB = CanvasUtils::ConvertUint32ToRGB(m_outlineColor);
	m_stream << boost::format(R"(  <line x1="%1%" y1="%2%" x2="%3%" y2="%4%" stroke-width="%5$.2f" stroke="%6%"/>)")
		% m_x % m_y % x % y % m_thickness % lineColorRGB << std::endl;
	MoveTo(x, y);
}

void CCanvas::DrawEllipse(double left, double top, double width, double height)
{
	auto lineColorRGB = CanvasUtils::ConvertUint32ToRGB(m_outlineColor);
	auto fillColorRGB = CanvasUtils::ConvertUint32ToRGB(m_fillColor);
	
	m_stream << boost::format(R"(  <ellipse cx="%1%" cy="%2%" rx="%3%" ry="%4%" stroke-width="%5$.2f" fill="%6%" stroke="%7%"/>)")
		% left % top % width % height % m_thickness % fillColorRGB % lineColorRGB << std::endl;

}

void CCanvas::SetLineThickness(float thickness)
{
	m_thickness = thickness;
}
