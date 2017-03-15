#include "ShapeFactory.h"
#include "ShapeTypes.h"
#include "Shape.h"

#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "RegularPolygon.h"

CShapeFactory::CShapeFactory()
{
}

std::shared_ptr<CShape> CShapeFactory::CreateShape(std::string const & description)
{
	return  std::make_shared<CRectangle>(glm::vec2(75, 75), glm::vec2(80, 80));
}
