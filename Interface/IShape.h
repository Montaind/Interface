#pragma once
#include <iostream>
#include "SDL.h"
#include "Point.h"
#include "Color.h"
class IShape {
public:
	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void relocate(Point location) = 0;
	virtual bool contains(Point location) = 0;
	virtual bool isSelected() = 0;
	virtual void setSelection(bool selected) = 0;
	virtual void relocate(double x, double y) = 0;
	virtual void scale(double s) = 0;
	virtual void rotate(double a) = 0;
};