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
	data[3][3] = 1;
}

Matrix4x4::~Matrix4x4()
{

}


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
	Matrix4x4 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Vector4 row(data[i][0], data[i][1], data[i][2], data[i][3]);
			Vector4 column(other.data[0][j], other.data[1][j], other.data[2][j], other.data[3][j]);
			result.data[i][j] = row.Dot(column);
		}
	}
	return result;
}


Vector4 Matrix4x4::operator*(const Vector4 &other) const
{
	Vector4 result;
	result.x = (data[0][0] * other.x + data[0][1] * other.y + data[0][2] * other.z + data[0][3] * other.w);
	result.y = (data[1][0] * other.x + data[1][1] * other.y + data[1][2] * other.z + data[1][3] * other.w);
	result.z = (data[2][0] * other.x + data[2][1] * other.y + data[2][2] * other.z + data[2][3] * other.w);
	result.w = (data[3][0] * other.x + data[3][1] * other.y + data[3][2] * other.z + data[3][3] * other.w);
	return result;
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


float Matrix4x4::operator()(unsigned int row, unsigned int col)
{
	if (row < 4 && col < 4)
	{
		return data[row][col];
	}
	else
		return 1;
}


Matrix4x4 Matrix4x4::Identity()
{
	Matrix4x4 identity;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				identity.data[i][j] = 1;
			else
				identity.data[i][j] = 0;
		}
	}
	return identity;
}


Matrix4x4 Matrix4x4::CreateRotation(float radians)
{
	Matrix4x4 rotationMatrix;
	rotationMatrix.data[0][0] = cos(radians);
	rotationMatrix.data[0][1] = cos(radians + 90);
	rotationMatrix.data[1][0] = sin(radians);
	rotationMatrix.data[1][1] = sin(radians + 90);
	rotationMatrix.data[2][2] = 1;
	rotationMatrix.data[3][3] = 1;
	return rotationMatrix;
}


Matrix4x4 Matrix4x4::CreateScale(const Vector4 &scale)
{
	Matrix4x4 scaleMatrix;
	scaleMatrix.data[0][0] = scale.x;
	scaleMatrix.data[1][1] = scale.y;
	scaleMatrix.data[2][2] = scale.z;
	scaleMatrix.data[3][3] = 1;
	return scaleMatrix;
}


Matrix4x4 Matrix4x4::CreateScale(float x_val, float y_val, float z_val)
{
	Matrix4x4 scaleMatrix;
	scaleMatrix.data[0][0] = x_val;
	scaleMatrix.data[1][1] = y_val;
	scaleMatrix.data[2][2] = z_val;
	scaleMatrix.data[3][3] = 1;
	return scaleMatrix;
}


Matrix4x4 Matrix4x4::CreateTranslation(const Vector4 &translation)
{
	Matrix4x4 translationMatrix;
	translationMatrix.data[0][0] = 1;
	translationMatrix.data[1][1] = 1;
	translationMatrix.data[2][2] = 1;
	translationMatrix.data[3][3] = 1;
	translationMatrix.data[0][3] = translation.x;
	translationMatrix.data[1][3] = translation.y;
	translationMatrix.data[2][3] = translation.z;
	return translationMatrix;
}


Matrix4x4 Matrix4x4::CreateTranslation(float x_val, float y_val, float z_val)
{
	Matrix4x4 translationMatrix;
	translationMatrix.data[0][0] = 1;
	translationMatrix.data[1][1] = 1;
	translationMatrix.data[2][2] = 1;
	translationMatrix.data[3][3] = 1;
	translationMatrix.data[0][3] = x_val;
	translationMatrix.data[1][3] = y_val;
	translationMatrix.data[2][3] = z_val;
	return translationMatrix;
}


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