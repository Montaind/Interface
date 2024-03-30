#include "Circle.h"

Circle::Circle() : A(0, 0), radius(0) {}

Circle::Circle(double x, double y, double radius) : A(x, y), radius(radius) {}

Circle::Circle(Point A, double radius) : A(A), radius(radius){}

void Circle::draw()
{
	std::cout << A.x << " " << A.y << " " << radius;
}

void Circle::relocate(double x, double y)
{
	A.x += x;
	A.y = y;
}

void Circle::relocate(Point location)
{
	A.x += location.x;
	A.y += location.y;
}

Circle::~Circle()
{
}

