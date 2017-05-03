#include "stdafx.h"
#include "Slide.h"

CSlide::CSlide(double width, double height)
	: m_width(width)
	, m_height(height)
{
}

CSlide::~CSlide()
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

void CSlide::Draw(ICanvas & canvas)
{
	std::for_each(m_shapes.begin(), m_shapes.end(), [&](auto & shape) {
		shape->Draw(canvas);
	});
}
