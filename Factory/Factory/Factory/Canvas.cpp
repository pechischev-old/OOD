#include "stdafx.h"
#include "Canvas.h"
#include <SFML/Graphics/Color.hpp>

namespace 
{
	static const sf::Color GetColorByType(Color type) // TODO: 
	{
		auto color = sf::Color::White;
		switch (type)
		{
			case Color::Green:
				return sf::Color::Green;
			case Color::Red:
				return sf::Color::Red;
			case Color::Blue:
				return sf::Color::Blue;
			case Color::Yellow:
				return sf::Color::Yellow;
			case Color::Pink:
				return sf::Color::Magenta;
			case Color::Black:
				return sf::Color::Black;
		}
		return sf::Color::White;
	};

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

void CCanvas::DrawLine(sf::Vector2f const & from, sf::Vector2f const & to)
{
	m_out << "Draw line from " << from.x << ", " <<  from.y << " to " << to.x << ", " << to.y << std::endl;
}

void CCanvas::DrawEllipse(float left, float top, float width, float height)
{
	m_out << "Draw ellipse position x = " << left << " y = " << top << 
		 " width = " << width << " height = " << height << std::endl;
}