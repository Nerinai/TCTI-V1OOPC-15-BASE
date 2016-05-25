#ifndef VECTOR_HPP
#define VECTOR_HPP
/// @file

/// ADT vector

/// This is an ATD that implements two dimensional Vectors.
/// Vectors are stored as two (signed) integers.
/// Apropriate operators and constructors are provided.

class vector
{
public:
	int x;
	int y; 

/// Construcor for initializing a vector.
/// Takes the x and the y integer form user input.
	vector( int x, int y ): 
		x( x ), y( y )
	{}

/// Constructor for initializing a vector when no user input has been givien
/// Vector will be initialized with x = 0 and y = 0.
	vector():
		x(), y()
	{}
	
/// Operator to compare two vectors.
/// Returns a boolean statement weither the vectors are equal or not.
	bool operator==(const vector & rhs )
	{
		return (x == rhs.x ) && (y == rhs.y );
	}

/// Output operator for vectors.
/// Returns the vector with the annotation style of "(x,y)".
/// Values are printed as decimal values.
	friend std::ostream & operator<<( std::ostream & lhs, const vector & rhs )
	{
		lhs << "(" << rhs.x << "," << rhs.y << ")";
		return lhs;
	}
	
/// + Operator for vectors.
/// Returns the sum of the vectors without changing the original vectors. 
	vector operator+(const vector rhs) const
	{
		return vector (x + rhs.x, y + rhs.y);
	}
	
/// += Operator for vectors.
/// Reurns the sum of the vectors stored in the lhs value.
	vector operator+=(const vector & rhs)
	{
		x = x + rhs.x;
		y = y + rhs.y;
		return *this;
	}
	
/// - Operator for vectors.
/// Returns a vector with the value of the vectors substracted from eachother
/// without changing the original vectors.
	vector operator-(const vector rhs) const
	{
		return vector (x - rhs.x, y - rhs.y);
	}
	
/// -= Operator for vectors.
/// Returns the substracted value of the vectors stored in the lhs value.
	vector operator-=(const vector & rhs)
	{
		x = x - rhs.x;
		y = y - rhs.y;
		return *this;
	}
	
/// * Operator for vectors
/// Multiplies a vector with an integer.
/// Overload for "vector * int"
/// Returns the value without changing the original vector.
	vector operator*(const int rhs) const
	{
		return vector ( rhs * x, rhs * y);
	}
	
/// *= operator for vectors
/// Multiplies the vector with an integer.
/// Returns the value stored in the vector used.
	vector operator *=(const int rhs)
	{
		x = x * rhs;
		y = y * rhs;
		return *this;
	}
	
/// / Operator for vectors
/// Multiplies a vector with an integer.
/// Overload for "vector / int"
/// Returns the value without changing the original vector.
	vector operator/(const int rhs) const
	{
		return vector ( rhs / x, rhs / y);
	}
	
/// /= operator for vectors
/// Multiplies the vector with an integer.
/// Returns the value stored in the vector used.
	vector operator /=(const int rhs)
	{
		x = x / rhs;
		y = y / rhs;
		return *this;
	}
	
};
/// + Operator for vectors.
/// Returns the sum of the vectors without changing the original vectors.
	/*vector operator+(const vector lhs, const vector rhs) const
	{
		return vector (lhs.x + rhs.x, lhs.y + rhs.y);
	}*/
	
/// - Operator for vectors.
/// Returns the sum of the vectors without changing the original vectors.
/*	vector operator-(const vector lhs, const vector rhs) const
	{
		return vector (lhs.x - rhs.x, lhs.y - rhs.y);
	}*/

/// * Operator for vectors
/// Multiplies a vector with an integer.
/// Overload for "int * vector"
/// Returns the value without changing the original vector.
	vector operator*(const int lhs, vector & rhs)
	{
		return vector ( lhs * rhs.x, lhs * rhs.y);
	}
	
/// * Operator for vectors
/// Multiplies a vector with an integer.
/// Overload for "int * vector"
/// Returns the value without changing the original vector.
	vector operator/(const int lhs, vector & rhs)
	{
		return vector ( lhs / rhs.x, lhs / rhs.y);
	}

#endif