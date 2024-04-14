#pragma once
#include <iostream>
#include "SDL.h"
#include "Point.h"
class IShape {
public:
	virtual void draw(SDL_Renderer* renderer) = 0;
	virtual void relocate(Point location) = 0;
	virtual void relocate(double x, double y) = 0;
};