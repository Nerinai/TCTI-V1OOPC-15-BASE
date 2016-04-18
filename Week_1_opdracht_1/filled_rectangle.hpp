#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGEL_HPP

#include "window.hpp"


class filled_rect {
private:
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	window & w;
public:
	filled_rect(window & w, int start_x, int start_y, int end_x, int end_y);
	void print();
};



#endif //FILLED_RECTANGLE_HPP