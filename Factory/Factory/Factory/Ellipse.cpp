#include "Ellipse.h"



CEllipse::CEllipse(Color color, sf::Vector2f const & center, float width, float height)
	: CShape(color)
	, m_center(center)
	, m_horizontalRadius(width)
	, m_verticalRadius(height)
{
}


CEllipse::~CEllipse()
{
}

void CEllipse::Draw(ICanvas & canvas)
{
	canvas.DrawEllipse(m_center.x, m_center.y, m_horizontalRadius, m_verticalRadius);
}

sf::Vector2f CEllipse::GetCenter() const
{
	return m_center;
}

float CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

float CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}
