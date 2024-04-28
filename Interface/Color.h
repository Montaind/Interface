#pragma once
struct Color {
	inline Color(unsigned __int8 r, unsigned __int8 g, unsigned __int8 b, unsigned __int8 a) : r(r), g(g), b(b), a(a) {}
	inline Color() : r(0), g(0), b(0), a(0) {}
	inline ~Color() {}
	unsigned __int8 r;
	unsigned __int8 g;
	unsigned __int8 b;
	unsigned __int8 a;
};
