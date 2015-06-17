#pragma once
#include "Vector2.h"

//uses floating-point data in row-major right-handed form:
class Matrix2x2
{
public:
	Matrix2x2();
	~Matrix2x2();

	//bool operator==(const Matrix3x3 &other) const;

	void operator=(const Matrix2x2 &other);

	Matrix2x2 operator+(const Matrix2x2 &other) const;
	Matrix2x2 operator-(const Matrix2x2 &other) const;
	Matrix2x2 operator*(const Matrix2x2 &other) const;
	Vector2 operator*(const Vector2 &other) const;

	void operator*=(Matrix2x2 &other);

	Matrix2x2 operator-=(const Matrix2x2 &other);
	Matrix2x2 operator+=(const Matrix2x2 &other);
	Matrix2x2 operator*=(const Matrix2x2 &other);

	float operator()(unsigned int row, unsigned int col); //FIX DIS

	//builds and returns new identity matrix
	static Matrix2x2 Identity();
	//builds and returns a new rotation matrix
	static Matrix2x2 CreateRotation(float radians);
	//builds and returns a new scale matrix
	static Matrix2x2 CreateScale(const Vector2 &scale);
	//									static Matrix4x4 CreateScale(float x_val, float y_val, float z_val);
	//builds and returns a new translation matrix
	static Matrix2x2 CreateTranslation(const Vector2 &translation);
	//									static Matrix4x4 CreateScale(float x_val, float y_val, float z_val);

	//Transposes this and returns *this
	Matrix2x2 Transpose();
	//Builds and returns a new matrix that is this the transpose of this matrix
	Matrix2x2 GetTranspose() const;

	float data[2][2];

private:

};

