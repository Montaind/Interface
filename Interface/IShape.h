#pragma once
#include <iostream>

class IShape {
public:
	virtual void draw() = 0;
	virtual void relocate(double x, double y) = 0;
};