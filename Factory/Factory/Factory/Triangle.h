#pragma once
#include <glm/vec2.hpp>
#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(glm::vec2 const & vertex1, glm::vec2 const & vertex2, glm::vec2 const & vertex3);
	~CTriangle();

	void Draw(ICanvas & canvas) override;

	glm::vec2 GetVertex1() const;
	glm::vec2 GetVertex2() const;
	glm::vec2 GetVertex3() const;
private:
	glm::vec2 m_pointA;
	glm::vec2 m_pointB;
	glm::vec2 m_pointC;
};

