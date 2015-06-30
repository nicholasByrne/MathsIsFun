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


void Vector2::operator=(const Vector2 &other)
{
	x = other.x;
	y = other.y;
}


Vector2 Vector2::operator+(Vector2 &other) const
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


Vector2 Vector2::operator-(const Vector2 &other) const
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


Vector2 Vector2::operator*(float scalar) const
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


Vector2 Vector2::operator/(float scalar)
{
	Vector2 temp;
	temp.x = x / scalar;
	temp.y = y / scalar;
	return temp;
}


void Vector2::operator/=(float scalar)
{
	x = x / scalar;
	y = y / scalar;
}


float Vector2::Magnitude()
{
	return sqrt((x * x) + (y * y));
}


float Vector2::MagnitudeSqrd()
{
	return ((x * x) + (y * y));
}


void Vector2::NormaliseThis()
{
	float magnitude = Magnitude();
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
	}
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


Vector2 Vector2::Perpindicular()
{
	Vector2 result(-y, x);
	return result;
}



float Vector2::Dot(Vector2 vectorB)
{
	return ((x *  vectorB.x) + (y * vectorB.y));
}


float Vector2::Dot(Vector2 vectorA, Vector2 vectorB)
{
	return ((vectorA.x * vectorB.x) + (vectorA.y * vectorB.y));
}


float Vector2::Distance(Vector2& vectorA, Vector2& vectorB)
{
	Vector2 result(vectorA - vectorB);
	return result.Magnitude();
}


float Vector2::Angle(const Vector2& vectorA, const Vector2& vectorB)
{
	return atan2(vectorA.y - vectorB.y, vectorA.x - vectorB.x);

}


Vector2 operator*(float lhs, Vector2 &rhs)
{
	return rhs * lhs;
}