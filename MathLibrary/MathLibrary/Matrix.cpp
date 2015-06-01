#include "Matrix.h"


Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix3x3::~Matrix3x3()
{

}


//bool Matrix3x3::operator==(const Matrix3x3 &other) const
//{
//
//}


void Matrix3x3::operator=(const Matrix3x3 &other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}


Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &other) const
{
	Matrix3x3 mat;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
}


void Matrix3x3::operator+=(const Matrix3x3 &other) 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] += other.data[i][j];
		}
	}
}


Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &other) const
{
	Matrix3x3 mat;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
}


void Matrix3x3::operator-=(const Matrix3x3 &other) 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] -= other.data[i][j];
		}
	}
}


Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &other) const
{
	Matrix3x3 matrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix.data[i][j] = data[i][j] 
		}
	}
}


void Matrix3x3::operator*=(const Matrix3x3 &other) 
{

}

//Matrix3x3 Matrix3x3::operator/(const Matrix3x3 &other) const
//{
//
//}


//void Matrix3x3::operator/*(Matrix3x3 &other);
