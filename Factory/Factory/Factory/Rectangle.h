#pragma once
#include "Shape.h"
#include <glm\vec2.hpp> // TODO: temp, replace on SFML/vec2


class CRectangle : public CShape
{
public:
	CRectangle(glm::vec2 leftTop, glm::vec2 rightBottom);
	~CRectangle() = default;

	void Draw(ICanvas & canvas) override;
	glm::vec2 GetLeftTop() const;
	glm::vec2 GetRightBottom() const;

private:
	glm::vec2 m_leftTop;
	glm::vec2 m_rightBottom;
};

