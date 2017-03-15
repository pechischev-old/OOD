#include "Triangle.h"



CTriangle::CTriangle(glm::vec2 const & vertex1, glm::vec2 const & vertex2, glm::vec2 const & vertex3)
	: m_pointA(vertex1)
	, m_pointB(vertex2)
	, m_pointC(vertex3)
{
}


CTriangle::~CTriangle()
{
}

void CTriangle::Draw(ICanvas & canvas)
{

}

glm::vec2 CTriangle::GetVertex1() const
{
	return m_pointA;
}

glm::vec2 CTriangle::GetVertex2() const
{
	return m_pointB;
}

glm::vec2 CTriangle::GetVertex3() const
{
	return m_pointC;
}
