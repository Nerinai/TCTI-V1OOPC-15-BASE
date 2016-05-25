// example:
// declaration of a rectangle object that is contains four line objects

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "line.hpp"

class rectangle : public drawable {
protected:
   vector end;
   line left;
   line right;
   line top;
   line bottom;
public:
   rectangle( window & w, const vector & start, const vector & end );
   rectangle( window & w, const vector & start, const vector & end, const vector & bounce );
   void draw() override;
   void update_lines();
};


#endif // RECTANGLE_HPP
