#pragma once
#include "GameObject.h"

class SpriteBatch;
class Texture;

class Bullet :	public GameObject
{
public:
	Bullet();
	Bullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, bool playerShot, Texture * bulletTexture);
	~Bullet();

	void Update(float deltaTime);
	void Draw(SpriteBatch * m_spriteBatch);
	
	bool m_playerShot;

	void OnCollision(GameObject * a_other);
};

