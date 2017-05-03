#pragma once
#include "SimpleShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle);

protected:
	void DrawImpl(ICanvas & canvas) override;
};

