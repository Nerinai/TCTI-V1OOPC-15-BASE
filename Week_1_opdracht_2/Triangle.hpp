#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "window.hpp"
#include "line.hpp"

class Triangle
{
private:
	line side_a, side_b, side_c;
public:
	Triangle(window & w, int side_a_x, int side_a_y, int side_b_x, int side_b_y, int side_c_x, int side_c_y);
	void print();
};

#endif // TRIANGLE_HPP
