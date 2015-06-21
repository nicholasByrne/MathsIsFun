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


BulletManager::BulletManager(SpriteBatch * spritebatch, int WindowHeight, int WindowWidth)
{
	liveBullets = 0;
	maxBullets = 200;
	bulletArray = new Bullet * [maxBullets];
	m_spriteBatch = spritebatch;
	windowWidth = WindowWidth;
	windowHeight = WindowHeight;

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
			if (BulletOutOfWindow(bulletArray[i]) == true)
			{
				delete bulletArray[i];
				bulletArray[i] = nullptr;
			}
			else
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


void BulletManager::ClearBullets()
{
	for (int i = 0; i < maxBullets; i++)
	{
		if (bulletArray[i] != nullptr)
		{
			delete bulletArray[i];
		}
	}
}


bool BulletManager::BulletOutOfWindow(Bullet * bullet)
{
	if (bullet->position.x > windowWidth + 100) //RHS
	{
		return true;
	}
	else if (bullet->position.x < -100) //LHS
	{
		return true;
	}
	else if (bullet->position.y > windowHeight + 100) //Bottom
	{
		return true;
	}
	else if (bullet->position.y < -100) //Top
	{
		return true;
	}
	else
		return false;
}