#include "wall.hpp"

wall::wall(window & w, const vector & location, const vector & end, int update_interval, const vector & bounce):
	rectangle(w, location, end, bounce),
	update_interval(update_interval)
{}

void wall::update()
{
	update_count++;
	if (update_interval == update_count)
	{
		update_count = 0;
		if (filled == true)
		{
			filled = false;
		}
		else
		{
			filled = true;
		}
	}
}

void wall::draw()
{
		if (filled == true)
		{
			for (int i = location.x; i < end.x + 1; i++)
			{
				for (int j = location.y; j < end.y + 1; j++ )
				{
					w.draw(vector(i , j));
				}
			}
		}
		else
		{
			rectangle::draw();
		}
}