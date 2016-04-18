// template

#include <iostream>

#include "window.hpp"
/*#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "filled_rectangle.hpp"
#include "Triangle.hpp"*/
#include "house.hpp"
#include "circle.hpp"

int main(int argc, char **argv){
   window w( (128 * 1), (64 * 1), 1 );
   
	/*smoke stack(w, 40, 30, 4);
	stack.print();*/
   
	house home (w, 30, 30, 1.5);
	home.print();
      
   /*Triangle roof(w, 40, 30, 60, 30, 50, 10);
   roof.print();*/
   
   return 0;
}
