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
	data[2][2] = 1;
}


Matrix3x3::Matrix3x3(float val00, float val01, float val02, float val10, float val11, float val12, float val20, float val21, float val22)
{
	data[0][0] = val00;
	data[0][1] = val01;
	data[0][2] = val02;
	data[1][0] = val10;
	data[1][1] = val11;
	data[1][2] = val12;
	data[2][0] = val20;
	data[2][1] = val21;
	data[2][2] = val22;
}


Matrix3x3::~Matrix3x3()
{

}


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
	Matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Vector3 row(data[i][0], data[i][1], data[i][2]);
			Vector3 column(other.data[0][j], other.data[1][j], other.data[2][j]);
			result.data[i][j] = row.Dot(column);
		}
	}
	return result;
}


Vector3 Matrix3x3::operator*(const Vector3 &other) const
{
	Vector3 result;
	result.x = (data[0][0] * other.x + data[0][1] * other.y + data[0][2] * other.z);
	result.y = (data[1][0] * other.x + data[1][1] * other.y + data[1][2] * other.z);
	result.z = (data[2][0] * other.x + data[2][1] * other.y + data[2][2] * other.z);
	return result;
}


Vector2 Matrix3x3::operator*(const Vector2 &other) const
{
	Vector2 result;
	result.x = (data[0][0] * other.x + data[0][1] * other.y);
	result.y = (data[1][0] * other.x + data[1][1] * other.y);
	return result;
}



Matrix3x3 Matrix3x3::operator*=(const Matrix3x3 &other)
{
	Matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				result.data[i][j] += data[i][k] * other.data[k][j];
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = result.data[i][j];
		}
	}
	return *this;
}


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
	rotationMatrix.data[0][1] = -sin(radians);
	rotationMatrix.data[1][0] = sin(radians);
	rotationMatrix.data[1][1] = cos(radians);
	rotationMatrix.data[2][2] = 1;
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


Matrix3x3 Matrix3x3::CreateScale(float x_val, float y_val)
{
	Matrix3x3 scaleMatrix;
	scaleMatrix.data[0][0] = x_val;
	scaleMatrix.data[1][1] = y_val;
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


Matrix3x3 Matrix3x3::CreateTranslation(float x_val, float y_val)
{
	Matrix3x3 translationMatrix;
	translationMatrix.data[0][0] = 1;
	translationMatrix.data[1][1] = 1;
	translationMatrix.data[2][2] = 1;
	translationMatrix.data[0][2] = x_val;
	translationMatrix.data[1][2] = y_val;
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
