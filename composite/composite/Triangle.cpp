#include "stdafx.h"
#include "Triangle.h"
#include "ICanvas.h"



CTriangle::CTriangle(RectD const & frame, IStylePtr const  & fillStyle, IStylePtr const  & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}

CTriangle::CTriangle(RectD const & frame)
	: CShape(frame)
{
}

void CTriangle::DrawImpl(ICanvas & canvas) const
{
	auto frame = GetFrame();
	canvas.MoveTo(frame.left + frame.width / 2.f, frame.top);
	canvas.LineTo(frame.left + frame.width, frame.top + frame.height);
	canvas.LineTo(frame.left, frame.top + frame.height);
	canvas.LineTo(frame.left + frame.width / 2.f, frame.top);
}
