#pragma once
#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point.h"
class IShape {
public:
	virtual void draw() = 0;
	virtual void relocate(Point location) = 0;
	virtual void relocate(double x, double y) = 0;
};