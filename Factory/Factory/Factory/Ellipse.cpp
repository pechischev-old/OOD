#include "Ellipse.h"
#include "ICanvas.h"


CEllipse::CEllipse(Color color, Vec2 const & center, double width, double height)
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

Vec2 CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}
