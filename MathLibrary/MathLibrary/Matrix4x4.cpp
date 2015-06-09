#include "Matrix4x4.h"


Matrix4x4::Matrix4x4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix4x4::~Matrix4x4()
{

}


//bool Matrix3x3::operator==(const Matrix3x3 &other) const
//{
//
//}


void Matrix4x4::operator=(const Matrix4x4 &other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}


Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &other) const
{
	Matrix4x4 mat;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return mat;
}


Matrix4x4 Matrix4x4::operator+=(const Matrix4x4 &other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
}


Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &other) const
{
	Matrix4x4 mat;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mat.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return mat;
}


Matrix4x4 Matrix4x4::operator-=(const Matrix4x4 &other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}


Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &other) const
{
	Matrix4x4 matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}
	return matrix;
}


Matrix4x4 Matrix4x4::operator*=(const Matrix4x4 &other)
{
	Matrix4x4 matrix;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = matrix.data[i][j];
		}
	}
	return *this;
}

//Matrix3x3 Matrix3x3::operator/(const Matrix3x3 &other) const
//{
//
//}


//void Matrix3x3::operator/*(Matrix3x3 &other);

float Matrix4x4::operator()(unsigned int row, unsigned int col)
{
	if (row < 4 && col < 4)
	{
		return data[row][col];
	}
	else
		return 1;
}


////builds and returns new identity matrix
//static Matrix4x4 Identity();
////builds and returns a new rotation matrix
//static Matrix4x4 CreateRotation(float radians);
////builds and returns a new scale matrix
//static Matrix4x4 CreateScale(const Vector4 &scale);
////builds and returns a new translation matrix
//static Matrix4x4 CreateTranslation(const Vector4 &translation);


Matrix4x4 Matrix4x4::Transpose()
{
	Matrix4x4 original(*this);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = original.data[j][i];
		}
	}
	return *this;
}


Matrix4x4 Matrix4x4::GetTranspose() const
{
	Matrix4x4 original(*this);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			original.data[i][j] = data[j][i];
		}
	}
	return original;
}