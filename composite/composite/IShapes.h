#pragma once
#include <numeric>
#include <memory>
#include "IShape.h"


using IShapePtr = std::shared_ptr<IShape>;

class IShapes
{
public:
	virtual size_t GetShapesCount()const = 0;
	virtual void InsertShape(const IShapePtr& shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	virtual IShapePtr GetShapeAtIndex(size_t index) = 0;
	virtual void RemoveShapeAtIndex(size_t index) = 0;

	virtual ~IShapes() = default;
};