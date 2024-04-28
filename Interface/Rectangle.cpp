#include "Rectangle.h"

Rectangle::Rectangle() : A(0, 0), width(0), length(0), color(0,0,0,0), selected(false)
{
}

Rectangle::Rectangle(double x, double y, double width, double length, Color color) : A(x, y), width(width), length(length), color(color), selected(false)
{
}

Rectangle::Rectangle(Point A, double width, double length, Color color) : A(A), width(width), length(length), color(color), selected(false)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(SDL_Renderer* renderer)
{
	if (selected) SDL_SetRenderDrawColor(renderer, 0, 68, 255, 0);
	else SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	
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

bool Rectangle::contains(Point location)
{
	if (location.x >= A.x && location.x <= A.x + width && location.y >= A.y && location.y <= A.y + length) {
		return true;
	}
	return false;
}

bool Rectangle::isSelected()
{
	return selected;
}

void Rectangle::setSelection(bool selected)
{
	this->selected = selected;
}


