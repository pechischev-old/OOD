#pragma once

#include "IShape.h"
#include "IDrawable.h"
#include "StrokeStyle.h"


struct ICanvas;

class CShape : public IShape
{
public:
	CShape(RectD const & frame, IStylePtr const & fillStyle = std::make_shared<CStyle>(false, 0xFFFFFF), IStylePtr const & outlineStyle = std::make_shared<CStrokeStyle>(true, 0xFF0000, 1.f));
	RectD GetFrame() override;
	void SetFrame(const RectD & frame) override;

	virtual IStylePtr GetOutlineStyle() const override;
	virtual void SetOutlineStyle(IStylePtr const & style) override;

	virtual IStylePtr GetFillStyle() const override;
	virtual void SetFillStyle(IStylePtr const & style) override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	void Draw(ICanvas & canvas) override;

	virtual ~CShape() = default;

protected:
	virtual void DrawImpl(ICanvas & canvas) = 0;

private:
	RectD m_frame;
	IStylePtr m_outlineStyle;
	IStylePtr m_fillStyle;
};