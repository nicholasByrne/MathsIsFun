#pragma once
#include "GameObject.h"
#include <vector>


class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void AddEntity(GameObject & entityToAdd);
	void RemoveEntity(GameObject & entityToRemove);
	void UpdateCollisions();
	bool CheckCollision(GameObject & object1, GameObject & object2);

	
private:
	std::vector<GameObject>::iterator iter;
	std::vector<GameObject>gameObjectVector;
};

