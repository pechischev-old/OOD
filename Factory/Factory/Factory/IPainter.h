#pragma once
#include <memory>


class CPictureDraft;
struct ICanvas;

struct IPainter
{
	virtual void DrawPicture(CPictureDraft & draft, ICanvas & canvas) = 0;
	virtual ~IPainter() = default;
};