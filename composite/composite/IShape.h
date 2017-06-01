#pragma once
#include "IDrawable.h"
#include "CommonTypes.h"
#include "IStyle.h"
#include <memory>


class IGroupShape;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() = 0;
	virtual void SetFrame(const RectD & rect) = 0;

	virtual IStylePtr GetOutlineStyle() const = 0;
	virtual void SetOutlineStyle(IStylePtr const & style) = 0;

	virtual IStylePtr GetFillStyle() const = 0;
	virtual void SetFillStyle(IStylePtr const & style) = 0;

	virtual std::shared_ptr<IGroupShape> GetGroup() = 0;
	virtual std::shared_ptr<const IGroupShape> GetGroup() const = 0;

	virtual ~IShape() = default;
};