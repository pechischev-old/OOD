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

void CSlide::AddShape(const IShapePtr & shape)
{
	m_shapes.push_back(shape);
}

void CSlide::RemoveShape(size_t index)
{
	if (m_shapes.size() <= index)
	{
		throw std::out_of_range("out of range");
	}
	m_shapes.erase(m_shapes.begin() + index);
}

void CSlide::Draw(ICanvas & canvas) const
{
	std::for_each(m_shapes.begin(), m_shapes.end(), [&](auto & shape) {
		shape->Draw(canvas);
	});
}
