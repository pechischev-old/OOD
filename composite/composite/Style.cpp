#include "Style.h"



CStyle::CStyle(bool enable, RGBAColor color)
	: m_enable(enable)
	, m_color(color)
{
}

bool CStyle::IsEnabled() const
{
	return m_enable;
}

void CStyle::Enable(bool enable)
{
	m_enable = enable;
}

RGBAColor CStyle::GetColor() const
{
	return m_color;
}

void CStyle::SetColor(RGBAColor color)
{
	m_color = color;
}
