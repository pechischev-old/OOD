#pragma once
#include <vector>
#include <memory>
#include "CommonTypes.h"
#include "ISlide.h"
#include "Shapes.h"

class IShape;

class CSlide 
	: public ISlide
	, public CShapes
{
public:
	CSlide(double width, double height);
	~CSlide();

	double GetWidth()const override;
	double GetHeight()const override;

	void Draw(ICanvas & canvas);
private:
	double m_width;
	double m_height;
};

