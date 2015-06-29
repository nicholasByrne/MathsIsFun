#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix4x4.h"

//uses floating-point data in column-major right-handed form:
class Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(float val00, float val01, float val02, float val10, float val11, float val12, float val20, float val21, float val22);
	~Matrix3x3();


	void operator=(const Matrix3x3 &other);

	Matrix3x3 operator+(const Matrix3x3 &other) const;
	Matrix3x3 operator-(const Matrix3x3 &other) const;
	Matrix3x3 operator*(const Matrix3x3 &other) const;
	Vector2 operator*(const Vector2 &vector) const; //This work?
	//Matrix3x3 operator*(const Vector3 &vector) const;
	Vector3 operator*(const Vector3 &other) const;


	Matrix3x3 operator*=(const Matrix3x3 &other);
	Matrix3x3 operator-=(const Matrix3x3 &other);
	Matrix3x3 operator+=(const Matrix3x3 &other);

	float operator()(unsigned int row, unsigned int col);

	//builds and returns new identity matrix
	static Matrix3x3 Identity();
	//builds and returns a new rotation matrix
	static Matrix3x3 CreateRotation(float radians);
	//builds and returns a new scale matrix
	static Matrix3x3 CreateScale(const Vector3 &scale);
	static Matrix3x3 CreateScale(float x_val, float y_val);
	//builds and returns a new translation matrix
	static Matrix3x3 CreateTranslation(const Vector3 &translation);
	static Matrix3x3 CreateTranslation(float x_val, float y_val);

	//Transposes this and returns *this
	Matrix3x3 Transpose();
	//Builds and returns a new matrix that is this the transpose of this matrix
	Matrix3x3 GetTranspose() const;
	//Convertts a Matrix3x3 into a Matrix4x4
	Matrix4x4 Mat4();

	float data[3][3];

private:

};

