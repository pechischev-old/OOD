#pragma once
#include "CommonTypes.h"
#include <memory>



class IStyle
{
public:
	virtual bool IsEnabled()const = 0;
	virtual void Enable(bool enable) = 0;

	virtual RGBAColor GetColor()const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};

using IStylePtr = std::shared_ptr<IStyle>;