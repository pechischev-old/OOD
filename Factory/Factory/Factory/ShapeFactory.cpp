#include "ShapeFactory.h"
#include "ShapeTypes.h"

#include "Rectangle.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "RegularPolygon.h"

namespace
{
	const std::string ERROR_MESSAGE = "invalid parameter ";

	Color GetColor(std::istream & description)
	{
		std::string word;
		description >> word;
		if (word == "red")
		{
			return Color::Red;
		}
		else if (word == "black")
		{
			return Color::Black;
		}
		else if (word == "green")
		{
			return Color::Green;
		}
		else if (word == "blue")
		{
			return Color::Blue;
		}
		else if (word == "pink")
		{
			return Color::Pink;
		}
		else if (word == "yellow")
		{
			return Color::Yellow;
		}
		else
		{
			return Color::Black;
		}
	}
};

CShapeFactory::CShapeFactory()
{
}

std::unique_ptr<CShape> CShapeFactory::CreateShape(std::istream & description)
{
	std::string type;
	description >> type;

	Color color = GetColor(description);

	if (type == ShapeType::RECTANGLE)
	{
		return CreateRectangle(color, description);
	}
	else if (type == ShapeType::ELLIPSE)
	{
		return CreateEllipse(color, description);
	}
	else if (type == ShapeType::TRIANGLE)
	{
		return CreateTriangle(color, description);
	}
	else if (type == ShapeType::POLYGON)
	{
		return CreatePolygon(color, description);
	}
	else
	{
		throw std::invalid_argument("unknown shape type");
	}
	return nullptr;
}

std::unique_ptr<CShape> CShapeFactory::CreateRectangle(Color color, std::istream & description)
{
	double left, top, right, bottom;
	if (description >> left >> top >> right >> bottom)
	{
		return std::make_unique<CRectangle>(color, Vec2(left, top), Vec2(right, bottom));
	}
	else
	{
		throw std::invalid_argument(ERROR_MESSAGE + " for " + ShapeType::RECTANGLE);
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateTriangle(Color color, std::istream & description)
{
	double x1, x2, x3, y1, y2, y3;
	if (description >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		return std::make_unique<CTriangle>(color, Vec2(x1, y1), Vec2(x2, y2), Vec2(x3, y3));
	}
	else
	{
		throw std::invalid_argument(ERROR_MESSAGE + " for " + ShapeType::TRIANGLE);
	}
}

std::unique_ptr<CShape> CShapeFactory::CreateEllipse(Color color, std::istream & description)
{
	double x, y, width, height;
	if (description >> x >> y >> width >> height) 
	{ 
		return std::make_unique<CEllipse>(color, Vec2(x, y), width, height);
	}
	else
	{
		throw std::invalid_argument(ERROR_MESSAGE + " for " + ShapeType::ELLIPSE);
	}
}

std::unique_ptr<CShape> CShapeFactory::CreatePolygon(Color color, std::istream & description)
{
	double x, y, radius;
	unsigned vertexCount;
	if (description >> x >> y >> radius >> vertexCount)
	{
		return std::make_unique<CRegularPolygon>(color, Vec2(x, y), radius, vertexCount);
	}
	else
	{
		throw std::invalid_argument(ERROR_MESSAGE + " for " + ShapeType::POLYGON);
	}
}
