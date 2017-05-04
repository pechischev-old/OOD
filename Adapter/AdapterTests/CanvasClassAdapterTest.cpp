#include "stdafx.h"

#include "../Adapter/CanvasClassAdapter.h"

#include "../Adapter/shape_drawing_lib/Rectangle.h"
#include "../Adapter/shape_drawing_lib/Triangle.h"
#include "../Adapter/shape_drawing_lib/CanvasPainter.h"

using namespace app;
using namespace modern_graphics_lib;
using namespace shape_drawing_lib;

struct CanvasClassAdapter
{
	std::stringstream stream;
};

BOOST_FIXTURE_TEST_SUITE(canvas_class_adapter_tests, CanvasClassAdapter)

BOOST_AUTO_TEST_CASE(should_draw_line)
{
	{
		CCanvasClassAdapter adapter(stream);
		adapter.MoveTo(0, 0);
		adapter.LineTo(10, 10);
	}
	std::string expectedString = R"(<draw>
  <line fromX="0" fromY="0" toX="10" toY="10"/>
</draw>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_CASE(should_draw_rectangle)
{
	{
		CCanvasClassAdapter adapter(stream);
		CCanvasPainter painter(adapter);

		CRectangle rect({ 0, 0 }, 50, 60);
		painter.Draw(rect);
	}
	std::string expectedString = R"(<draw>
  <line fromX="0" fromY="0" toX="50" toY="0"/>
  <line fromX="50" fromY="0" toX="50" toY="60"/>
  <line fromX="50" fromY="60" toX="0" toY="60"/>
  <line fromX="0" fromY="60" toX="0" toY="0"/>
</draw>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_CASE(should_draw_triangle)
{
	{
		CCanvasClassAdapter adapter(stream);
		CCanvasPainter painter(adapter);

		CTriangle triangle({ 50, 0 }, { 0, 20 }, { 50, 20 });
		painter.Draw(triangle);
	}
	std::string expectedString = R"(<draw>
  <line fromX="50" fromY="0" toX="0" toY="20"/>
  <line fromX="0" fromY="20" toX="50" toY="20"/>
  <line fromX="50" fromY="20" toX="50" toY="0"/>
</draw>
)";
	BOOST_CHECK_EQUAL(stream.str(), expectedString);
}

BOOST_AUTO_TEST_SUITE_END()