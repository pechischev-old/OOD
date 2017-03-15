#pragma once
#include "Colors.h"
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();

	std::shared_ptr<CShape> CreateShape(std::istream & description) override;

private:
	std::shared_ptr<CShape> CreateRectangle(Color color, std::istream & description);
	std::shared_ptr<CShape> CreateTriangle(Color color, std::istream & description);
	std::shared_ptr<CShape> CreateEllipse(Color color, std::istream & description);
	std::shared_ptr<CShape> CreatePolygon(Color color, std::istream & description);
};

