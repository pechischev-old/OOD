#include "Shape.h"



CShape::CShape()
{
}

Color CShape::GetColor() const
{
	return m_color;
}

void CShape::SetColor(Color color)
{
	m_color = color;
}
