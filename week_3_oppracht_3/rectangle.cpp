// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end ):
   drawable( w, start, end - start),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}

rectangle::rectangle( window & w, const vector & start, const vector & end, const vector & bounce ):
   drawable(w, start, end - start, bounce),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}


void rectangle::draw(){
	if (size > vector (0,0)){
		left.draw();
		right.draw();
		top.draw();
		bottom.draw();
	}
}

void rectangle::update_lines(){
	left.update(vector(location.x, location.y), vector(location.x, end.y));
	right.update(vector(end.x, location.y), vector(end.x, end.y));
	top.update (vector(location.x, location.y), vector(end.x, location.y));
	bottom.update(vector(location.x, end.y), vector(end.x, end.y));
}