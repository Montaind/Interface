#include "Rectangle.h"

Rectangle::Rectangle() : A(0, 0), width(0), length(0)
{
}

Rectangle::Rectangle(double x, double y, double width, double length) : A(x, y), width(width), length(length)
{
}

Rectangle::Rectangle(Point A, double width, double length) : A(A), width(width), length(length)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	std::cout << A.x << " " << A.y << " " << width << " " << length;
}

void Rectangle::relocate(double x, double y)
{
	A.x += x;
	A.y += y;
}

void Rectangle::relocate(Point location)
{
	A.x += location.x;
	A.y += location.y;
}


