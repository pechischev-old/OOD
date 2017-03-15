#pragma once
#include <ostream>
#include "ICanvas.h"


class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & out);
	
	void SetColor(Color color) override;
	void DrawLine(unsigned from, unsigned to) override;
	void DrawEllipse(unsigned left, unsigned top, unsigned width, unsigned height) override;

private:
	std::ostream & m_out;
};

