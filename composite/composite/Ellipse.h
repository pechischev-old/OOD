#pragma once
#include "SimpleShape.h"


class CEllipse : public CShape
{
public:
	CEllipse(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle);

protected:
	void DrawImpl(ICanvas & canvas) override;
};

