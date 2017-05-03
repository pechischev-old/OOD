#include "stdafx.h"
#include "Triangle.h"
#include "ICanvas.h"



CTriangle::CTriangle(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}

void CTriangle::DrawImpl(ICanvas & canvas)
{
	auto frame = GetFrame();
	canvas.MoveTo(frame.left + frame.width / 2.f, frame.top);
	canvas.LineTo(frame.left + frame.width, frame.top + frame.height);
	canvas.LineTo(frame.left, frame.top + frame.height);
	canvas.LineTo(frame.left + frame.width / 2.f, frame.top);
}
