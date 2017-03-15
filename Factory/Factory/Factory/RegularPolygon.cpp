#include "RegularPolygon.h"



CRegularPolygon::CRegularPolygon(Color color, sf::Vector2f const & center, float radius, unsigned vertexCount)
	: CShape(color)
	, m_center(center)
	, m_radius(radius)
	, m_vertexCount(vertexCount)
{
}


CRegularPolygon::~CRegularPolygon()
{
}

void CRegularPolygon::Draw(ICanvas & canvas)
{
	float angle = 360.f / m_vertexCount;
	auto predPoint = GetCoordinatePoint(angle, 0);

	for (unsigned vertex = 1; vertex < m_vertexCount; ++vertex)
	{
		auto nextPoint = GetCoordinatePoint(angle, vertex);
		canvas.DrawLine(predPoint, nextPoint);
		predPoint = nextPoint;
	}
}

unsigned CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

sf::Vector2f CRegularPolygon::GetCenter() const
{
	return m_center;
}

float CRegularPolygon::GetRadius() const
{
	return m_radius;
}

sf::Vector2f CRegularPolygon::GetCoordinatePoint(float angle, unsigned number) const
{
	return sf::Vector2f(m_center.x + m_radius * cos(angle * number), m_center.y + m_radius * sin(angle * number));
}
