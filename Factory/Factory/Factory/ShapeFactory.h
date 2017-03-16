#pragma once
#include "Colors.h"
#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory
{
public:
	CShapeFactory();

	std::unique_ptr<CShape> CreateShape(std::istream & description) override;

private:
	std::unique_ptr<CShape> CreateRectangle(Color color, std::istream & description);
	std::unique_ptr<CShape> CreateTriangle(Color color, std::istream & description);
	std::unique_ptr<CShape> CreateEllipse(Color color, std::istream & description);
	std::unique_ptr<CShape> CreatePolygon(Color color, std::istream & description);
};

