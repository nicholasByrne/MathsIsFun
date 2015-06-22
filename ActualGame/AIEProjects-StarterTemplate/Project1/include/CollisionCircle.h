#pragma once
#include "Vector2.h"
class CollisionCircle
{
public:
	CollisionCircle();
	~CollisionCircle();

	void Update(Vector2 &newPosition);
	Vector2 position;
	float radius;
};

