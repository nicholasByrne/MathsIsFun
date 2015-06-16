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


	float Magnitude();
	float MagnitudeSqrd();

	Vector2 NormaliseThis(); //returns *this
	Vector2 Normalise(); //returns normalised version

	static float Dot(Vector2 &vectorA, Vector2 &vectorB);

private:

};
