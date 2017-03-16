#include <SFML/System/Vector2.hpp>
#include "Rectangle.h"
#include "ICanvas.h"

using namespace sf;

CRectangle::CRectangle(Color color, Vec2 leftTop, Vec2 rightBottom)
	: CShape(color)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

void CRectangle::Draw(ICanvas & canvas)
{

	canvas.SetColor(GetColor());
	canvas.DrawLine(m_leftTop, Vec2(m_rightBottom.x, m_leftTop.y));
	canvas.DrawLine(Vec2(m_rightBottom.x, m_leftTop.y), m_rightBottom);
	canvas.DrawLine(m_rightBottom, Vec2(m_leftTop.x, m_rightBottom.y));
	canvas.DrawLine(Vec2(m_leftTop.x, m_rightBottom.y), m_leftTop);
}

Vec2 CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Vec2 CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}