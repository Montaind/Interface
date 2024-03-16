#include "Circle.h"

Circle::Circle(double x, double y, int radius)
{
	point_x = x;
	point_y = y;
	this->radius = radius;
}

void Circle::draw()
{
	std::cout << point_x << " " << point_y << " " << radius << "\n";
}

void Circle::relocate(double x, double y)
{
	point_x = x;
	point_y = y;
}

