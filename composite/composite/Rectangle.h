#pragma once
#include "SimpleShape.h"


class CRectangle 
	: public CShape
{
public:
	CRectangle(RectD const & frame, IStylePtr const  & fillStyle, IStylePtr const  & outlineStyle);
	CRectangle(RectD const & frame);
protected:
	void DrawImpl(ICanvas & canvas) const override;
};

