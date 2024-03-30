#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
	Circle();
	Circle(double x, double y, double radius);
	Circle(Point A, double radius);
	virtual void draw() override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	~Circle();
private:
	Point A;
	double radius;
};