#include "PictureDraft.h"



CPictureDraft::CPictureDraft()
{
}


CPictureDraft::~CPictureDraft()
{
}

unsigned CPictureDraft::GetShapeCount() const
{
	return m_shapes.size();;
}

void CPictureDraft::AddShape(std::shared_ptr<CShape> & shape)
{
	m_shapes.push_back(shape);
}

std::shared_ptr<CShape> CPictureDraft::GetShape(unsigned index) const
{
	return m_shapes.at(index);
}
