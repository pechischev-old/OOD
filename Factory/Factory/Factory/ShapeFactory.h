#pragma once
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();

	std::shared_ptr<CShape> CreateShape(std::string const & description) override;
};

