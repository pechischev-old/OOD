#include "StrokeStyle.h"



CStrokeStyle::CStrokeStyle(bool enable, RGBAColor color, float lineThickness)
	: CStyle(enable, color)
	, m_lineThickness(lineThickness)
{
}

CStrokeStyle::CStrokeStyle()
	: CStyle()
	, m_lineThickness(0.f)
{
}

void CStrokeStyle::SetLineThickness(float thickness)
{
	m_lineThickness = thickness;
}

float CStrokeStyle::GetLineThickness() const
{
	return m_lineThickness;
}

bool operator==(const CStrokeStyle & left, const CStrokeStyle & right)
{
	return (left.GetColor() == right.GetColor() && left.IsEnabled() == right.IsEnabled() && left.GetLineThickness() == right.GetLineThickness());
}

bool operator!=(const CStrokeStyle & left, const CStrokeStyle & right)
{
	return !(left == right);
}
