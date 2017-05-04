#include "stdafx.h"
#include "Ellipse.h"
#include "ICanvas.h"



CEllipse::CEllipse(RectD const & frame, IStylePtr const  & fillStyle, IStylePtr const  & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}

CEllipse::CEllipse(RectD const & frame)
	: CShape(frame)
{
}

void CEllipse::DrawImpl(ICanvas & canvas)
{
	auto frame = GetFrame();
	canvas.DrawEllipse(frame.left, frame.top, frame.width, frame.width);
}