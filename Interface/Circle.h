#pragma once
#include "IShape.h"
#include <cmath>


class Circle : public IShape {
public:
	Circle();
	Circle(double x, double y, double radius, Color color);
	Circle(Point A, double radius, Color color);
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	virtual void scale(double s) override;
	virtual void rotate(double a) override;
	~Circle();
private:
	Point A;
	Color color;
	double radius;
};