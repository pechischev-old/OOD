#pragma once
#include <string>
#include <memory>
#include "Colors.h"
#include "ShapeTypes.h"
#include "ICanvas.h"

class CShape
{
public:
	CShape(Color color);
	virtual ~CShape() = default;

	virtual void Draw(ICanvas & canvas) = 0;

	Color GetColor() const;

protected:
	Color m_color;
};

