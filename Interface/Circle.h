#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
	Circle(double x, double y, int radius);
	virtual void draw() override;
	virtual void relocate(double x, double y) override;
private:
	double point_x;
	double point_y;
	int radius;
};