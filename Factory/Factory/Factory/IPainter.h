#pragma once
#include <memory>
#include "ICanvas.h"
#include "PictureDraft.h"


class IPainter
{
public:
	virtual void DrawPicture(CPictureDraft & draft, ICanvas & canvas) = 0;
	virtual ~IPainter() = default;
};