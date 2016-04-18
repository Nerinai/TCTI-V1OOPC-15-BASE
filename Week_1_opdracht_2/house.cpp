#include "house.hpp"

house::house( window & w, int coord_x, int coord_y, float scale):
	house_body(w, coord_x, coord_y, coord_x + (20 * scale), coord_y + (20 * scale)),
	housewindow(w, coord_x + (3 * scale), coord_y + (3 * scale), coord_x + (9 * scale), coord_y + (9 * scale)),
	darkwindow(w, coord_x + (3 * scale), coord_y + (3 * scale), coord_x + (9 * scale), coord_y + (9 * scale)),
	door(w, coord_x + (13 * scale), coord_y + (10 * scale), coord_x + (18 * scale), coord_y + (20 * scale)),
	roof(w, coord_x - 1 , coord_y, (coord_x + (20 * scale) + 1), coord_y, coord_x + (10 * scale), coord_y - ((20 / 2) * scale)),
	dakraam(w, coord_x + (10 * scale), coord_y - ((20 / 4) * scale), (3 * scale))
{
}

void house::print(){
	darkwindow.print();
	house_body.print();
	door.print();
	roof.print();
	dakraam.print();
}


