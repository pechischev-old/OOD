#pragma once
#include <iostream>
#include "RGBAColor.h"

// ������������ ���� ����������� ����������� ����������� ���������� (���������� ��� ���������)
namespace modern_graphics_lib_pro
{

class CPoint
{
public:
	CPoint(int x, int y) :x(x), y(y) {}

	int x;
	int y;
};

// ����� ��� ������������ ��������� �������
class CModernGraphicsRendererPro
{
public:
	CModernGraphicsRendererPro(std::ostream & strm);

	~CModernGraphicsRendererPro();

	// ���� ����� ������ ���� ������ � ������ ���������
	void BeginDraw();

	// ��������� ��������� �����
	void DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color);

	// ���� ����� ������ ���� ������ � ����� ���������
	void EndDraw();
private:
	std::ostream & m_out;
	bool m_drawing = false;
};
};