#include "Triangle.h"
#include "ICanvas.h"


CTriangle::CTriangle(Color color, Vec2 const & vertex1, Vec2 const & vertex2, Vec2 const & vertex3)
	: CShape(color)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}


CTriangle::~CTriangle()
{
}

void CTriangle::Draw(ICanvas & canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_vertex1, m_vertex2);
	canvas.DrawLine(m_vertex2, m_vertex3);
	canvas.DrawLine(m_vertex3, m_vertex1);
}

Vec2 CTriangle::GetVertex1() const
{
	return m_vertex1;
}

Vec2 CTriangle::GetVertex2() const
{
	return m_vertex2;
}

Vec2 CTriangle::GetVertex3() const
{
	return m_vertex3;
}
