#include "Collider.h"
#include <math.h>
#include <iostream>
Collider::Collider()
{

}

Collider::~Collider()
{

}

CircleCollider::CircleCollider(const Vector2& a_center, float a_radius)
{
	colliderType = ColliderType::CIRCLE;

	localCircle.center = a_center;
	localCircle.radius = a_radius;
}

CircleCollider::~CircleCollider()
{

}

void CircleCollider::UpdateCollider(const Matrix3x3& globalTransformMat)
{
	globalCircle = globalTransformMat * localCircle;
}

void CircleCollider::DrawCollider(SpriteBatch& m_spriteBatch) const
{
	Vector2 oldPos = globalCircle.center;

	for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
	{
		Vector2 newPos;

		newPos.x = globalCircle.center.x + (cos(i) * globalCircle.radius);
		newPos.y = globalCircle.center.y + (sin(i) * globalCircle.radius);

		m_spriteBatch.DrawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

		oldPos = newPos;
	}
}


BoxCollider::BoxCollider(const Vector2& min, const Vector2& max)
{
	colliderType = ColliderType::AABB;

	localAABB.min = min;
	localAABB.max = max;
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::UpdateCollider(const Matrix3x3& globalTransformMat)
{
	globalAABB = (globalTransformMat * localAABB);
	//globalAABB.max = (globalTransformMat * localAABB).max;
}

void BoxCollider::DrawCollider(SpriteBatch& m_spriteBatch) const
{
	m_spriteBatch.DrawLine(globalAABB.min.x, globalAABB.min.y, globalAABB.max.x, globalAABB.min.y, 2.0f);
	m_spriteBatch.DrawLine(globalAABB.max.x, globalAABB.min.y, globalAABB.max.x, globalAABB.max.y, 2.0f);
	m_spriteBatch.DrawLine(globalAABB.max.x, globalAABB.max.y, globalAABB.min.x, globalAABB.max.y, 2.0f);
	m_spriteBatch.DrawLine(globalAABB.min.x, globalAABB.max.y, globalAABB.min.x, globalAABB.min.y, 2.0f);
}

PolygonCollider::PolygonCollider(int a_numPoints, Vector2 * a_points)
{
	colliderType = ColliderType::POLYGON;

	localPolygon.SetLocalPoints(a_numPoints, a_points);
	globalPolygon.SetLocalPoints(a_numPoints, a_points);
}

PolygonCollider::~PolygonCollider()
{

}

void PolygonCollider::UpdateCollider(const Matrix3x3& globalTransformMat)
{
	//sets globalPolygon's points to be equal to localPolygon points multiplied by our transformation matrix
	globalPolygon.SetTransformedPoints(localPolygon.numPoints, localPolygon.points, globalTransformMat);
}

void PolygonCollider::DrawCollider(SpriteBatch& m_spriteBatch) const
{
	//draw the polygon
	for (int i = 0; i < globalPolygon.numPoints-1; i++)
	{
		m_spriteBatch.DrawLine(globalPolygon.points[i].x, globalPolygon.points[i].y, globalPolygon.points[i+1].x, globalPolygon.points[i+1].y, 2.0f);
	}

	m_spriteBatch.DrawLine(globalPolygon.points[0].x, globalPolygon.points[0].y, globalPolygon.points[globalPolygon.numPoints - 1].x, globalPolygon.points[globalPolygon.numPoints - 1].y, 2.0f);

}

Vector2 * PolygonCollider::GetLocalPoints() const
{
	return localPolygon.points;
}

int PolygonCollider::GetPointCount() const
{
	return localPolygon.numPoints;
}
void PolygonCollider::SetLocalPoints(int a_numPoints, Vector2 * a_points)
{
	return localPolygon.SetLocalPoints(a_numPoints, a_points);;
}