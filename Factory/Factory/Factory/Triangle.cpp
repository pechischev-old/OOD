#include "Triangle.h"



CTriangle::CTriangle(Color color, sf::Vector2f const & vertex1, sf::Vector2f const & vertex2, sf::Vector2f const & vertex3)
	: CShape(color)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}


CTriangle::~CTriangle()
{
}

void CTriangle::Draw(ICanvas & canvas)
{
	canvas.DrawLine(m_vertex1, m_vertex2);
	canvas.DrawLine(m_vertex2, m_vertex3);
	canvas.DrawLine(m_vertex3, m_vertex1);
}

sf::Vector2f CTriangle::GetVertex1() const
{
	return m_vertex1;
}

sf::Vector2f CTriangle::GetVertex2() const
{
	return m_vertex2;
}

sf::Vector2f CTriangle::GetVertex3() const
{
	return m_vertex3;
}
