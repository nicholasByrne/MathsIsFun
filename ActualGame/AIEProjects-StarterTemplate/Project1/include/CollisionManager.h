#pragma once
#include <vector>
#include "GameObject.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Rock.h"
#include "Tank.h"
#include "TankTurret.h"


class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void AddEntity(GameObject * entityToAdd);
	void RemoveEntity(GameObject * entityToRemove);

	void UpdateCollisions();
	bool CheckCollision(GameObject * object1, GameObject * object2);

	//removes objects where m_alive == false
	void RemoveDead();

	
private:
	std::vector<GameObject*>::iterator iter;
	std::vector<GameObject*>gameObjectVector;
};

