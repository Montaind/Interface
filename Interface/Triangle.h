#pragma once
#include "IShape.h"

class Triangle : public IShape {
public:
	Triangle();
	Triangle(Point A, Point B, Point C);
	virtual void draw();
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	~Triangle();
private:
	Point A;
	Point B;
	Point C;

};