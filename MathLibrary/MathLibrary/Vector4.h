#pragma once
#include <math.h>
#define PI 3.14159265

class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);
	~Vector4();

	float x, y, z, w;

	bool operator==(Vector4 &other);
	void operator=(Vector4 &other);

	Vector4 operator+(Vector4 &other) const;
	void operator+=(Vector4 &other);

	Vector4 operator-(Vector4 &other) const;
	void operator-=(Vector4 &other);

	Vector4 operator*(float scalar) const;
	void operator*=(float scalar);

	Vector4 operator/(Vector4 &other) const;
	void operator/=(Vector4 &other);

	float Magnitude(); //Length
	float MagnitudeSqrd();

	void NormaliseThis();
	Vector4 Normalise(); //returns normalised version

	float Dot(Vector4 vectorB);
	Vector4 Cross(Vector4 &vectorB);

	static float Dot(Vector4 vectorA, Vector4 vectorB);
	static Vector4 Cross(Vector4 &vectorA, Vector4 &vectorB);
	static float Distance(Vector4& vectorA, Vector4& vectorB);
	static float Angle(const Vector4& vectorA, const Vector4& vectorB);

private:

};

Vector4 operator*(float lhs, Vector4 &rhs);
