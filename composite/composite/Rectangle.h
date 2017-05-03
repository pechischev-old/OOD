#pragma once
#include "SimpleShape.h"


class CRectangle 
	: public CShape
{
public:
	CRectangle(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle);

protected:
	void DrawImpl(ICanvas & canvas) override;
};

