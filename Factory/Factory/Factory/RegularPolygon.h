#pragma once
#include <vector>
#include "Shape.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(Color color, Vec2 const & center, double radius, unsigned vertexCount);
	~CRegularPolygon();

	void Draw(ICanvas & canvas) override;

	unsigned GetVertexCount() const;
	Vec2 GetCenter() const;
	double GetRadius() const;

private:
	Vec2 GetCoordinatePoint(double angle, unsigned number) const;

private:
	unsigned m_vertexCount;
	double m_radius;
	Vec2 m_center;
};

