#pragma once
#include <cmath>
#define PI 3.14159265

class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();

	float x, y;

	bool operator==(Vector2 &other);
	void operator=(const Vector2 &other);

	Vector2 operator+(Vector2 &other) const;
	void operator+=(Vector2 &other);

	Vector2 operator-(const Vector2 &other) const;
	void operator-=(Vector2 &other);

	Vector2 operator*(float scalar) const;
	void operator*=(float scalar);

	Vector2 operator/(float scalar);
	void operator/=(float scalar);

	float Magnitude(); //Length
	float MagnitudeSqrd();

	void NormaliseThis();
	Vector2 Normalise(); //returns normalised version

	float Dot(Vector2 vectorB);
	Vector2 Perpindicular();

	static float Dot(Vector2 vectorA, Vector2 vectorB);
	static float Distance(Vector2& vectorA, Vector2& vectorB);
	static float Angle(const Vector2& vectorA, const Vector2& vectorB);

private:

};

Vector2 operator*(float lhs, Vector2 &rhs);