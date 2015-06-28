#include "CollisionManager.h"


CollisionManager::CollisionManager()
{
	entityArray = new GameObject*[100];
	for (int i = 0; i < 100; i++)
	{
		entityArray[i] = nullptr;
	}
}


CollisionManager::~CollisionManager()
{

}


void CollisionManager::CheckCollision(GameObject & object1, GameObject & object2)
{
	Vector2 temp(object1.m_position - object2.m_position);
	float radii = object1.m_radius + object2.m_radius;

	//if ((a^2 + b^2) > c^2)
	if (temp.MagnitudeSqrd() < (radii * radii))
	{
		object2.OnCollision(object1);
		object1.OnCollision(object2);
	}

}