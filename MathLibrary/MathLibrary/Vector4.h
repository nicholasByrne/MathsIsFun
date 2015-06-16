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
	
	float Magnitude();
	float MagnitudeSqrd();

	Vector4 NormaliseThis(); //returns *this
	Vector4 Normalise(); //returns normalised version

	static Vector4 Cross(Vector4 &vectorA, Vector4 &vectorB);

private:

};