#include "victim.hpp"
#include "stdio.h"
victim::victim(window & w, const vector & start, const vector & end):
	rectangle(w, start, end)
{}

void victim::update()
{
	if ((is_hit == true) && (size > vector (0,0)))
	{
		end -= vector(1,1);
		location += vector(1,1);
		size = end - location;
		rectangle::update_lines();
	}
}

void victim::interact(drawable & other)
{
	if (this != & other)
	{
		if (overlaps(other))
		{
			is_hit = true;
		}
	}
}