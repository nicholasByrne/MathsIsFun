#pragma once
#include "Vector4.h"
#include "Vector3.h"

//uses floating-point data in column-major right-handed form:
class Matrix4x4
{
public:
	Matrix4x4();
	~Matrix4x4();


	void operator=(const Matrix4x4 &other);

	Matrix4x4 operator+(const Matrix4x4 &other) const;
	Matrix4x4 operator-(const Matrix4x4 &other) const;
	Matrix4x4 operator*(const Matrix4x4 &other) const;
	Vector4 operator*(const Vector4 &other) const;

	void operator*=(Matrix4x4 &other);

	Matrix4x4 operator-=(const Matrix4x4 &other);
	Matrix4x4 operator+=(const Matrix4x4 &other);
	Matrix4x4 operator*=(const Matrix4x4 &other);

	float operator()(unsigned int row, unsigned int col);

	//builds and returns new identity matrix
	static Matrix4x4 Identity();
	//builds and returns a new rotation matrix
	static Matrix4x4 CreateRotation(float radians);
	//builds and returns a new scale matrix
	static Matrix4x4 CreateScale(const Vector4 &scale);
	static Matrix4x4 CreateScale(float x_val, float y_val, float z_val);
	//builds and returns a new translation matrix
	static Matrix4x4 CreateTranslation(const Vector4 &translation);
	static Matrix4x4 CreateTranslation(float x_val, float y_val, float z_val);

	//Transposes this and returns *this
	Matrix4x4 Transpose();
	//Builds and returns a new matrix that is this the transpose of this matrix
	Matrix4x4 GetTranspose() const;

	float data[4][4];

private:

};