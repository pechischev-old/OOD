#pragma once
#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(Color color, Vec2 const & vertex1, Vec2 const & vertex2, Vec2 const & vertex3);
	~CTriangle();

	void Draw(ICanvas & canvas) const override;

	Vec2 GetVertex1() const;
	Vec2 GetVertex2() const;
	Vec2 GetVertex3() const;
private:
	Vec2 m_vertex1;
	Vec2 m_vertex2;
	Vec2 m_vertex3;
};

