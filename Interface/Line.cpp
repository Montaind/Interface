#include "Line.h"

Line::Line() : A(0,0), B(0,0), lenght(0), scale_kef(1), angle(0), color(0,0,0,0) {}

Line::Line(Point A, double lenght, Color color) : A(A), lenght(lenght), B(A.x + lenght, A.y), scale_kef(1), angle(0), color(color) {}

Line::Line(double x, double y, double lenght, Color color) : A(x,y), lenght(lenght), B(x + lenght, y), scale_kef(1), angle(0), color(color) {}

Line::~Line() {}

void Line::draw(SDL_Renderer* renderer)
{
	if (selected) SDL_SetRenderDrawColor(renderer, 0, 68, 255, 0);
	else SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
}

void Line::relocate(double x, double y)
{
	A.x += x;
	A.y += y;
	B.x += x;
	B.y += y;
}

void Line::relocate(Point location)
{
	A.x += location.x;
	A.y += location.y;
	B.x += location.x;
	B.y += location.y;
}

void Line::scale(double s)
{
	lenght *= s;
	recalculate();
}

void Line::rotate(double a)
{
	angle += a;
	recalculate();
}

bool Line::contains(Point location)
{
	if (A.y == B.y) {
		return (location.y == A.y && location.x >= A.x && location.x <= B.x);
	}
	return (location.x - A.x) / (B.x - A.x) == (location.y - A.y) / (B.y - A.y);
}

void Line::setSelection(bool selected)
{
	this->selected = selected;
}

bool Line::isSelected()
{
	return selected;
}

void Line::recalculate() {
	B.x = A.x + lenght * scale_kef;
	B.y = A.y;
	B.x = B.x * cos(angle) + B.y * sin(angle);
	B.y = B.x * sin(angle) + B.y * cos(angle);
}
