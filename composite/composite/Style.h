#pragma once
#include "CommonTypes.h"
#include "IStyle.h"


class CStyle : public IStyle
{
public:
	CStyle(bool enable, RGBAColor color);
	CStyle();

	bool IsEnabled()const override;
	void Enable(bool enable) override;

	RGBAColor GetColor()const override;
	void SetColor(RGBAColor color) override;

	friend bool operator==(const CStyle& left, const CStyle& right);
	friend bool operator!=(const CStyle & left, const CStyle & right);

	virtual ~CStyle() = default;
private:
	bool m_enable;
	RGBAColor m_color;
};
