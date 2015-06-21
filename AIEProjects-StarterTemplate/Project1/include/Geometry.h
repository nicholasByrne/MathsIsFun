#pragma once

#ifdef MATHLIBRARYDLL_EXPORTS
#define MATHLIBRARYDLL_API __declspec(dllexport) 
#else
#define MATHLIBRARYDLL_API __declspec(dllimport) 
#endif

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3x3.h"
#include <cmath>

namespace MathLibrary
{
	//Represents both a Line and a Line Segments
	struct Line2D
	{
		Vector2 P1;
		Vector2 P2;
	};

	struct Ray2D
	{
		Vector2 origin;
		Vector2 direction;
	};

	struct Circle2D
	{
		Vector2 center;
		float radius;

		MATHLIBRARYDLL_API Circle2D operator*(const Matrix3x3& mat)
		{
			Circle2D newCircle;
			newCircle.center = mat * center;
			newCircle.radius = Vector2(mat.data[0][0], mat.data[1][0]).Magnitude() * radius;
			return newCircle;
		}
	};

	MATHLIBRARYDLL_API Circle2D operator*(const Matrix3x3& mat, Circle2D& rhs);

	struct AABB2D
	{
		Vector2 min;
		Vector2 max;

		MATHLIBRARYDLL_API AABB2D operator*(const Matrix3x3& mat)
		{
			AABB2D newAABB;

			Vector2 verts[4];

			//rotate bounding box and then get the min and max
			verts[0].x = min.x; verts[0].y = min.y;
			verts[1].x = max.x; verts[1].y = min.y;
			verts[2].x = max.x; verts[2].y = max.y;
			verts[3].x = min.x; verts[3].y = max.y;
		
			//this is terrible - shouldn't use arbitrary values - use
			//max float value or find another way to do this (alternatively, don't 
			//do this at all because it's unnecessary)
			newAABB.min.x = 100000.f;
			newAABB.min.y = 100000.f;
			newAABB.max.x = -100000.f;
			newAABB.max.y = -100000.f;

			for (int i = 0; i < 4; i++)
			{
				verts[i] = mat * verts[i];

				if (verts[i].x < newAABB.min.x)
					newAABB.min.x = verts[i].x;

				if (verts[i].y < newAABB.min.y)
					newAABB.min.y = verts[i].y;

				if (verts[i].x > newAABB.max.x)
					newAABB.max.x = verts[i].x;

				if (verts[i].y > newAABB.max.y)
					newAABB.max.y = verts[i].y;

			}

			return newAABB;
		}
	};

	MATHLIBRARYDLL_API AABB2D operator*(const Matrix3x3& mat, AABB2D& rhs);

	struct Polygon2D
	{
		Vector2 * points = nullptr;
		int numPoints = 0;

		//Set's points to transformed points
		MATHLIBRARYDLL_API void SetTransformedPoints(int a_numPoints, Vector2 * a_points, const Matrix3x3& mat)
		{
			//if we don't have the same amount of points
			if (numPoints != a_numPoints)
			{
				if (points != nullptr)
					delete[] points;

				points = new Vector2[a_numPoints];
				numPoints = a_numPoints;
			}

			for (int i = 0; i < numPoints; i++)
			{
				points[i] = mat * a_points[i];
			}
		}

		//Copies m_points into localPoints
		MATHLIBRARYDLL_API void SetLocalPoints( int a_numPoints, Vector2 * m_points )
		{
			if (points != nullptr)
				delete[] points;

			points = new Vector2[a_numPoints];
			numPoints = a_numPoints;

			for (int i = 0; i < numPoints; i++)
			{
				points[i] = m_points[i];
			}			
		}
	};

}