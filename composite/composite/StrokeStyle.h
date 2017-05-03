#pragma once
#include "Style.h"


class CStrokeStyle : public CStyle
{
public:
	CStrokeStyle(bool enable, RGBAColor color, float lineThickness);
	~CStrokeStyle() = default;

	void SetLineThickness(float thickness);
	float GetLineThickness() const;
private:
	float m_lineThickness;
};

