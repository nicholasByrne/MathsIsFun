#include "CollisionManager.h"


CollisionManager::CollisionManager()
{
	//iter = gameObjectVector.begin(); iter != gameObjectVector.end(); iter++
	iter = gameObjectVector.begin();
}


CollisionManager::~CollisionManager()
{

}

//add entity to collision manager
void CollisionManager::AddEntity(GameObject & entityToAdd)
{
	gameObjectVector.push_back(entityToAdd);

}


void CollisionManager::RemoveEntity(GameObject & entityToRemove)
{
	for (iter = gameObjectVector.begin(); iter != gameObjectVector.end(); iter++)
	{
		//if ((*iter) == entityToRemove)
		//{
		//
		//}
	}
}


bool CollisionManager::CheckCollision(GameObject & object1, GameObject & object2)
{ 
	Vector2 temp(object1.m_position - object2.m_position);
	float radii = object1.m_radius + object2.m_radius;

	//if ((a^2 + b^2) > c^2)
	if (temp.MagnitudeSqrd() < (radii * radii))
	{
		object2.OnCollision(object1);
		object1.OnCollision(object2);
		return true;
	}
	
	return false;
}

void CollisionManager::UpdateCollisions()
{

	//for every object
	for (iter = gameObjectVector.begin(); iter != gameObjectVector.end(); iter++)
	{
		//for every object
		for (std::vector<GameObject>::iterator iter2 = iter + 1; iter2 != gameObjectVector.end(); iter2++)
		{
			//check collision between objects
			if (CheckCollision((*iter), (*iter2)))
			{
				//physically resolve the collision (stop them from being inside eachother)
				//push circles away
				(*iter).OnCollision((*iter2));
				(*iter2).OnCollision((*iter));

			}
		}
	}
		//for every other object	
	
}