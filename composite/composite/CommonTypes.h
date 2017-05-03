#pragma once
#include <cstdint>


template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
	Rect(T l, T t, T w, T h)
		: left(l)
		, top(t)
		, width(w)
		, height(h)
	{};
};

typedef Rect<double> RectD;
using RGBAColor = uint32_t;