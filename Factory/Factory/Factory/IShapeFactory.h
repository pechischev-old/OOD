#pragma once
#include <string>
#include <memory>
#include "ShapeTypes.h"

class CShape;

class IShapeFactory
{
public:
	virtual std::shared_ptr<CShape> CreateShape(std::istream & description) = 0;
};