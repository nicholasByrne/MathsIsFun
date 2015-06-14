#pragma once
#include "Vector3.h"

//uses floating-point data in row-major right-handed form:
class Matrix3x3
{
public:
	Matrix3x3();
	~Matrix3x3();

	//bool operator==(const Matrix3x3 &other) const;

	void operator=(const Matrix3x3 &other);

	Matrix3x3 operator+(const Matrix3x3 &other) const;
	Matrix3x3 operator-(const Matrix3x3 &other) const;
	Matrix3x3 operator*(const Matrix3x3 &other) const;
	Vector3 operator*(const Vector3 &other) const;

	void operator*=(Matrix3x3 &other);

	Matrix3x3 operator-=(const Matrix3x3 &other);
	Matrix3x3 operator+=(const Matrix3x3 &other);
	Matrix3x3 operator*=(const Matrix3x3 &other);

	float operator()(unsigned int row, unsigned int col);

	//builds and returns new identity matrix
	static Matrix3x3 Identity();
	//builds and returns a new rotation matrix
	static Matrix3x3 CreateRotation(float radians);
	//builds and returns a new scale matrix
	static Matrix3x3 CreateScale(const Vector3 &scale);
	//builds and returns a new translation matrix
	static Matrix3x3 CreateTranslation(const Vector3 &translation);



	//Transposes this and returns *this
	Matrix3x3 Transpose();
	//Builds and returns a new matrix that is this the transpose of this matrix
	Matrix3x3 GetTranspose() const;

	float data[3][3];

private:

};

