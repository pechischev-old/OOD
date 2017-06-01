#pragma once
#include <vector>
#include "IShapes.h"

class CShapes : public IShapes
{
public:
	CShapes() = default;

	size_t GetShapesCount()const override;
	void InsertShape(const IShapePtr & shape, size_t position = std::numeric_limits<size_t>::max()) override;
	IShapePtr GetShapeAtIndex(size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

	virtual ~CShapes() = default;

protected:
	std::vector<IShapePtr> m_shapes;
};

