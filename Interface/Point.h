#pragma once
struct Point {
	inline Point() : x(0), y(0) {}
	inline Point(double x, double y) : x(x), y(y) {}
	inline ~Point() {}
	double x;
	double y;
};