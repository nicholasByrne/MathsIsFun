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


Vector3 Matrix3x3::operator*(const Vector3 &other) const
{
	Vector3 result;
	result.x = (data[0][0] * other.x + data[0][1] * other.y + data[0][2] * other.z);
	result.y = (data[1][0] * other.x + data[1][1] * other.y + data[1][2] * other.z);
	result.z = (data[2][0] * other.x + data[2][1] * other.y + data[2][2] * other.z);
	return result;
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



Matrix3x3 Matrix3x3::Identity()
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
	return identity;
}


Matrix3x3 Matrix3x3::CreateRotation(float radians)
{
	Matrix3x3 rotationMatrix;
	rotationMatrix.data[0][0] = cos(radians);
	rotationMatrix.data[0][1] = cos(radians + 90);
	rotationMatrix.data[1][0] = sin(radians);
	rotationMatrix.data[1][1] = sin(radians + 90);
	return rotationMatrix;
}


Matrix3x3 Matrix3x3::CreateScale(const Vector3 &scale)
{
	Matrix3x3 scaleMatrix;
	scaleMatrix.data[0][0] = scale.x;
	scaleMatrix.data[1][1] = scale.y;
	scaleMatrix.data[2][2] = 1;
	return scaleMatrix;
}


Matrix3x3 Matrix3x3::CreateTranslation(const Vector3 &translation)
{
	Matrix3x3 translationMatrix;
	translationMatrix.data[0][0] = 1;
	translationMatrix.data[1][1] = 1;
	translationMatrix.data[2][2] = 1;
	translationMatrix.data[0][2] = translation.x;
	translationMatrix.data[1][2] = translation.y;
	return translationMatrix;
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


Matrix4x4 Matrix3x3::Mat4()
{
	Matrix4x4 mat4;
	mat4.data[0][0] = data[0][0];
	mat4.data[0][1] = data[0][1];
	mat4.data[0][2] = 0;
	mat4.data[0][3] = 0;
	mat4.data[1][0] = data[1][0];
	mat4.data[1][1] = data[1][1];
	mat4.data[1][2] = 0;
	mat4.data[1][3] = 0;
	mat4.data[2][0] = 0;
	mat4.data[2][1] = 0;
	mat4.data[2][2] = 1;
	mat4.data[2][3] = 0;
	mat4.data[3][0] = data[2][0];
	mat4.data[3][1] = data[2][1];
	mat4.data[3][2] = 0;
	mat4.data[3][3] = 1;
	return mat4;
}