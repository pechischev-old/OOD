#pragma once
#include "SimpleShape.h"


class CEllipse : public CShape
{
public:
	CEllipse(RectD const & frame, IStylePtr const  & fillStyle, IStylePtr const & outlineStyle);
	CEllipse(RectD const & frame);
protected:
	void DrawImpl(ICanvas & canvas) const override;
};

