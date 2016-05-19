#ifndef WALL_HPP
#define WALL_HPP

#include "stdbool.h"
#include "vector.hpp"
#include "rectangle.hpp"
#include "filled_rectangle.hpp"

class wall : public rectangle
{
private:
	
	vector start;
	vector end;
	int update_interval = 0;
	bool filled = true;
	int update_count = 0;
	
public:
	wall(window & w, const vector & start, const vector & end, int update_interval, const vector & bounce);
	void draw() override;
	void update() override;
};

#endif // WALL_HPP
