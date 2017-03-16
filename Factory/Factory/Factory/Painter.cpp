#include "Painter.h"
#include "ICanvas.h"
#include "PictureDraft.h"

CPainter::CPainter()
{
}

CPainter::~CPainter()
{
}

void CPainter::DrawPicture(CPictureDraft & draft, ICanvas & canvas)
{
	for (size_t i = 0; i < draft.GetShapeCount(); ++i)
	{
		canvas.OutputText("---- Begin draw shape -----");
		auto shape = draft.GetShape(i);
		shape->Draw(canvas);
		canvas.OutputText("---- End draw shape -----");
	}
}
