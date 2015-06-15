#include "Matrix2x2.h"


Matrix2x2::Matrix2x2()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix2x2::~Matrix2x2()
{

}


//bool Matrix2x2::operator==(const Matrix3x3 &other) const
//{
//
//}


void Matrix2x2::operator=(const Matrix2x2 &other)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}


Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &other) const
{
	Matrix2x2 mat;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mat.data[i][j] = data[i][j] + other.data[i][j];
		}
	}
	return mat;
}


Matrix2x2 Matrix2x2::operator+=(const Matrix2x2 &other)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] += other.data[i][j];
		}
	}
	return *this;
}


Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &other) const
{
	Matrix2x2 mat;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			mat.data[i][j] = data[i][j] - other.data[i][j];
		}
	}
	return mat;
}


Matrix2x2 Matrix2x2::operator-=(const Matrix2x2 &other)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}


Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &other) const
{
	Matrix2x2 matrix;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			float sum = 0;
			for (int k = 0; k < 2; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}
	return matrix;
}


Vector2 Matrix2x2::operator*(const Vector2 &other) const
{
	Vector2 result;
	result.x = (data[0][0] * other.x + data[0][1] * other.y);
	result.y = (data[1][0] * other.x + data[1][1] * other.y);
	return result;
}


Matrix2x2 Matrix2x2::operator*=(const Matrix2x2 &other)
{
	Matrix2x2 matrix;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			float sum = 0;
			for (int k = 0; k < 2; k++)
			{
				matrix.data[i][j] = (data[i][k] * other.data[k][j]);
			}
			matrix.data[i][j] = sum;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = matrix.data[i][j];
		}
	}
	return *this;
}

//Matrix2x2 Matrix2x2::operator/(const Matrix2x2 &other) const
//{
//
//}


//void Matrix2x2::operator/*(Matrix3x3 &other);

float Matrix2x2::operator()(unsigned int row, unsigned int col)
{
	if (row < 2 && col < 2)
	{
		return data[row][col];
	}
	else
		return 1;
}


//builds and returns new identity matrix
Matrix2x2 Matrix2x2::Identity()
{
	Matrix2x2 identity;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == j)
				identity.data[i][j] = 1;
			else
				identity.data[i][j] = 0;
		}
	}
	return identity;
}


Matrix2x2 Matrix2x2::CreateRotation(float radians)
{
	Matrix2x2 rotationMatrix;
	rotationMatrix.data[0][0] = cos(radians);
	rotationMatrix.data[0][1] = cos(radians + 90);
	rotationMatrix.data[1][0] = sin(radians);
	rotationMatrix.data[1][1] = sin(radians + 90);
	return rotationMatrix;
}


Matrix2x2 Matrix2x2::CreateScale(const Vector2 &scale)
{
	Matrix2x2 scaleMatrix;
	scaleMatrix.data[0][0] = scale.x;
	scaleMatrix.data[1][1] = scale.y;
	return scaleMatrix;
}


//Matrix2x2 Matrix2x2::CreateTranslation(const Vector2 &translation) // V fix dis V
//{
//	Matrix2x2 translationMatrix;
//	translationMatrix.data[0][0] = 1;
//	translationMatrix.data[1][1] = 1;
//	translationMatrix.data[2][2] = 1;
//	translationMatrix.data[0][2] = translation.x;
//	translationMatrix.data[1][2] = translation.y;
//	return translationMatrix;
//}


Matrix2x2 Matrix2x2::Transpose()
{
	Matrix2x2 original(*this);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			data[i][j] = original.data[j][i];
		}
	}
	return *this;
}


Matrix2x2 Matrix2x2::GetTranspose() const
{
	Matrix2x2 original(*this);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			original.data[i][j] = data[j][i];
		}
	}
	return original;
}