#include "../stdafx.h"
#include "ModernGraphicsRendererPro.h"


// ������������ ���� ����������� ����������� ����������� ���������� (���������� ��� ���������)
namespace modern_graphics_lib_pro
{

	
	CModernGraphicsRendererPro::CModernGraphicsRendererPro(std::ostream & strm)
	: m_out(strm)
{
}

	CModernGraphicsRendererPro::~CModernGraphicsRendererPro()
{
	// ���������� �������� ��� ���������
}

// ���� ����� ������ ���� ������ � ������ ���������
void CModernGraphicsRendererPro::BeginDraw()
{
	// ���������� �������� ��� ���������
}

// ��������� ��������� �����
void CModernGraphicsRendererPro::DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color)
{
	// TODO: ������� � output ���������� ��� ��������� ����� � ����
	// <line fromX="3" fromY="5" toX="5" toY="17">
	//   <color r="0.35" g="0.47" b="1.0" a="1.0" />
	// </line>
	// ����� �������� ������ ����� BeginDraw() � EndDraw()
}

// ���� ����� ������ ���� ������ � ����� ���������
void CModernGraphicsRendererPro::EndDraw()
{
	// ���������� �������� ��� ���������
}
};
