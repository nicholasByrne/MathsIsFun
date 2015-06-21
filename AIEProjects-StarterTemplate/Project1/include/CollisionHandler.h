#pragma once
#include <vector>
#include "Vector2.h"
#include "MathUtility.h"
#include "Geometry.h"
using namespace std;
using namespace MathLibrary;

class Collider;
class CircleCollider;
class BoxCollider;
class PolygonCollider;
class CollisionHandler
{
public:
	CollisionHandler();
	~CollisionHandler();

	bool CheckCollision(Collider * a, Collider * b);
	bool CheckCircleCollision(CircleCollider * a, CircleCollider * b);
	bool CheckAABBCollision(BoxCollider * a, BoxCollider * b);
	bool CheckCircleAABBCollision(CircleCollider * a, BoxCollider * b);

	bool CheckSATCollision(PolygonCollider * colliderA, PolygonCollider * colliderB, Vector2& outMTV);
	bool CheckSATPolygonCircleCollision(PolygonCollider * colliderA, CircleCollider * colliderB, Vector2& outMTV);

	//Calculate the axes for the two shapes - you need to pass in an array of Vector2
	//that is equal to shape1 axes to shape2 axes. Once the function call is finished,
	//your m_axes array will contain the required object axes
	static void CalculateAxes(const Polygon2D& shape1, Vector2 * m_axes);
	static void CalculateAxes(const Circle2D& circle1, const Polygon2D& shape1, Vector2 * m_axes);

	//axes must be normalised to get valid projections
	static Vector2 Project(Polygon2D& polyA, Vector2 axis);

	static bool Overlap(Vector2 proj1, Vector2 proj2);
	static float GetOverlap(Vector2 proj1, Vector2 proj2);
};
