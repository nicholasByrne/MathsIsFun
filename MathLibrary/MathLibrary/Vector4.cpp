#include "Vector4.h"


Vector4::Vector4()
{

}


Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}


Vector4::~Vector4()
{
}


bool Vector4::operator==(Vector4 &other)
{
	if (x == other.x && y == other.y && z == other.z && w == other.w)
	{
		return true;
	}
	else
		return false;
}


void Vector4::operator=(Vector4 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}


Vector4 Vector4::operator+(Vector4 &other)
{
	Vector4 temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	temp.z = z + other.z;
	temp.w = w + other.w;
	return temp;
}


void Vector4::operator+=(Vector4 &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}


Vector4 Vector4::operator-(Vector4 &other)
{
	Vector4 temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	temp.z = z - other.z;
	temp.w = w - other.w;
	return temp;
}


void Vector4::operator-=(Vector4 &other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
}


Vector4 Vector4::operator*(float scalar)
{
	Vector4 temp;
	temp.x = x * scalar;
	temp.y = y * scalar;
	temp.z = z * scalar;
	temp.w = w * scalar;
	return temp;
}


void Vector4::operator*=(float scalar)
{
	x = x * scalar;
	y = y * scalar;
	z = z * scalar;
	w = w * scalar;
}


Vector4 Vector4::operator/(Vector4 &other)
{
	Vector4 temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	temp.z = z / other.z;
	temp.w = w / other.w;
	return temp;
}


void Vector4::operator/=(Vector4 &other)
{
	x = x / other.x;
	y = y / other.y;
	z = z / other.z;
	w = w / other.w;
}


float Vector4::Magnitude()
{
	return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}


float Vector4::MagnitudeSqrd()
{
	return ((x * x) + (y * y) + (z * z) + (w * w));
}


void Vector4::NormaliseThis()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		w /= magnitude;
	}
}


Vector4 Vector4::Normalise()
{
	Vector4 temp;
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		temp.x = x / magnitude;
		temp.y = y / magnitude;
		temp.z = z / magnitude;
		temp.w = w / magnitude;
	}
	return temp;
}