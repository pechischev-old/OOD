#pragma once
#include "../graphics_lib_pro/ICanvasPro.h"

namespace shape_drawing_lib_pro
{

struct Point
{
	int x;
	int y;
};

// Интерфейс объектов, которые могут быть нарисованы на холсте из graphics_lib_pro
class ICanvasDrawable
{
public:
	virtual void Draw(graphics_lib_pro::ICanvas & canvas)const = 0;
	virtual ~ICanvasDrawable() = default;
};
};