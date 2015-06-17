#pragma once
#include "Vector3.h"

//Axis Aligned Boundary Box
class AABB
{
public:
	AABB();
	AABB(Vector3 a_min, Vector3 a_max);
	~AABB();

	Vector3 m_min;
	Vector3 m_max;

	void SetMin(float a_x, float a_y, float a_z);
	void SetMin(Vector3 a_min);

	void SetMax(float a_x, float a_y, float a_z);
	void SetMax(Vector3 a_max);

	//returns true if min/max set to infinity
	bool IsEmpty();

	void SetToTransformedBox(const AABB &box, const Matrix3x3 &matrix);



private:

};

