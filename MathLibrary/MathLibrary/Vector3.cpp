#include "Vector3.h"


Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 1;
}


Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}


Vector3::~Vector3()
{
}


bool Vector3::operator==(Vector3 &other)
{
	if (x == other.x && y == other.y && z == other.z)
	{
		return true;
	}
	else
		return false;
}


void Vector3::operator=(Vector3 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}


Vector3 Vector3::operator+(Vector3 &other) const
{
	Vector3 temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	temp.z = z + other.z;
	return temp;
}


void Vector3::operator+=(Vector3 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}


Vector3 Vector3::operator-(Vector3 &other) const
{
	Vector3 temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	temp.z = z - other.z;
	return temp;
}


void Vector3::operator-=(Vector3 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}


Vector3 Vector3::operator*(float scalar) const
{
	Vector3 temp;
	temp.x = x * scalar;
	temp.y = y * scalar;
	temp.z = z * scalar;
	return temp;
}


void Vector3::operator*=(float scalar)
{
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;
}


Vector3 Vector3::operator/(float scalar)
{
	Vector3 temp;
	temp.x = x / scalar;
	temp.y = y / scalar;
	temp.z = z / scalar;
	return temp;
}


void Vector3::operator/=(float scalar)
{
	x = x / scalar;
	y = y / scalar;
	z = z / scalar;
}


float Vector3::Magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}


float Vector3::MagnitudeSqrd()
{
	return ((x * x) + (y * y) + (z * z));
}


void Vector3::NormaliseThis()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}
}


Vector3 Vector3::Normalise()
{
	Vector3 temp;
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		temp.x = x / magnitude;
		temp.y = y / magnitude;
		temp.z = z / magnitude;
	}
	return temp;
}


float Vector3::Dot(Vector3 vectorB)
{
	return ((x *  vectorB.x) + (y * vectorB.y) + (z * vectorB.z));
}


Vector3 Vector3::Cross(Vector3 &vectorB)
{
	Vector3 result;
	result.x = ((y * vectorB.z) - (z * vectorB.y));
	result.y = ((z * vectorB.x) - (x * vectorB.z));
	result.z = ((x * vectorB.y) - (y * vectorB.x));
	return result;
}


float Vector3::Dot(Vector3 vectorA, Vector3 vectorB)
{
	return ((vectorA.x * vectorB.x) + (vectorA.y * vectorB.y) + (vectorA.z * vectorB.z));
}


Vector3 Vector3::Cross(Vector3 &vectorA, Vector3 &vectorB)
{
	Vector3 result;
	result.x = ((vectorA.y * vectorB.z) - (vectorA.z * vectorB.y));
	result.y = ((vectorA.z * vectorB.x) - (vectorA.x * vectorB.z));
	result.z = ((vectorA.x * vectorB.y) - (vectorA.y * vectorB.x));
	return result;
}


Vector3 operator*(float lhs, Vector3 &rhs)
{
	return rhs * lhs;
}
