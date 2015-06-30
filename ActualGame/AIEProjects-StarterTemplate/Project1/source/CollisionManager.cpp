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
void CollisionManager::AddEntity(GameObject * entityToAdd)
{
	gameObjectVector.push_back(entityToAdd);

}


void CollisionManager::RemoveEntity(GameObject * entityToRemove)
{
	for (iter = gameObjectVector.begin(); iter != gameObjectVector.end(); iter++)
	{
		if ((*iter) == entityToRemove)
		{
			delete entityToRemove;
			entityToRemove = nullptr;
	
			return;
		}
	}
}


bool CollisionManager::CheckCollision(GameObject * object1, GameObject * object2)
{ 
	Vector2 temp(object1->m_position - object2->m_position);
	float radii = object1->m_scale.x * object1->m_texture->GetWidth() / 2.0f + object2->m_scale.y * object2->m_texture->GetWidth() / 2.0f;

	//if ((a^2 + b^2) > c^2)
	if (temp.MagnitudeSqrd() < (radii * radii))
	{
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
		for (std::vector<GameObject*>::iterator iter2 = iter + 1; iter2 != gameObjectVector.end(); iter2++)
		{	
			//check collision between objects
			if (CheckCollision((*iter), (*iter2)))
			{
				//Resolve Collisions
				(*iter)->OnCollision((*iter2));
				(*iter2)->OnCollision((*iter));

			}
		}
	}
}


void CollisionManager::RemoveDead()
{
	for (iter = gameObjectVector.begin(); iter != gameObjectVector.end(); /*iter++*/)
	{
		if ((*iter) != nullptr && (*iter)->m_alive == false)
		{
			iter = gameObjectVector.erase( iter );	
		}
		else {
			iter++;
		}
	}
}