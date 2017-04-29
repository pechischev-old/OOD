#pragma once
#include <cstdint>

namespace graphics_lib_pro
{

// ����� ��� ���������
struct ICanvas
{
	// ��������� ����� � ������� 0xRRGGBB
	virtual void SetColor(uint32_t rgbColor) = 0;
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;
	virtual ~ICanvas() = default;
};
};