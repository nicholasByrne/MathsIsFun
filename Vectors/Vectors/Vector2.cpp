#include "Vector2.h"


Vector2::Vector2()
{
	
}


Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}


Vector2::~Vector2()
{
}


bool Vector2::operator==(Vector2 &other)
{
	if (x == other.x && y == other.y)
	{
		return true;
	}
	else
		return false;
}


void Vector2::operator=(Vector2 &other)
{
	x = other.x;
	y = other.y;
}


Vector2 Vector2::operator+(Vector2 &other)
{
	Vector2 temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	return temp;
}


void Vector2::operator+=(Vector2 &other)
{
	x += other.x;
	y += other.y;
}


Vector2 Vector2::operator-(Vector2 &other)
{
	Vector2 temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	return temp;
}


void Vector2::operator-=(Vector2 &other)
{
	x -= other.x;
	y -= other.y;
}


Vector2 Vector2::operator*(float scalar)
{
	Vector2 temp;
	temp.x = x * scalar;
	temp.y = y * scalar;
	return temp;
}


void Vector2::operator*=(float scalar)
{
	x = x * scalar;
	y = y * scalar;
}


Vector2 Vector2::operator/(Vector2 &other)
{
	Vector2 temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	return temp;
}


void Vector2::operator/=(Vector2 &other)
{
	x = x / other.x;
	y = y / other.y;
}


float Vector2::Magnitude()
{
	return sqrt((x * x) + (y * y));
}


float Vector2::MagnitudeSqrd()
{
	return ((x * x) + (y * y));
}


void Vector2::Normalise()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
	}
}


Vector2 Vector2::Normal()
{
	Vector2 temp;
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		temp.x = x / magnitude;
		temp.y = y / magnitude;
	}
	return temp;
}