#include "Triangle.hpp"

Triangle::Triangle(window & w, int side_a_x, int side_a_y, int side_b_x, int side_b_y, int side_c_x, int side_c_y):
	side_a( w, side_a_x, side_a_y, side_b_x, side_b_y),
	side_b( w, side_b_x, side_b_y, side_c_x, side_c_y),
	side_c( w, side_c_x, side_c_y, side_a_x, side_a_y)
{}

void Triangle::print()
{
	side_a.print();
	side_b.print();
	side_c.print();
}