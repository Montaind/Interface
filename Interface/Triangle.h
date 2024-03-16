#pragma once
#include "IShape.h"

class Triangle : public IShape {
public:
	Triangle(int A, int B, int C, int x, int y);
	virtual void draw();
	virtual void relocate(double x, double y);
private:
	double point_A;
	double point_B;
	double point_C;
	double point_x;
	double point_y;
};