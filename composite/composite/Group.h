#pragma once
#include "IGroupShape.h"
#include "SimpleShape.h"
#include "Shapes.h"
#include "IGroupShape.h"

#include <memory>
#include <vector>


class CGroup
	: public IGroupShape
	, public std::enable_shared_from_this<IGroupShape>
{
public:
	CGroup(RectD const & frame, IStylePtr const & fillStyle, IStylePtr const & outlineStyle);
	CGroup(RectD const & frame);
	~CGroup();

	RectD GetFrame() override;
	void SetFrame(const RectD & rect) override;

	void SetOutlineStyle(IStylePtr const & style) override;
	void SetFillStyle(IStylePtr const & style) override;

	size_t GetShapesCount()const override;
	void InsertShape(const IShapePtr & shape, size_t position = std::numeric_limits<size_t>::max()) override;
	IShapePtr GetShapeAtIndex(size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	IStylePtr GetOutlineStyle() const override;
	IStylePtr GetFillStyle() const override;

	void Draw(ICanvas & canvas) override;

private:
	void UpdateFrame();

private:
	RectD m_frame;
	IStylePtr m_outlineStyle;
	IStylePtr m_fillStyle;
	std::vector<IShapePtr> m_shapes;
};

