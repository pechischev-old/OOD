#pragma once
#include <istream>
#include "Shape.h"
#include <vector>

class CPictureDraft
{
public:
	CPictureDraft();
	~CPictureDraft();

	unsigned GetShapeCount() const;

	void AddShape(std::shared_ptr<CShape> & shape);
	std::shared_ptr<CShape> GetShape(unsigned index) const;

private:
	std::vector<std::shared_ptr<CShape>> m_shapes;
};