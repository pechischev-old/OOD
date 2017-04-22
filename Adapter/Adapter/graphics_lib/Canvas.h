#pragma once
#include <iostream>
#include "ICanvas.h"


// ������������ ���� ����������� ���������� (���������� ��� ���������)
namespace graphics_lib
{


// ���������� ������ ��� ���������
class CCanvas : public ICanvas
{
public:
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};

};