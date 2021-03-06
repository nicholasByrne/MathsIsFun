#pragma once
#include "Entity.h"

class SpriteBatch;
class Texture;

class Bullet :	public Entity
{
public:
	Bullet();
	Bullet(Vector2 playerVector2, Vector2 mouseVector2, float gunAngle, float bulletSpeed, Texture * bulletTexture);
	~Bullet();

	void Update(float deltaTime);
	void Draw(SpriteBatch * m_spriteBatch);

	float angle;
	float speed;
};

