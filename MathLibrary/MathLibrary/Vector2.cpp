#include "Vector2.h"


Vector2::Vector2()
{
	x = 0;
	y = 0;
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


float Vector2::Magnitude()
{
	return sqrt((x * x) + (y * y));
}


float Vector2::MagnitudeSqrd()
{
	return ((x * x) + (y * y));
}


Vector2 Vector2::NormaliseThis()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
	}
	return *this;
}


Vector2 Vector2::Normalise()
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


float Vector2::Dot(Vector2 &vectorA, Vector2 &vectorB)
{
	return ((vectorA.x * vectorB.x) + (vectorA.y * vectorB.y));
}