#pragma once


namespace graphics_lib
{
	// ����� ��� ���������
	struct ICanvas
	{
		virtual void MoveTo(int x, int y) = 0;
		virtual void LineTo(int x, int y) = 0;
		virtual ~ICanvas() = default;
	};

};