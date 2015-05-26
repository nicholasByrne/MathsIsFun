#pragma once
#include <math.h>

class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);
	~Vector4();

	float x, y, z, w;

	bool operator==(Vector4 &other);
	void operator=(Vector4 &other);

	Vector4 operator+(Vector4 &other);
	void operator+=(Vector4 &other);

	Vector4 operator-(Vector4 &other);
	void operator-=(Vector4 &other);

	Vector4 operator*(float scalar);
	void operator*=(float scalar);

	Vector4 operator/(Vector4 &other);
	void operator/=(Vector4 &other);

	float Magnitude();
	float MagnitudeSqrd();

	void Normalise();
	Vector4 Normal(); //returns normalised version


private:

};