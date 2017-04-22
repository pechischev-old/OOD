#pragma once


namespace graphics_lib
{
	// Холст для рисования
	struct ICanvas
	{
		virtual void MoveTo(int x, int y) = 0;
		virtual void LineTo(int x, int y) = 0;
		virtual ~ICanvas() = default;
	};

};