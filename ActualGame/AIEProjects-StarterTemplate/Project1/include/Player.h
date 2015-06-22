#pragma once
#include "GameObject.h"

class SpriteBatch;
class Texture;

class Player : public GameObject
{
public:
	Player();
	Player(Texture * playerTexture);
	~Player();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch * m_spriteBatch);

	void MoveNorth(float deltaTime);
	void MoveEast(float deltaTime);
	void MoveSouth(float deltaTime);
	void MoveWest(float deltaTime);

	void MoveNorthEast(float deltaTime);
	void MoveSouthEast(float deltaTime);
	void MoveSouthWest(float deltaTime);
	void MoveNorthWest(float deltaTime);

	//void Shoot(float deltaTime, BulletManager & bulletManager);

	float attackCooldown;




};
