#ifndef MATH_H
#define MATH_H

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

typedef struct VECTOR2D {
	
	int x;
	int y;

	VECTOR2D() {};
	VECTOR2D(int xIn, int yIn) { x = xIn; y = yIn; };

	void operator += (const VECTOR2D& v)
	{
		x += v.x;
		y += v.y;
	}

	VECTOR2D operator +(const VECTOR2D& v)
	{
		VECTOR2D v2;
		v2.x = v.x + x;
		v2.y = y + v.y;

		return v2; 
	}

	void operator -= (const VECTOR2D& v)
	{
		x -= v.x;
		y -= v.y;
	}

	VECTOR2D operator -(const VECTOR2D& v)
	{
		VECTOR2D v2;
		v2.x = v.x - x;
		v2.y = y - v.y;

		return v2; 
	}

	// Multiply this Vector2D by a scalar.
	void operator *= (int a)
	{
		x *= a; y *= a;
	}

	// Multiply this Vector2D by a scalar.
	bool operator >= (const VECTOR2D& v)
	{
		if( x >= v.x && y >= v.y)
			return true;

		else
			return false;
	}

	// Multiply this Vector2D by a scalar.
	bool operator < (const VECTOR2D& v)
	{
		if( x < v.x && y < v.y)
			return true;

		else
			return false;
	}



} Vector2D;

#endif