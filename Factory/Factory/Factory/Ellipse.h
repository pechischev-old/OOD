#pragma once
#include <glm/vec2.hpp>
#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse();
	~CEllipse();

	void Draw(ICanvas & canvas) override;

	glm::vec2 GetCenter() const;
	float GetHorizontalRadius() const;
	float GetVerticalRadius() const;

private:
	float m_horizontalRadius;
	float m_verticalRadius;
	glm::vec2 m_center;
};

