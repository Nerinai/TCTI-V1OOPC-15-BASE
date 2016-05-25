#ifndef LINE_HPP
#define LINE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class line : public drawable {
private:
vector end;
public:

   line( window & w, const vector & location, const vector & end ):
      drawable( w, location, end - location ),
      end( end )
   {}
   void draw() override;
   void update(vector n_end, vector n_location);
};

#endif // LINE_HPP
