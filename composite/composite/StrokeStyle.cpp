#include "StrokeStyle.h"



CStrokeStyle::CStrokeStyle(bool enable, RGBAColor color, float lineThickness)
	: CStyle(enable, color)
	, m_lineThickness(lineThickness)
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
