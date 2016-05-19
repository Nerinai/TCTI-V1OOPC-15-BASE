#include "filled_rectangle.hpp"


	filled_rect::filled_rect(window & w, const vector & start, const vector & end ): 
		drawable(w, start, end - start),
		start ( start ),
		end ( end ),
		w ( w )
	{}


void filled_rect::draw()
{
	
	for(int i = start.x; i < end.x + 1; i++)
	{
		for(int j = start.y; j < end.y + 1; j++)
		{
			w.draw(vector (i, j));
		}
	}
}