#pragma once
#include "GameObject.h"
#include "Tank.h"

class Player;

class TankTurret :	public GameObject
{
public:
	TankTurret();
	TankTurret(Tank * tankBody, Player * target, Texture * texture);
	~TankTurret();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch * m_spriteBatch);

	Tank * tank;
	Player * m_target;

	void OnCollision(GameObject * a_other);

};

