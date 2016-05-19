#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "Triangle.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"

class house
{
private:
	int ishome;
	float scale;
	rectangle house_body, housewindow, door;
	Triangle roof;
	filled_rect darkwindow;
	circle dakraam;
	

public:
	house(window & w, int x_coord, int y_coord, float scale, int ishome);
	void print();

};

#endif // HOUSE_HPP
