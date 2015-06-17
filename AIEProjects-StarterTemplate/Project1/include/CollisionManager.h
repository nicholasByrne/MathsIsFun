#pragma once
#include "GameObject.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void AddEntity(GameObject * entityToAdd);
	void RemoveEntity();
	void CheckCollision();
	
private:
	GameObject ** entityArray;
};

