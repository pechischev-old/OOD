#pragma once

// ������������ ���� ����������� ����������� ����������� ���������� (���������� ��� ���������)
namespace modern_graphics_lib_pro
{

	// ���� � ������� RGBA, ������ ��������� ��������� �������� �� 0.0f �� 1.0f
	class CRGBAColor
	{
	public:
		CRGBAColor(float r, float g, float b, float a) :r(r), g(g), b(b), a(a) {}
		float r, g, b, a;
	};
};