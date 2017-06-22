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
	CGroup(IStylePtr const & fillStyle, IStylePtr const & outlineStyle);
	CGroup();
	~CGroup();

	void SetFrame(const RectD & rect) override;
	RectD GetFrame() const override;

	void SetOutlineStyle(IStylePtr const & style) override;
	void SetFillStyle(IStylePtr const & style) override;

	IStylePtr GetOutlineStyle() const override;
	IStylePtr GetFillStyle() const override;

	size_t GetShapesCount()const override;
	void InsertShape(const IShapePtr & shape, size_t position = std::numeric_limits<size_t>::max()) override;
	IShapePtr GetShapeAtIndex(size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	void Draw(ICanvas & canvas) const override;

private:
	void UpdateFrame();

private:

	IStylePtr m_outlineStyle;
	IStylePtr m_fillStyle;
	std::vector<IShapePtr> m_shapes;
};

