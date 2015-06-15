#include "Vector3.h"


Vector3::Vector3()
{

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


Vector3 Vector3::operator+(Vector3 &other)
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


Vector3 Vector3::operator-(Vector3 &other)
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


Vector3 Vector3::operator*(float scalar)
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


Vector3 Vector3::operator/(Vector3 &other)
{
	Vector3 temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	temp.z = z / other.z;
	return temp;
}


void Vector3::operator/=(Vector3 &other)
{
	x = x / other.x;
	y = y / other.y;
	z = z / other.z;
}


float Vector3::Magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}


float Vector3::MagnitudeSqrd()
{
	return ((x * x) + (y * y) + (z * z));
}


Vector3 Vector3::NormaliseThis()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}
	return *this;
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