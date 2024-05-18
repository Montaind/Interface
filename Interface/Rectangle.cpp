#include "Rectangle.h"

Rectangle::Rectangle() : A(0, 0), width(0), length(0), color(0,0,0,0), selected(false)
{
	recalculate();
}

Rectangle::Rectangle(double x, double y, double width, double length, Color color) : center(x, y), width(width), length(length), color(color), selected(false)
{
	recalculate();
}

Rectangle::Rectangle(Point center, double width, double length, Color color) : center(center), width(width), length(length), color(color), selected(false)
{
	recalculate();
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(SDL_Renderer* renderer)
{
	if (selected) SDL_SetRenderDrawColor(renderer, 0, 68, 255, 0);
	else SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	
	SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
	SDL_RenderDrawLine(renderer, A.x, A.y, D.x, D.y);
	SDL_RenderDrawLine(renderer, D.x, D.y, C.x, C.y);
	SDL_RenderDrawLine(renderer, B.x, B.y, C.x, C.y);

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
	scale_kef = s;
	recalculate();
}

void Rectangle::rotate(double a)
{
	angle += a;
	recalculate();
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

void Rectangle::recalculate()
{
	double width_buffed = width * scale_kef;
	double length_buffed = length * scale_kef;
	A.x = (center.x - width_buffed/ 2);
	A.y = (center.y - length_buffed / 2);
	B.x = (center.x + width_buffed / 2);
	B.y = (center.y - length_buffed / 2);
	C.x = (center.x + width_buffed / 2);
	C.y = (center.y + length_buffed / 2);
	D.x = (center.x - width_buffed / 2);
	D.y = (center.y + length_buffed / 2);
	
	A = rotatePoint(A);
	B = rotatePoint(B);
	C = rotatePoint(C);
	D = rotatePoint(D);

	A.x += center.x;
	A.y += center.y;
	B.x += center.x;
	B.y += center.y;
	C.x += center.x;
	C.y += center.y;
	D.x += center.x;
	D.y += center.y;
}

Point Rectangle::rotatePoint(Point point)
{
	double x_rel = 0;
	double y_rel = 0;
	if (angle < 0)
	{
		double a = angle * -1;
		x_rel = point.x * cos(a) + point.y * sin(a);
		y_rel = -1 * point.x * sin(a) + point.y * cos(a);
	}
	else
	{
		x_rel = point.x * cos(angle) - point.y * sin(angle);
		y_rel = point.x * sin(angle) + point.y * cos(angle);
	}
	return Point(x_rel, y_rel);
}


