#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Shape.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, sf::Vector2f const & center, float radius, unsigned vertexCount);
	~CRegularPolygon();

	void Draw(ICanvas & canvas) override;

	unsigned GetVertexCount() const;
	sf::Vector2f GetCenter() const;
	float GetRadius() const;

private:
	sf::Vector2f GetCoordinatePoint(float angle, unsigned number) const;

private:
	unsigned m_vertexCount;
	float m_radius;
	sf::Vector2f m_center;
};

