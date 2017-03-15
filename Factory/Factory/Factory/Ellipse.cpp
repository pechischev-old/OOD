#include "Ellipse.h"



CEllipse::CEllipse()
{
}


CEllipse::~CEllipse()
{
}

void CEllipse::Draw(ICanvas & canvas)
{
}

glm::vec2 CEllipse::GetCenter() const
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
