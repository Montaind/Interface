#pragma once
#include "IShape.h"

class Line : public IShape {
public:
	Line();
	Line(Point A, double lenght, Color color);
	Line(double x, double y, double lenght , Color color);
	~Line();
	virtual void draw(SDL_Renderer* renderer) override;
	virtual void relocate(double x, double y) override;
	virtual void relocate(Point location) override;
	virtual void scale(double s) override;
	virtual void rotate(double a) override;
	virtual bool contains(Point location) override;
	virtual bool isSelected() override;
	virtual void setSelection(bool selected) override;
private:
	void recalculate();
private:
	Point A;
	Point B;
	Color color;
	double lenght;
	double scale_kef;
	double angle;
	bool selected;
};