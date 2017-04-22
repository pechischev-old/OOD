#include "../stdafx.h"
#include "ModernGraphicsRenderer.h"

namespace modern_graphics_lib
{
	CModernGraphicsRenderer::CModernGraphicsRenderer(std::ostream & strm) 
		: m_out(strm)
	{
	}

	CModernGraphicsRenderer::~CModernGraphicsRenderer() 
	{
		if (m_drawing) // ��������� ���������, ���� ��� ���� ������
		{
			EndDraw();
		}
	}

	void CModernGraphicsRenderer::BeginDraw()
	{
		if (m_drawing)
		{
			throw std::logic_error("Drawing has already begun");
		}
		m_out << "<draw>" << std::endl;
		m_drawing = true;
	}

	// ��������� ��������� �����
	void CModernGraphicsRenderer::DrawLine(const CPoint & start, const CPoint & end)
	{
		if (!m_drawing)
		{
			throw std::logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
		}
		m_out << boost::format(R"(  <line fromX="%1%" fromY="%2" toX="%3%" toY="%4%"/>)") << std::endl;
	}

	// ���� ����� ������ ���� ������ � ����� ���������
	void CModernGraphicsRenderer::EndDraw()
	{
		if (!m_drawing)
		{
			throw std::logic_error("Drawing has not been started");
		}
		m_out << "</draw>" << std::endl;
		m_drawing = false;
	}
};