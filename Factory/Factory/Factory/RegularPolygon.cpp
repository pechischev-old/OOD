#include "RegularPolygon.h"
#include "ICanvas.h"


CRegularPolygon::CRegularPolygon(Color color, Vec2 const & center, double radius, unsigned vertexCount)
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
	double angle = 360.f / m_vertexCount;
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

Vec2 CRegularPolygon::GetCenter() const
{
	return m_center;
}

double CRegularPolygon::GetRadius() const
{
	return m_radius;
}

Vec2 CRegularPolygon::GetCoordinatePoint(double angle, unsigned number) const
{
	return Vec2(m_center.x + m_radius * cos(angle * number), m_center.y + m_radius * sin(angle * number));
}
