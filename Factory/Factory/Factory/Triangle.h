#pragma once
#include <SFML/System/Vector2.hpp>
#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(Color color, sf::Vector2f const & vertex1, sf::Vector2f const & vertex2, sf::Vector2f const & vertex3);
	~CTriangle();

	void Draw(ICanvas & canvas) override;

	sf::Vector2f GetVertex1() const;
	sf::Vector2f GetVertex2() const;
	sf::Vector2f GetVertex3() const;
private:
	sf::Vector2f m_pointA;
	sf::Vector2f m_pointB;
	sf::Vector2f m_pointC;
};

