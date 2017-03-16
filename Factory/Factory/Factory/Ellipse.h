#pragma once
#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Vec2 const & center, double width, double height);
	~CEllipse();

	void Draw(ICanvas & canvas) const override;

	Vec2 GetCenter() const;
	double GetHorizontalRadius() const;
	double GetVerticalRadius() const;

private:
	double m_horizontalRadius;
	double m_verticalRadius;
	Vec2 m_center;
};

