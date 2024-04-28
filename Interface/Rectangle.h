#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	Rectangle();
	Rectangle(double x, double y, double width, double length, Color color);
	Rectangle(Point A, double width, double length, Color color);
	~Rectangle();
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	virtual void scale(double s) override;
	virtual void rotate(double a) override;
	virtual bool contains(Point location) override;
	virtual bool isSelected() override;
	virtual void setSelection(bool selected) override;
private:
	bool selected;
	Color color;
	Point A;
	double width;
	double length;
};