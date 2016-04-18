#include "filled_rectangle.hpp"


	filled_rect::filled_rect(window & w, int start_x, int start_y, int end_x, int end_y): 
		start_x( start_x ),
		start_y( start_y ),
		end_x( end_x ),
		end_y( end_y ),
		w( w )
	{}


void filled_rect::print()
{
	
	for(int i = start_x; i < end_x + 1; i++)
	{
		for(int j = start_y; j < end_y + 1; j++)
		{
			w.draw(i, j);
		}
	}
}