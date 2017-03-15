#include <SFML/System/Vector2.hpp>
#include "Rectangle.h"


using namespace sf;

CRectangle::CRectangle(Color color, sf::Vector2f leftTop, sf::Vector2f rightBottom)
	: CShape(color)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

void CRectangle::Draw(ICanvas & canvas)
{

	canvas.SetColor(GetColor());
	canvas.DrawLine(m_leftTop, Vector2f(m_rightBottom.x, m_leftTop.y));
	canvas.DrawLine(Vector2f(m_rightBottom.x, m_leftTop.y), m_rightBottom);
	canvas.DrawLine(m_rightBottom, Vector2f(m_leftTop.x, m_rightBottom.y));
	canvas.DrawLine(Vector2f(m_leftTop.x, m_rightBottom.y), m_leftTop);
}

sf::Vector2f CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

sf::Vector2f CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}