#pragma once
#include <SFML/System/Vector2.hpp>
#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, sf::Vector2f const & center, float width, float height);
	~CEllipse();

	void Draw(ICanvas & canvas) override;

	sf::Vector2f GetCenter() const;
	float GetHorizontalRadius() const;
	float GetVerticalRadius() const;

private:
	float m_horizontalRadius;
	float m_verticalRadius;
	sf::Vector2f m_center;
};

