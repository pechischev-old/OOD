#include "RegularPolygon.h"



CRegularPolygon::CRegularPolygon()
{
}


CRegularPolygon::~CRegularPolygon()
{
}

void CRegularPolygon::Draw(ICanvas & canvas)
{
}

unsigned CRegularPolygon::GetVertexCount() const
{
	return m_vertexCount;
}

glm::vec2 CRegularPolygon::GetCenter() const
{
	return m_center;
}

float CRegularPolygon::GetRadius() const
{
	return m_radius;
}
