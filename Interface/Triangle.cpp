#include "Triangle.h"

Triangle::Triangle() : A(0, 0), B(0, 0), C(0, 0), color(color) {}

Triangle::Triangle(Point A, Point B, Point C, Color color) :A(A), B(B), C(C), color(color) {}

void Triangle::draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
	SDL_RenderDrawLine(renderer, B.x, B.y, C.x, C.y);
	SDL_RenderDrawLine(renderer, A.x, A.y, C.x, C.y);
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

void Triangle::scale(double s)
{

}

void Triangle::rotate(double a)
{

}

Triangle::~Triangle()
{
}
