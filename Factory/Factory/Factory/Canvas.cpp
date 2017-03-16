#include "stdafx.h"
#include "Canvas.h"

namespace 
{
	std::string const GetColor(Color type)
	{
		switch (type)
		{
		case Color::Green:
			return "Green";
		case Color::Red:
			return "Red";
		case Color::Blue:
			return "Blue";
		case Color::Yellow:
			return "Yellow";
		case Color::Pink:
			return "Pink";
		case Color::Black:
			return "Black";
		}
		return "White";
	}
};

CCanvas::CCanvas(std::ostream & out)
	: m_out(out)
{
}

void CCanvas::OutputText(std::string const & text)
{
	m_out << text << std::endl;
}

void CCanvas::SetColor(Color color)
{	
	m_out << "Use color " << GetColor(color) << std::endl;
}

void CCanvas::DrawLine(Vec2 const & from, Vec2 const & to)
{
	m_out << "Draw line from " << from.x << ", " <<  from.y << " to " << to.x << ", " << to.y << std::endl;
}

void CCanvas::DrawEllipse(double left, double top, double width, double height)
{
	m_out << "Draw ellipse position x = " << left << " y = " << top << 
		 " width = " << width << " height = " << height << std::endl;
}