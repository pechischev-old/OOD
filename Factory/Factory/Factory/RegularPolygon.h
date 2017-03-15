#pragma once
#include <vector>
#include <glm/vec2.hpp>
#include "Shape.h"

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon();
	~CRegularPolygon();

	void Draw(ICanvas & canvas) override;

	unsigned GetVertexCount() const;
	glm::vec2 GetCenter() const;
	float GetRadius() const;

private:
	unsigned m_vertexCount;
	float m_radius;
	glm::vec2 m_center;
};

