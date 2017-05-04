#include "stdafx.h"

#include "SimpleShape.h"
#include "ICanvas.h"

CShape::CShape(RectD const & frame, IStylePtr const & fillStyle, IStylePtr const & outlineStyle)
	: m_fillStyle(fillStyle)
	, m_outlineStyle(outlineStyle)
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
	return *m_outlineStyle.get();
}

const IStyle & CShape::GetOutlineStyle() const
{
	return *m_outlineStyle.get();
}

IStyle & CShape::GetFillStyle()
{
	return *m_fillStyle.get();
}

const IStyle & CShape::GetFillStyle() const
{
	return *m_fillStyle.get();
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
	if (m_outlineStyle->IsEnabled())
	{
		canvas.SetLineColor(m_outlineStyle->GetColor());
		canvas.SetLineThickness(static_cast<CStrokeStyle*>(m_outlineStyle.get())->GetLineThickness());
	}

	auto filledShape = false;
	if (m_fillStyle->IsEnabled())
	{
		canvas.BeginFill(m_fillStyle->GetColor());
		filledShape = true;
	}

	DrawImpl(canvas);

	if (filledShape)
	{
		canvas.EndFill();
	}
}
