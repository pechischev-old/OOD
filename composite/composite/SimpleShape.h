#pragma once

#include "IShape.h"
#include "IDrawable.h"


class ICanvas;

class CShape : public IShape
{
public:
	CShape(RectD const & frame, IStyle & fillStyle, IStyle & outlineStyle);
	RectD GetFrame() override;
	void SetFrame(const RectD & frame) override;

	IStyle & GetOutlineStyle() override;
	const IStyle & GetOutlineStyle()const override;

	IStyle & GetFillStyle() override;
	const IStyle & GetFillStyle()const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	void Draw(ICanvas & canvas) override;

	virtual ~CShape() = default;

protected:
	virtual void DrawImpl(ICanvas & canvas) = 0;

private:
	RectD m_frame;
	IStyle & m_outlineStyle;
	IStyle & m_fillStyle;
};