#pragma once
#include "IShape.h"

class Triangle : public IShape {
public:
	Triangle();
	Triangle(Point A, Point B, Point C, Color color);
	virtual void draw(SDL_Renderer* renderer);
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	virtual void scale(double s) override;
	virtual void rotate(double a) override;
	~Triangle();
private:
	Color color;
	Point A;
	Point B;
	Point C;

};