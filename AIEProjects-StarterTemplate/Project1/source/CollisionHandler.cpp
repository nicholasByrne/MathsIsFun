#include "CollisionHandler.h"
#include "Geometry.h"
#include "Collider.h"
#include "Vector2.h"
#include "MathUtility.h"
#include <iostream>
using namespace MathLibrary;

CollisionHandler::CollisionHandler()
{

}

CollisionHandler::~CollisionHandler()
{
}

//check collision between two colliders
bool CollisionHandler::CheckCollision(Collider * a, Collider * b)
{
	//check types
	if (a->colliderType == ColliderType::CIRCLE && b->colliderType == ColliderType::CIRCLE)
	{
		return CheckCircleCollision((CircleCollider*)a, (CircleCollider*)b);
	}
	else if (a->colliderType == ColliderType::AABB && b->colliderType == ColliderType::AABB)
	{
		
		return CheckAABBCollision((BoxCollider*)a, (BoxCollider*)b);
	}
	else if (a->colliderType == ColliderType::AABB && b->colliderType == ColliderType::CIRCLE)
	{

		return CheckCircleAABBCollision((CircleCollider*)b, (BoxCollider*)a);
	}
	else if (a->colliderType == ColliderType::CIRCLE && b->colliderType == ColliderType::AABB)
	{
		return CheckCircleAABBCollision((CircleCollider*)a, (BoxCollider*)b);
	}
	else if (a->colliderType == ColliderType::POLYGON && b->colliderType == ColliderType::POLYGON)
	{
		Vector2 mtv;
		return CheckSATCollision((PolygonCollider*)a, (PolygonCollider*)b, mtv);
	}

	return false;
}

//Checks a circle collision
bool CollisionHandler::CheckCircleCollision(CircleCollider * a, CircleCollider * b)
{
	//calculate distance
	float dist = Vector2::Distance(a->globalCircle.center, b->globalCircle.center);

	if (dist <= a->globalCircle.radius + b->globalCircle.radius)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Checks an AABB collision
bool CollisionHandler::CheckAABBCollision(BoxCollider * a, BoxCollider * b)
{
	if (a->globalAABB.min.x <= b->globalAABB.max.x &&
		a->globalAABB.max.x >= b->globalAABB.min.x &&
		a->globalAABB.min.y <= b->globalAABB.max.y &&
		a->globalAABB.max.y >= b->globalAABB.min.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Check Circle and AABB collision
bool CollisionHandler::CheckCircleAABBCollision(CircleCollider * a, BoxCollider * b)
{
	Vector2 closestPoint;

	closestPoint.x = Clamp(a->globalCircle.center.x, b->globalAABB.min.x, b->globalAABB.max.x);
	closestPoint.y = Clamp(a->globalCircle.center.y, b->globalAABB.min.y, b->globalAABB.max.y);

	if ((a->globalCircle.center - closestPoint).Dot((a->globalCircle.center - closestPoint)) <= a->globalCircle.radius*a->globalCircle.radius)
		return true;

	return false;
}

//Check separating axis collision
bool CollisionHandler::CheckSATCollision(PolygonCollider * colliderA, PolygonCollider * colliderB, Vector2& outMTV)
{
	Polygon2D& polyA = colliderA->globalPolygon;
	Polygon2D& polyB = colliderB->globalPolygon;

	//create array of axes
	int numAxes = polyA.numPoints + polyB.numPoints;
	Vector2 * axes = new Vector2[numAxes];
	
	//set the axes
	CalculateAxes(polyA, axes);
	CalculateAxes(polyB, &axes[polyA.numPoints]);

	int indexOfMinAxis = 0;
	float minOverlap = 0.0f;

	// loop over the axes
	for (int i = 0; i < numAxes; i++)
	{
		Vector2 axis = axes[i];

		// project both shapes onto the axis
		Vector2 proj1 = Project( polyA, axis.Normalise() );
		Vector2 proj2 = Project( polyB, axis.Normalise() );

		//minimum axis is our MTV

		// do the projections overlap?
		if ( !Overlap(proj1, proj2) ) 
		{
			// then we can guarantee that the shapes do not overlap
			return false;
		}
		else
		{
			if (i == 0)
			{
				minOverlap = GetOverlap(proj1, proj2);
				indexOfMinAxis = 0;
			}
			else
			{
				float overlap = GetOverlap(proj1, proj2);

				if (overlap < minOverlap)
				{
					minOverlap = overlap;
					indexOfMinAxis = i;
				}
			}
		}
	}

	//if we're here - there was an overlap!
	delete[] axes;

	//set mtv
	if (indexOfMinAxis >= polyA.numPoints)
		minOverlap *= -1.0f;

	outMTV = axes[indexOfMinAxis].Normalise() * minOverlap;
	return true;
}

//Check separating axis collision
bool CollisionHandler::CheckSATPolygonCircleCollision(PolygonCollider * colliderA, CircleCollider * colliderB, Vector2& outMTV)
{
	Polygon2D& polyA = colliderA->globalPolygon;
	Circle2D& circleB = colliderB->globalCircle;

	//get the axes
	int numAxes = polyA.numPoints + 1; //one extra for the circle axis
	Vector2 * axes = new Vector2[numAxes];

	//set the axes
	CalculateAxes(polyA, axes);
	CalculateAxes(circleB, polyA, &axes[polyA.numPoints - 1]);

	int indexOfMinAxis = 0;
	float minOverlap = 0.0f;

	// loop over the axes
	for (int i = 0; i < numAxes; i++)
	{
		Vector2 axis = axes[i].Normalise();

		// project both shapes onto the axis
		Vector2 proj1 = Project(polyA, axis.Normalise());
		Vector2 proj2( axis.Dot(circleB.center) - circleB.radius, axis.Dot(circleB.center) + circleB.radius );

		//minimum axis is our MTV

		// do the projections overlap?
		if (!Overlap(proj1, proj2)) {
			// then we can guarantee that the shapes do not overlap
			return false;
		}
		else
		{
			if (i == 0)
			{
				minOverlap = GetOverlap(proj1, proj2);
				indexOfMinAxis = 0;
			}
			else
			{
				float overlap = GetOverlap(proj1, proj2);

				if (overlap < minOverlap)
				{
					minOverlap = overlap;
					indexOfMinAxis = i;
				}
			}
		}
	}

	// if we get here then we know that every axis had overlap on it
	// so we can guarantee an intersection

	//set mtv
	if (indexOfMinAxis > polyA.numPoints)
		minOverlap *= -1.0f;

	outMTV = axes[indexOfMinAxis].Normalise() * minOverlap;
	return true;

}

float CollisionHandler::GetOverlap(Vector2 proj1, Vector2 proj2)
{
	if (proj1.y - proj2.x < proj2.y - proj1.x)
		return 	proj1.y - proj2.x;
	else
		return proj2.y - proj1.x;
}

bool CollisionHandler::Overlap(Vector2 proj1, Vector2 proj2)
{
	if( proj1.y < proj2.x || proj2.y < proj1.x )
		return false; //no overlap
	else
		return true; //yes overlap
}

void CollisionHandler::CalculateAxes( const Polygon2D& polyA, Vector2 * m_axes )
{
	// loop over the vertices
	for (int i = 0; i < polyA.numPoints; i++)
	{
		// get the current vertex
		Vector2 p1 = polyA.points[i];

		// get the next vertex
		Vector2 p2 = polyA.points[(i + 1 == polyA.numPoints) ? 0 : i + 1];

		// subtract the two to get the edge vector
		Vector2 edge = p1 - p2;

		// get either perpendicular vector
		Vector2 normal = edge.Perpindicular();

		m_axes[i] = normal;
	}
}

void CollisionHandler::CalculateAxes(const Circle2D& circle, const Polygon2D& polyA, Vector2 * m_axes)
{
	int nearestPointIndex = 0;

	float minDist = (circle.center - polyA.points[0]).MagnitudeSqrd();

	// loop over the vertices
	for (int i = 0; i < polyA.numPoints; i++)
	{
		float dist = (circle.center - polyA.points[i]).MagnitudeSqrd();

		if (dist < minDist)
		{
			nearestPointIndex = i;
			minDist = dist;
		}
	}

	m_axes[0] = circle.center - polyA.points[nearestPointIndex];

}

Vector2 CollisionHandler::Project(Polygon2D& polyA, Vector2 axis)
{
	//set min and max to first point projected
	float min = axis.Dot( polyA.points[0] );
	float max = min;

	for ( int i = 1; i < polyA.numPoints; i++ ) 
	{
		float proj = axis.Dot(polyA.points[i]);

		//keep track of min and max projection
		if (proj < min)
		{
			min = proj;
		}
		else if (proj > max)
		{
			max = proj;
		}
	}

	return Vector2(min, max);
}
