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
	B.x = lenght * scale_kef;
	B.y = 0;
	double x_rel = 0;
	double y_rel = 0;
	if (angle < 0)
	{
		double a = angle * -1;
		B.x = B.x * cos(a) + B.y * sin(a);
		B.y = -1 * B.x * sin(a) + B.y * cos(a);
	}
	else
	{
		x_rel = B.x * cos(angle) - B.y * sin(angle);
		y_rel = B.x * sin(angle) + B.y * cos(angle);
	}
	
	B.x = A.x + x_rel;
	B.y = A.y + y_rel;

	std::cout << "B.x: " << B.x << " " << "B.y: " << B.y << " " << "lenght: " << lenght << " " << "scale_kef: " << " " << scale_kef << " " << "angle: " << angle << " " << "sin: " << sin(angle) << " " << "cos: " << cos(angle) << "\n";
}
