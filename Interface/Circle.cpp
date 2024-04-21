#include "Circle.h"

Circle::Circle() : A(0, 0), radius(0) {}

Circle::Circle(double x, double y, double radius) : A(x, y), radius(radius) {}

Circle::Circle(Point A, double radius) : A(A), radius(radius){}

void Circle::draw(SDL_Renderer* renderer)
{
	int x;
	int y;
	int x0 = A.x + radius;
	int y0 = A.y + radius;

	double round = M_PI * 2;
	for (double a = 0; a <= round; a += 0.001)
	{
		x = x0 + radius * cos(a);
		y = y0 + radius * sin(a);
		SDL_RenderDrawPoint(renderer, x, y);
	}
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

void Circle::scale(double s)
{

}

void Circle::rotate(double a)
{

}

Circle::~Circle()
{
}

