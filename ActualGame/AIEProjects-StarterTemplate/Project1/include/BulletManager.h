#pragma once
#include "Bullet.h"
#include "CollisionManager.h"
#include <vector>

class SpriteBatch;
class Texture;

class BulletManager
{
public:
	BulletManager();
	BulletManager(SpriteBatch * a_spriteBatch, int WindowHeight, int WindowWidth, CollisionManager * collisionManager);
	~BulletManager();

	void UpdateBullets(float deltaTime);
	void CreateBullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, bool playerShot, Texture * bulletTexture);
	void DrawBullets();
	void ClearBullets();
	bool BulletOutOfWindow(Bullet * bullet);
	void RemoveDead();

	CollisionManager * m_collisionManager;
	SpriteBatch * m_spriteBatch;

	std::vector<Bullet*> bulletVector;
	std::vector<Bullet*>::iterator iter;

	int windowWidth;
	int windowHeight;
};
