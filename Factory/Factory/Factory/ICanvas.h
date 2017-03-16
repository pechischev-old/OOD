#pragma once
#include <string>
#include "Colors.h"
#include "Vec2.h"

struct ICanvas
{
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Vec2 const & from, Vec2 const & to) = 0;
	virtual void DrawEllipse(double left, double top, double width, double height) = 0;
	virtual void OutputText(std::string const & text) = 0;
	virtual ~ICanvas() {};
};
