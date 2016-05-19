#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGEL_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"

class filled_rect : public drawable {
private:
	vector start;
	vector end;
	window w;
public:
	filled_rect(window & w, const vector & start, const vector & end);
	void draw() override;
};



#endif //FILLED_RECTANGLE_HPP