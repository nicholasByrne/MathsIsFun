#pragma once

#include "Geometry.h"
#include "Matrix3x3.h"
#include "Vector2.h"
#include "SpriteBatch.h"
using namespace MathLibrary;

enum class ColliderType
{
	CIRCLE,
	AABB,
	POLYGON
};

class Collider
{
public:
	
	Collider();
	virtual ~Collider();

	//Updates global collider based on object's transformation matrix
	virtual void UpdateCollider(const Matrix3x3& transformMat) = 0;
	
	//exists for debug purposes only - collider should NOT know about spritebatch
	virtual void DrawCollider(SpriteBatch& m_spriteBatch) const = 0;

	//type of collider
	ColliderType colliderType;
};

class CircleCollider : public Collider
{
public:
	CircleCollider(const Vector2& a_center, float a_radius);
	~CircleCollider();

	//Updates global collider based on object's transformation matrix
	void UpdateCollider(const Matrix3x3& transformMat);

	//exists for debug purposes only - collider should NOT know about spritebatch
	void DrawCollider(SpriteBatch& m_spriteBatch) const;

	//local shape
	Circle2D localCircle;

	//updated shape based on object's transform matrix
	Circle2D globalCircle;
};

class BoxCollider : public Collider
{
public:
	BoxCollider(const Vector2& min, const Vector2& max);
	~BoxCollider();

	//Updates global collider based on object's transformation matrix
	void UpdateCollider(const Matrix3x3& transformMat);

	//exists for debug purposes only - collider should NOT know about spritebatch
	void DrawCollider(SpriteBatch& m_spriteBatch) const;

	//local shape
	AABB2D localAABB;

	//updated shape based on object's transform matrix
	AABB2D globalAABB;
};


class PolygonCollider : public Collider
{
public:
	PolygonCollider(int a_numPoints, Vector2 * a_points);
	~PolygonCollider();

	//Updates global collider based on object's transformation matrix
	void UpdateCollider(const Matrix3x3& transformMat);

	//exists for debug purposes only - collider should NOT know about spritebatch
	void DrawCollider(SpriteBatch& m_spriteBatch) const;

	//gives direct access to the localPolygon's points
	Vector2 * GetLocalPoints() const;
	int GetPointCount() const;
	//set's the polygon's points to new local points
	void SetLocalPoints(int a_numPoints, Vector2 * m_points);

	//local shape
	Polygon2D localPolygon;

	//updated shape based on object's transform matrix
	Polygon2D globalPolygon;

};