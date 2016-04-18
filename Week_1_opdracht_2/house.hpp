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
	float scale;
	rectangle house_body, housewindow;
	Triangle roof;
	filled_rect darkwindow, door;
	circle dakraam;
	

public:
	house(window & w, int x_coord, int y_coord, float scale);
	void print();

};

#endif // HOUSE_HPP
