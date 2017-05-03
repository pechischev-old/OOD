#include "stdafx.h"
#include "Ellipse.h"
#include "ICanvas.h"



CEllipse::CEllipse(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}

void CEllipse::DrawImpl(ICanvas & canvas)
{
	auto frame = GetFrame();
	canvas.DrawEllipse(frame.left, frame.top, frame.width, frame.width);
}