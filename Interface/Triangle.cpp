#include "Triangle.h"

Triangle::Triangle() : A(0, 0), B(0, 0), C(0, 0) {}

Triangle::Triangle(Point A, Point B, Point C) :A(A), B(B), C(C) {}

void Triangle::draw()
{
	std::cout << A.x << " " << A.y << "\n" << B.x << " " << B.y << "\n" << C.x << " " << C.y;
}

void Triangle::relocate(double x, double y)
{
	A.x += x;
	A.y += y;

	B.x += x;
	B.y += y;
	
	C.x += x;
	C.y += y;
}

void Triangle::relocate(Point location)
{
	A.x += location.x;
	A.y += location.y;

	B.x += location.x;
	B.y += location.y;

	C.x += location.x;
	C.y += location.y;
}

Triangle::~Triangle()
{
}
