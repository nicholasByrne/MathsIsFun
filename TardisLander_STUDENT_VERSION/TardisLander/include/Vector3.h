#pragma once
#include <math.h>

class Vector3
{
public:
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	float x, y, z;

	bool operator==(Vector3 &other);
	void operator=(Vector3 &other);

	Vector3 operator+(Vector3 &other);
	void operator+=(Vector3 &other);

	Vector3 operator-(Vector3 &other);
	void operator-=(Vector3 &other);

	Vector3 operator*(float scalar);
	void operator*=(float scalar);

	//Vector3 operator/(Vector3 &other);
	//void operator/=(Vector3 &other);

	float Magnitude();
	float MagnitudeSqrd();

	void NormaliseThis();
	Vector3 Normalise(); //returns normalised version

	static float Dot(Vector3 vectorA, Vector3 vectorB);
	static Vector3 Cross(Vector3 &vectorA, Vector3 &vectorB);

private:

};