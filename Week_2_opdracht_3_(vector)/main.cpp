#include "ostream"
#include "catch_with_main.hpp"
#include "vector.hpp"


TEST_CASE( "constructors, default" )
{
	vector v (1,7);
	REQUIRE( v == vector(1,7) );   
}

TEST_CASE ( "+ operator, 2 vectors and 3 vectors" )
{
	vector v (1,9), r (2,3), x (2,2), res1 ,res2;
	
	res1 = v + r;
	res2 = v + r + x;
	
	REQUIRE( res1 == vector(3,12) );
	REQUIRE( res2 == vector(5,14) );
}

TEST_CASE ( "+ operator, 2 vectors, negative values" )
{
	vector v (-1,-4), r(2,1), x (-3,4), res1, res2, res3;
	
	res1 = v + r;
	res2 = v + x;
	res3 = r + x;
	
	REQUIRE( res1 == vector(1,-3) );
	REQUIRE( res2 == vector(-4,0) );
	REQUIRE( res3 == vector(-1,5) );
}

TEST_CASE ( "+= operator, 2 vectors, positive and negative values" )
{
	vector v (1,9), r (2,3), x (-1,-3);
	
	v += r;
	r += x;
	
	REQUIRE( v == vector(3,12) );
	REQUIRE( r == vector(1,0) );
}

TEST_CASE ( "- operator, 2 vectors and 3 vectors" )
{
	vector v (1,9), r (2,3), x (2,2), res1 ,res2;
	
	res1 = v - r;
	res2 = v - r - x;
	
	REQUIRE( res1 == vector(-1,6) );
	REQUIRE( res2 == vector(-3,4) );
}

TEST_CASE ( "- operator, 2 vectors, negative values" )
{
	vector v (-1,-3), r(2,1), x (-3,4), res1, res2, res3;
	
	res1 = v - r;
	res2 = v - x;
	res3 = r - x;
	
	REQUIRE( res1 == vector(-3,-4) );
	REQUIRE( res2 == vector(2,-7) );
	REQUIRE( res3 == vector(5,-3) );
}

TEST_CASE ( "-= operator, 2 vectors, positive and negative values" )
{
	vector v (1,9), r (2,3), x (-1,-3);
	
	v -= r;
	r -= x;
	
	REQUIRE( v == vector(-1,6) );
	REQUIRE( r == vector(3,6) );
}

TEST_CASE ( "* operator, int multiplied with vector" )
{
	vector v (1,1), res1, res2;
	res1 = 2 * v;
	res2 = v * 2;
	
	REQUIRE( res1 == vector(2,2) );
	REQUIRE( res2 == vector(2,2) );
}

TEST_CASE ( "*= operator, 2 vectors, positive and negative values" )
{
	vector v (1,9);
	
	v *= 3;
	
	REQUIRE( v == vector(3,27) );
}

TEST_CASE ( "/ operator, int multiplied with vector" )
{
	vector v (2,2), res1, res2;
	res1 = 2 / v;
	res2 = v / 2;
	
	REQUIRE( res1 == vector(1,1) );
	REQUIRE( res2 == vector(1,1) );
}

TEST_CASE ( "/= operator, 2 vectors, positive and negative values" )
{
	vector v (3,9);
	
	v /= 3;
	
	REQUIRE( v == vector(1,3) );
}