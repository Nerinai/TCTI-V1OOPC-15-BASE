#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <rectangle.hpp>
#include <vector.hpp>
#include <stdbool.h>

class victim : public rectangle
{
	bool is_hit = false;
public:
	victim(window & w, const vector & start,const vector & end);
	~victim()
	{}
	void update() override;
	void interact(drawable & other) override;
};

#endif // VICTIM_HPP
