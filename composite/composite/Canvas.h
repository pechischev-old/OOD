#pragma once
#include "ICanvas.h"
#include <sstream>
#include <vector>


class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & stream);

	void SetLineColor(RGBAColor color) override;
	void BeginFill(RGBAColor color) override;
	void EndFill() override;
	void MoveTo(double x, double y) override;
	void LineTo(double x, double y) override;
	void DrawEllipse(double left, double top, double width, double height) override;
	void SetLineThickness(float thickness) override;

	~CCanvas();

private:
	bool m_isFilling;
	std::ostream & m_stream;
	RGBAColor m_outlineColor;
	RGBAColor m_fillColor;
	double m_x;
	double m_y;
	float m_thickness;
	std::vector<std::pair<double, double>> m_filledPoints;
};

