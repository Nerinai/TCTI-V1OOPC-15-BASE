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
   window w( (128 * 1), (64 * 1), 1);
   
	/*smoke stack(w, 40, 30, 4);
	stack.print();*/
   
	house home (w, 10, 42, 1, 1);
	house villa (w, 40, 32, 1.5, 0);
	house mansion (w, 80, 22, 2, 1);
	home.print();
	villa.print();
	mansion.print();
   /*Triangle roof(w, 40, 30, 60, 30, 50, 10);
   roof.print();*/
   
   return 0;
}
