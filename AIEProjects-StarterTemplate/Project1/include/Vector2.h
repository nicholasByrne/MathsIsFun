#pragma once
#include <math.h>
#define PI 3.14159265

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

	Vector2 operator/(float scalar);
	void operator/=(float scalar);

	float Magnitude();
	float MagnitudeSqrd();

	void Normalise();
	Vector2 Normal(); //returns normalised version

	static float Dot(Vector2 vectorA, Vector2 vectorB);
	static float Distance(const Vector2& vectorA, const Vector2& vectorB);
	static float Angle(const Vector2& vectorA, const Vector2& vectorB);

private:

};
