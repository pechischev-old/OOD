#pragma once
#include "Shape.h"


class CRectangle : public CShape
{
public:
	CRectangle(Color color, Vec2 leftTop, Vec2 rightBottom);
	~CRectangle() = default;

	void Draw(ICanvas & canvas) const override;
	
	Vec2 GetLeftTop() const;
	Vec2 GetRightBottom() const;

private:
	Vec2 m_leftTop;
	Vec2 m_rightBottom;
};

