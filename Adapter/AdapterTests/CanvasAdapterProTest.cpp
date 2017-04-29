#include "stdafx.h"

#include "../Adapter/CanvasAdapterPro.h"

#include "../Adapter/shape_drawing_lib_pro/RectanglePro.h"
#include "../Adapter/shape_drawing_lib_pro/TrianglePro.h"
#include "../Adapter/shape_drawing_lib_pro/CanvasPainterPro.h"

using namespace app;
using namespace modern_graphics_lib_pro;
using namespace shape_drawing_lib_pro;

struct CanvasAdapterPro
{
	std::stringstream stream;
	CCanvasAdapterPro adapter;
	CanvasAdapterPro()
		: adapter(stream)
	{
	}
};
// TODO: call destruct adapter
BOOST_FIXTURE_TEST_SUITE(canvas_adapter_pro_tests, CanvasAdapterPro)

BOOST_AUTO_TEST_CASE(should_draw_line)
{
	adapter.MoveTo(0, 0);
	adapter.LineTo(10, 10);
	std::string expectedString = R"(<draw>
  <line fromX="0" fromY="0" toX="10" toY="10">
    <color r="0.00" g="0.00" b="0.00" a="1.00"/>
  </line>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_CASE(should_draw_green_rectangle)
{
	CCanvasPainter painter(adapter);

	CRectangle rect({ 0, 0 }, 50, 60, 0x00FF00);
	painter.Draw(rect);
	std::string expectedString = R"(<draw>
  <line fromX="0" fromY="0" toX="50" toY="0">
    <color r="0.00" g="1.00" b="0.00" a="1.00"/>
  </line>
  <line fromX="50" fromY="0" toX="50" toY="60">
    <color r="0.00" g="1.00" b="0.00" a="1.00"/>
  </line>
  <line fromX="50" fromY="60" toX="0" toY="60">
    <color r="0.00" g="1.00" b="0.00" a="1.00"/>
  </line>
  <line fromX="0" fromY="60" toX="0" toY="0">
    <color r="0.00" g="1.00" b="0.00" a="1.00"/>
  </line>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_CASE(should_draw_blue_triangle)
{
	CCanvasPainter painter(adapter);

	CTriangle triangle({ 50, 0 }, { 0, 20 }, { 50, 20 }, 0x0000FF);
	painter.Draw(triangle);
	std::string expectedString = R"(<draw>
  <line fromX="50" fromY="0" toX="0" toY="20">
    <color r="0.00" g="0.00" b="1.00" a="1.00"/>
  </line>
  <line fromX="0" fromY="20" toX="50" toY="20">
    <color r="0.00" g="0.00" b="1.00" a="1.00"/>
  </line>
  <line fromX="50" fromY="20" toX="50" toY="0">
    <color r="0.00" g="0.00" b="1.00" a="1.00"/>
  </line>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()