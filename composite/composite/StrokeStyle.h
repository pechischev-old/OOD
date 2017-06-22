#pragma once
#include "Style.h"


class CStrokeStyle : public CStyle
{
public:
	CStrokeStyle(bool enable, RGBAColor color, float lineThickness);
	CStrokeStyle();

	~CStrokeStyle() = default;

	void SetLineThickness(float thickness);
	float GetLineThickness() const;

	friend bool operator==(const CStrokeStyle& left, const CStrokeStyle& right);
	friend bool operator!=(const CStrokeStyle & left, const CStrokeStyle & right);
private:
	float m_lineThickness;
};

