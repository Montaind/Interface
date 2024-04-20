#pragma once
#include "IShape.h"
#include <cmath>


class Circle : public IShape {
public:
	Circle();
	Circle(double x, double y, double radius);
	Circle(Point A, double radius);
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	~Circle();
private:
	Point A;
	double radius;
};