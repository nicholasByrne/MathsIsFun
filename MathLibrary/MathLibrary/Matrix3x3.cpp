#include "Matrix3x3.h"


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
	return mat;
}


Matrix3x3 Matrix3x3::operator+=(const Matrix3x3 &other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
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
	return mat;
}


Matrix3x3 Matrix3x3::operator-=(const Matrix3x3 &other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}


Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &other) const
{
	Matrix3x3 matrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float sum = 0;
			for (int k = 0; k < 3; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}
	return matrix;
}


Matrix3x3 Matrix3x3::operator*=(const Matrix3x3 &other)
{
	Matrix3x3 matrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float sum = 0;
			for (int k = 0; k < 3; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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

float Matrix3x3::operator()(unsigned int row, unsigned int col)
{
	if (row < 3 && col < 3)
	{
		return data[row][col];
	}
	else
		return 1;
}



static Matrix3x3 Identity()
{
	Matrix3x3 identity;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				identity.data[i][j] = 1;
			else
				identity.data[i][j] = 0;
		}
	}
}


static Matrix3x3 CreateRotation(float radians)
{

}


static Matrix3x3 CreateScale(const Vector3 &scale)
{
	Matrix3x3 scaleMatrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scaleMatrix.data[i][j] = 0;
		}
	}
	scaleMatrix.data[0][0] = scale.x;
	scaleMatrix.data[1][1] = scale.y;
	scaleMatrix.data[2][2] = scale.z;
}


static Matrix3x3 CreateTranslation(const Vector3 &translation)
{

}

Matrix3x3 Matrix3x3::Transpose()
{
	Matrix3x3 original(*this);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = original.data[j][i];
		}
	}
	return *this;
}


Matrix3x3 Matrix3x3::GetTranspose() const
{
	Matrix3x3 original(*this);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			original.data[i][j] = data[j][i];
		}
	}
	return original;
}