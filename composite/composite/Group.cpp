#include "stdafx.h"
#include "Group.h"
#include "Style.h"

#include <cmath>



CGroup::CGroup(IStylePtr const & fillStyle, IStylePtr const & outlineStyle)
	: m_fillStyle(fillStyle)
	, m_outlineStyle(outlineStyle)
{
}

CGroup::CGroup()
{
}


CGroup::~CGroup()
{
}


size_t CGroup::GetShapesCount() const
{
	return m_shapes.size();
}

void CGroup::InsertShape(const IShapePtr & shape, size_t position)
{
	if (position > m_shapes.size())
	{
		m_shapes.push_back(shape);
	}
	else
	{
		m_shapes.insert(m_shapes.begin() + position, shape);
	}
	UpdateFrame();
}

IShapePtr CGroup::GetShapeAtIndex(size_t index)
{
	if (m_shapes.size() <= index)
	{
		throw std::out_of_range("out of range");;
	}
	return m_shapes[index];
}

void CGroup::RemoveShapeAtIndex(size_t index)
{
	if (m_shapes.size() <= index)
	{
		throw std::out_of_range("out of range");
	}
	m_shapes.erase(m_shapes.begin() + index);
	UpdateFrame();
}

void CGroup::SetFrame(const RectD & frame)
{
	auto oldFrame = GetFrame();

	double scaleX = frame.width / oldFrame.width;
	double scaleY = frame.height / oldFrame.height;

	for (auto & shape : m_shapes) 
	{
		auto shapeFrame = shape->GetFrame();
		double paddingX = shapeFrame.left - oldFrame.left;
		double paddingY = shapeFrame.top - oldFrame.top;

		shapeFrame.left = frame.left + paddingX * scaleX;
		shapeFrame.top = frame.top + paddingY * scaleY;
		shapeFrame.width *= scaleX;
		shapeFrame.height *= scaleY;

		shape->SetFrame(shapeFrame);
	};
}

RectD CGroup::GetFrame() const
{
	if (m_shapes.empty())
	{
		return RectD(0, 0, 0, 0);
	}
	RectD rect = m_shapes.front()->GetFrame();
	for (auto &shape : m_shapes)
	{
		auto shapeRect = shape->GetFrame();
		rect.left = std::min(shapeRect.left, rect.left);
		rect.top = std::min(shapeRect.top, rect.top);
		rect.width = std::max(shapeRect.width, rect.width);
		rect.height = std::max(shapeRect.height, rect.height);
	}
	return rect;
}

void CGroup::SetOutlineStyle(IStylePtr const & style)
{
	std::for_each(m_shapes.begin(), m_shapes.end(), [&](auto & shape) {
		shape->SetOutlineStyle(style);
	});
}

void CGroup::SetFillStyle(IStylePtr const & style)
{
	std::for_each(m_shapes.begin(), m_shapes.end(), [&](auto & shape) {
		shape->SetFillStyle(style);
	});
}

std::shared_ptr<IGroupShape> CGroup::GetGroup()
{
	return shared_from_this();
}

std::shared_ptr<const IGroupShape> CGroup::GetGroup() const
{
	return shared_from_this();
}

IStylePtr CGroup::GetOutlineStyle() const
{
	IStylePtr style = std::make_shared<CStrokeStyle>();
	for (auto &shape : m_shapes)
	{
		if (!style)
		{
			style = shape->GetOutlineStyle();
		}
		else if (style != shape->GetOutlineStyle())
		{
			return style;
		}
	}
	return style;
}

IStylePtr CGroup::GetFillStyle() const
{
	IStylePtr style = std::make_shared<CStyle>();
	for (auto &shape : m_shapes)
	{
		if (!style)
		{
			style = shape->GetFillStyle();
		}
		else if (style != shape->GetFillStyle())
		{
			return style;
		}
	}
	return style;
}

void CGroup::Draw(ICanvas & canvas) const
{
	for (auto shape : m_shapes)
	{
		shape->Draw(canvas);
	}
}

void CGroup::UpdateFrame()
{
	auto left = std::numeric_limits<double>::max();
	auto top = std::numeric_limits<double>::max();
	auto bottom = std::numeric_limits<double>::min();
	auto right = std::numeric_limits<double>::min();
	for (auto & shape : m_shapes)
	{
		RectD rect = shape->GetFrame();
		left = std::min(left, rect.left);
		top = std::min(top, rect.top);
		bottom = std::max(bottom, rect.top + rect.height);
		right = std::max(bottom, rect.left + rect.width);
		shape->SetFrame(RectD(left, top, right - left, bottom - top));
	}
}
