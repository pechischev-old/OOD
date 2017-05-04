#pragma once


struct ICanvas;

class IDrawable
{
public:
	virtual void Draw(ICanvas & canvas) = 0;

	virtual ~IDrawable() = default;
};