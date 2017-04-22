#pragma once
#include <iostream>
#include "graphics_lib/Canvas.h"
#include "shape_drawing_lib/CanvasPainter.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"
#include "shape_drawing_lib/Rectangle.h"
#include "shape_drawing_lib/Triangle.h"


// ������������ ���� ���������� (�������� ��� �����������)
namespace app
{

	void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
	{
		using namespace shape_drawing_lib;

		CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
		CRectangle rectangle({ 30, 40 }, 18, 24);

	// TODO: ���������� ������������� � ����������� ��� ������ painter
	}

	void PaintPictureOnCanvas()
	{
		graphics_lib::CCanvas simpleCanvas;
		shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
		PaintPicture(painter);
	}

	void PaintPictureOnModernGraphicsRenderer()
	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);
		(void)&renderer; // ��������� �������������� � �������������� ����������

						 // TODO: ��� ������ ������������ ������� PaintPicture() ����������
						 // ������� �� renderer
						 // ���������: ����������� ������� "�������"
	}
}