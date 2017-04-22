#pragma once
#include "ICanvasPro.h"

namespace graphics_lib_pro
{

// ���������� ������ ��� ���������
class CCanvasPro : public ICanvasPro
{
public:
	void SetColor(uint32_t rgbColor) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};
};