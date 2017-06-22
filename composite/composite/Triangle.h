#pragma once
#include "SimpleShape.h"

class CTriangle : public CShape
{
public:
	CTriangle(RectD const & frame, IStylePtr const & fillStyle, IStylePtr const & outlineStyle);
	CTriangle(RectD const & frame);
protected:
	void DrawImpl(ICanvas & canvas) const override;
};

