#pragma once
#include "Entity.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void AddEntity(Entity * entityToAdd);
	void RemoveEntity();
	void CheckCollision();
	
private:
	Entity ** entityArray;
};

