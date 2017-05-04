#pragma once
#include "IGroupShape.h"
#include "SimpleShape.h"


class CGroup 
	: public IGroupShape
	, public CShape
{
public:
	CGroup(RectD const & frame, IStylePtr const & fillStyle, IStylePtr const & outlineStyle);
	~CGroup();

	size_t GetShapesCount()const = 0;
	void InsertShape(const std::shared_ptr<IShape> & shape, size_t position = std::numeric_limits<size_t>::max()) = 0;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) = 0;
	void RemoveShapeAtIndex(size_t index) = 0;

	void SetFrame(const RectD & rect) override final;

	/*IStyle & GetOutlineStyle() override;

	IStyle & GetFillStyle() override;
	const IStyle & GetFillStyle()const override;*/

	std::shared_ptr<IGroupShape> GetGroup() override final;
	std::shared_ptr<const IGroupShape> GetGroup() const override final;
private:

};

