#include "stdafx.h"

#include "Shapes.h"



CShapes::CShapes()
{
}

size_t CShapes::GetShapesCount() const
{
	return m_shapes.size();
}

void CShapes::InsertShape(const IShapePtr & shape, size_t position)
{
	if (position > m_shapes.size())
	{
		m_shapes.push_back(shape);
	}
	else
	{
		m_shapes.insert(m_shapes.begin() + position, shape);
	}
}

IShapePtr CShapes::GetShapeAtIndex(size_t index)
{
	if (m_shapes.size() <= index)
	{
		throw std::out_of_range("out of range");;
	}
	return m_shapes[index];
}

void CShapes::RemoveShapeAtIndex(size_t index)
{
	if (m_shapes.size() <= index)
	{
		throw std::out_of_range("out of range");;
	}
	m_shapes.erase(m_shapes.begin() + index);
}
