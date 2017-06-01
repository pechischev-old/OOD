#pragma once
#include <vector>
#include <memory>
#include "CommonTypes.h"
#include "ISlide.h"
#include "Shapes.h"

class IShape;

class CSlide 
	: public ISlide
{
public:
	CSlide(double width, double height);
	~CSlide();

	double GetWidth()const override;
	double GetHeight()const override;

	void AddShape(const IShapePtr & shape);
	void RemoveShape(size_t index);

	void Draw(ICanvas & canvas);
private:
	double m_width;
	double m_height;
	std::vector<IShapePtr> m_shapes;
};

