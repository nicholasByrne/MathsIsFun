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
