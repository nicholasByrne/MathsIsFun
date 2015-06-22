#pragma once
#include "GameObject.h"


class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void AddEntity(GameObject * entityToAdd);
	void RemoveEntity();
	void CheckCollision(GameObject & object1, GameObject & object2);
	
private:
	GameObject ** entityArray;
};

