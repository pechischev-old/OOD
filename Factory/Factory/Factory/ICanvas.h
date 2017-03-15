#pragma once
#include <SFML/System/Vector2.hpp>
#include <string>
#include "Colors.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(sf::Vector2f const & from, sf::Vector2f const & to) = 0;
	virtual void DrawEllipse(float left, float top, float width, float height) = 0;
	virtual void OutputText(std::string const & text) = 0;
	virtual ~ICanvas() = default;
};
