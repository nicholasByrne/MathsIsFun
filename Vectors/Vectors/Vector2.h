#pragma once
#include <math.h>

class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();

	float x, y;

	bool operator==(Vector2 &other);
	void operator=(Vector2 &other);

	Vector2 operator+(Vector2 &other);
	void operator+=(Vector2 &other);

	Vector2 operator-(Vector2 &other);
	void operator-=(Vector2 &other);

	Vector2 operator*(float scalar);
	void operator*=(float scalar);

	Vector2 operator/(Vector2 &other);
	void operator/=(Vector2 &other);

	float Magnitude();
	float MagnitudeSqrd();

	void NormaliseThis(); //
	Vector2 Normalise(); //returns normalised version

	float dot(Vector2 &other);

private:

};





