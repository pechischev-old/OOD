#pragma once


struct ICanvas;

class IDrawable
{
public:
	virtual void Draw(ICanvas & canvas) const = 0;

	virtual ~IDrawable()  = default;
};