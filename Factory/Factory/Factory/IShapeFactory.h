#pragma once
#include <string>
#include <memory>
#include "ShapeTypes.h"

class CShape;

struct IShapeFactory
{
	virtual std::shared_ptr<CShape> CreateShape(std::istream & description) = 0;
	virtual ~IShapeFactory() = default;
};