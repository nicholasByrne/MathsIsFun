#include "AABB.h"


AABB::AABB()
{
}


AABB::AABB(Vector3 a_min, Vector3 a_max)
{
	m_min = a_min;
	m_max = a_max;
}


AABB::~AABB()
{
}


void AABB::SetMin(float a_x, float a_y, float a_z)
{
	m_min.x = a_x;
	m_min.y = a_y;
	m_min.z = a_z;
}


void AABB::SetMin(Vector3 a_min)
{
	m_min = a_min;
}


void AABB::SetMax(float a_x, float a_y, float a_z)
{
	m_max.x = a_x;
	m_max.y = a_y;
	m_max.z = a_z;
}


void AABB::SetMax(Vector3 a_max)
{
	m_max = a_max;
}


void AABB::SetToTransformedBox(const AABB &box, const Matrix3x3 &matrix)
{

}

