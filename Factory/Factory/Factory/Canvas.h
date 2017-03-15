#pragma once
#include <ostream>
#include "ICanvas.h"


class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream & out);
	
	void SetColor(Color color) override;
	void DrawLine(sf::Vector2f const & from, sf::Vector2f const & to) override;
	void DrawEllipse(float left, float top, float width, float height) override;
	void OutputText(std::string const & text) override;

private:
	std::ostream & m_out;
};

