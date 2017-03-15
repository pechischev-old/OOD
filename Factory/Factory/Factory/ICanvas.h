#pragma once
#include "Colors.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(unsigned from, unsigned to) = 0;
	virtual void DrawEllipse(unsigned left, unsigned top, unsigned width, unsigned height) = 0;
	virtual ~ICanvas() = default;
};
