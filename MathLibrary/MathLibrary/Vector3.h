#pragma once
#include <math.h>
#define PI 3.14159265

class Vector3
{
public:
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	float x, y, z;

	bool operator==(Vector3 &other);
	void operator=(Vector3 &other);

	Vector3 operator+(Vector3 &other) const;
	void operator+=(Vector3 &other);

	Vector3 operator-(Vector3 &other) const;
	void operator-=(Vector3 &other);

	Vector3 operator*(float scalar) const;
	void operator*=(float scalar);

	Vector3 operator/(float scalar);
	void operator/=(float scalar);

	float Magnitude(); //Length
	float MagnitudeSqrd();

	void NormaliseThis();
	Vector3 Normalise(); //returns normalised version

	float Dot(Vector3 vectorB);
	Vector3 Cross(Vector3 &vectorB);

	static float Dot(Vector3 vectorA, Vector3 vectorB);
	static Vector3 Cross(Vector3 &vectorA, Vector3 &vectorB);
	static float Distance(Vector3& vectorA, Vector3& vectorB);
	static float Angle(const Vector3& vectorA, const Vector3& vectorB);

private:
};

Vector3 operator*(float lhs, Vector3 &rhs);

