#include "stdafx.h"

#include "SimpleShape.h"
#include "Style.h"

CShape::CShape(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle)
	: m_fillStyle(CStyle(false, 0x000000))
	, m_outlineStyle(CStyle(false, 0x000000))
	, m_frame(frame)
{
}

RectD CShape::GetFrame()
{
	return m_frame;
}

void CShape::SetFrame(const RectD & rect)
{
	m_frame = rect;
}

IStyle & CShape::GetOutlineStyle()
{
	return m_outlineStyle;
}

const IStyle & CShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

IStyle & CShape::GetFillStyle()
{
	return m_fillStyle;
}

const IStyle & CShape::GetFillStyle() const
{
	return m_fillStyle;
}

std::shared_ptr<IGroupShape> CShape::GetGroup()
{
	return nullptr;
}

std::shared_ptr<const IGroupShape> CShape::GetGroup() const
{
	return nullptr;
}

void CShape::Draw(ICanvas & canvas)
{
	DrawImpl(canvas);
}
