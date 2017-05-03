#pragma once
#include "CommonTypes.h"
#include "IStyle.h"


class CStyle : public IStyle
{
public:
	CStyle(bool enable, RGBAColor color);
	bool IsEnabled()const override;
	void Enable(bool enable) override;

	RGBAColor GetColor()const override;
	void SetColor(RGBAColor color) override;

	virtual ~CStyle() = default;
private:
	bool m_enable;
	RGBAColor m_color;
};
