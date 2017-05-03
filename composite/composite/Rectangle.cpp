#include "stdafx.h"
#include "Rectangle.h"
#include "ICanvas.h"

CRectangle::CRectangle(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}

void CRectangle::DrawImpl(ICanvas & canvas)
{
	auto frame = GetFrame();
	canvas.MoveTo(frame.left, frame.top);
	canvas.LineTo(frame.left + frame.width, frame.top);
	canvas.LineTo(frame.left + frame.width, frame.top + frame.height);
	canvas.LineTo(frame.left, frame.top + frame.height);
	canvas.LineTo(frame.left, frame.top);
}
