#pragma once
#include "GameObject.h"

class SpriteBatch;
class Texture;

class Bullet :	public GameObject
{
public:
	Bullet();
	Bullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, Texture * bulletTexture);
	~Bullet();

	void Update(float deltaTime);
	void Draw(SpriteBatch * m_spriteBatch);

	//float angle;
	//float speed;
	bool playerShot;
};

