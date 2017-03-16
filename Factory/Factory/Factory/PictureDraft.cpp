#include "PictureDraft.h"



CPictureDraft::CPictureDraft()
{
}


CPictureDraft::~CPictureDraft()
{
}

bool CPictureDraft::IsEmpty() const
{
	return m_shapes.empty();
}

CPictureDraft::ConstIterator CPictureDraft::begin() const
{
	return m_shapes.begin();
}

CPictureDraft::ConstIterator CPictureDraft::end() const
{
	return m_shapes.end();
}

void CPictureDraft::AddShape(std::unique_ptr<CShape>&& shape)
{
	m_shapes.push_back(std::move(shape));
}
