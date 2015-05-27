#include "BulletManager.h"
#include "SpriteBatch.h"
#include "Texture.h"

BulletManager::BulletManager()
{
	liveBullets = 0;
	maxBullets = 200;
	bulletArray = new Bullet * [maxBullets];
	for (int i = 0; i < maxBullets; i++)
	{
		bulletArray[i] = nullptr; //new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, bulletTexture);
	}
}


BulletManager::BulletManager(SpriteBatch * spritebatch)
{
	liveBullets = 0;
	maxBullets = 200;
	bulletArray = new Bullet * [maxBullets];
	m_spriteBatch = spritebatch;

	for (int i = 0; i < maxBullets; i++)
	{
		bulletArray[i] = nullptr; //new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, bulletTexture);
	}
}


BulletManager::~BulletManager()
{
	delete[] bulletArray;
}

void BulletManager::UpdateBullets(float deltaTime)
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArray[i] != nullptr)
		{
			bulletArray[i]->Update(deltaTime);
		}
	}
}


void BulletManager::DrawBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{

		//bulletArray[i].Draw();
		if (bulletArray[i] != nullptr)
		{
			bulletArray[i]->Draw(m_spriteBatch);
		}
	}
}


void BulletManager::CreateBullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, Texture * bulletTexture)
{
	delete bulletArray[liveBullets];
	bulletArray[liveBullets] = new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, bulletTexture);
	liveBullets++;
	if (liveBullets == maxBullets)
	{
		liveBullets = 0;
	}
}

