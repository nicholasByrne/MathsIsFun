#pragma once
#include "Vector3.h"

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

	void operator-=(const Matrix3x3 &other);
	void operator+=(const Matrix3x3 &other);
	void operator*=(const Matrix3x3 &other);
	
	//builds and returns new identity matrix
	static Matrix3x3 Identity();
	//Transposes this
	void Transpose();
	//Builds and returns a new matrix that is this transposed
	Matrix3x3 GetTranspose() const;

	float data[3][3];

private:
	
};

