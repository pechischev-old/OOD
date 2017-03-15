#pragma once
#include "Shape.h"
#include <SFML/System/Vector2.hpp>


class CRectangle : public CShape
{
public:
	CRectangle(Color color, sf::Vector2f leftTop, sf::Vector2f rightBottom);
	~CRectangle() = default;

	void Draw(ICanvas & canvas) override;
	
	sf::Vector2f GetLeftTop() const;
	sf::Vector2f GetRightBottom() const;

private:
	sf::Vector2f m_leftTop;
	sf::Vector2f m_rightBottom;
};

