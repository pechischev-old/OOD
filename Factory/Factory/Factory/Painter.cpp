#include "Painter.h"
#include "ICanvas.h"
#include "PictureDraft.h"
#include <algorithm>

CPainter::CPainter()
{
}

CPainter::~CPainter()
{
}

void CPainter::DrawPicture(const CPictureDraft & draft, ICanvas & canvas)
{
	canvas.BeginDraw();
	std::for_each(draft.begin(), draft.end(), [&](const CShape &shape) {
		shape.Draw(canvas);
	});
	canvas.EndDraw();
}
