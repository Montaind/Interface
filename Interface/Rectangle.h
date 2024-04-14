#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	Rectangle();
	Rectangle(double x, double y, double width, double length);
	Rectangle(Point A, double width, double length);
	~Rectangle();
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
private:
	Point A;
	double width;
	double length;
};