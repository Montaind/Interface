#include <iostream>
#include "IShape.h"
#include <vector>

typedef std::vector<IShape*> IShapeVector;

int main() {
	IShapeVector shapes;
	shapes.push_back(new Circle(*new Point(2, 3), 5));
	shapes.push_back(new Circle(*new Point(4, 7), 10));
	shapes.push_back(new Circle(*new Point(6, 2), 3));
	shapes.push_back(new Triangle(*new Point(3, 2), *new Point(4, 1), *new Point(9, 5)));
}