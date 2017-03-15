#pragma once
#include <string>
#include <memory>
#include "ShapeTypes.h"

class CShape;

class IShapeFactory
{
public:
	virtual std::shared_ptr<CShape> CreateShape(std::string const & description) = 0;
};