#include "Group.h"



CGroup::CGroup(RectD const & frame, IStylePtr const & fillStyle, IStylePtr const & outlineStyle)
	: CShape(frame, fillStyle, outlineStyle)
{
}


CGroup::~CGroup()
{
}

size_t CGroup::GetShapesCount() const
{
	return size_t();
}

void CGroup::InsertShape(const std::shared_ptr<IShape>& shape, size_t position)
{
}

std::shared_ptr<IShape> CGroup::GetShapeAtIndex(size_t index)
{
	return std::shared_ptr<IShape>();
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
}

void CGroup::SetFrame(const RectD & rect)
{
}

//IStyle & CGroup::GetOutlineStyle()
//{
//	
//}
//
//IStyle & CGroup::GetFillStyle()
//{
//	// TODO: вставьте здесь оператор return
//}
//
//const IStyle & CGroup::GetFillStyle() const
//{
//	// TODO: вставьте здесь оператор return
//}

std::shared_ptr<IGroupShape> CGroup::GetGroup()
{
	return std::shared_ptr<IGroupShape>();
}

std::shared_ptr<const IGroupShape> CGroup::GetGroup() const
{
	return std::shared_ptr<const IGroupShape>();
}
