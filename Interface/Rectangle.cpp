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

void Rectangle::draw(SDL_Renderer* renderer)
{
	SDL_RenderDrawLine(renderer, A.x, A.y, A.x + width, A.y);
	SDL_RenderDrawLine(renderer, A.x, A.y, A.x, A.y + length);
	SDL_RenderDrawLine(renderer, A.x, A.y + length, A.x + width, A.y + length);
	SDL_RenderDrawLine(renderer, A.x + width, A.y, A.x + width, A.y + length);

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

void Rectangle::scale(double s)
{
	width *= s;
	length *= s;
}

void Rectangle::rotate(double a)
{

}


