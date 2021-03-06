#pragma once
#include <ostream>
#include "ICanvas.h"


class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & out);
	
	void SetColor(Color color) override;
	void DrawLine(Vec2 const & from, Vec2 const & to) override;
	void DrawEllipse(double left, double top, double width, double height) override;
	void BeginDraw() override;
	void EndDraw() override;
private:
	std::ostream & m_out;
	Color m_color;
};

