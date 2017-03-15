#include "Rectangle.h"



CRectangle::CRectangle(glm::vec2 leftTop, glm::vec2 rightBottom)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

void CRectangle::Draw(ICanvas & canvas)
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_leftTop.x, m_rightBottom.x);
	canvas.DrawLine(m_rightBottom.x, m_rightBottom.y);
	canvas.DrawLine(m_rightBottom.y, m_leftTop.x);
	canvas.DrawLine(m_leftTop.x, m_leftTop.y);
}

glm::vec2 CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

glm::vec2 CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}