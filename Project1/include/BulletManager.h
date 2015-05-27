#pragma once
#include "Bullet.h"

class SpriteBatch;
class Texture;

class BulletManager
{
public:
	BulletManager();
	BulletManager(SpriteBatch * a_spriteBatch);
	~BulletManager();

	void UpdateBullets(float deltaTime);
	void CreateBullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, Texture * bulletTexture);
	void DrawBullets();

	Bullet ** bulletArray;
	int liveBullets;
	int maxBullets;
	SpriteBatch * m_spriteBatch;
};
