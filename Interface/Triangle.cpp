#include "Triangle.h"

Triangle::Triangle(int A, int B, int C, int x, int y)
{
	point_A = A;
	point_B = B;
	point_C = C;
	point_x = x;
	point_y = y;
}

void Triangle::draw()
{
	std::cout << point_A << " " << point_B << " " << point_C << "\n";
}

void Triangle::relocate(double x, double y)
{
	point_x = x;
	point_y = y;
}
