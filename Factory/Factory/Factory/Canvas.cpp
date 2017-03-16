#include "stdafx.h"
#include "Canvas.h"

namespace 
{
	std::string const GetColor(Color type)
	{
		switch (type)
		{
		case Color::Green:
			return "green";
		case Color::Red:
			return "red";
		case Color::Blue:
			return "blue";
		case Color::Yellow:
			return "yellow";
		case Color::Pink:
			return "pink";
		case Color::Black:
			return "black";
		}
		return "black";
	}
};

CCanvas::CCanvas(std::ostream & out)
	: m_out(out)
{
}

void CCanvas::BeginDraw()
{
	m_out << "<svg xmlns='http://www.w3.org/2000/svg'>" << std::endl;
}

void CCanvas::EndDraw()
{
	m_out << "</svg>" << std::endl;
}

void CCanvas::SetColor(Color color)
{	
	m_color = color;
}

void CCanvas::DrawLine(Vec2 const & from, Vec2 const & to)
{
	m_out << "<line x1='" << from.x << " ' y1=' " <<  from.y << "' x2='" << to.x << "' y2='" << to.y
		<< "' stroke-width='1' stroke='"<< GetColor(m_color) << "'/>" << std::endl;
}

void CCanvas::DrawEllipse(double left, double top, double width, double height)
{
	m_out << "<ellipse cx='" << left << "' cy='" << top << "' rx='" << width << "' ry='" << height
		<< "' stroke-width='1' fill='" << GetColor(m_color) << "'/>" << std::endl;
}