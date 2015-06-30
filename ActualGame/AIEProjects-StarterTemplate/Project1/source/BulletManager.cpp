#include "BulletManager.h"
#include "SpriteBatch.h"
#include "Texture.h"

BulletManager::BulletManager()
{

	iter = bulletVector.begin();
	//new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, bulletTexture);
}


BulletManager::BulletManager(SpriteBatch * spritebatch, int WindowHeight, int WindowWidth, CollisionManager * collisionManager)
{
	m_spriteBatch = spritebatch;
	windowWidth = WindowWidth;
	windowHeight = WindowHeight;
	m_collisionManager = collisionManager;
	iter = bulletVector.begin();
}


BulletManager::~BulletManager()
{
	
}

void BulletManager::UpdateBullets(float deltaTime)
{
	for (iter = bulletVector.begin(); iter != bulletVector.end(); iter++)
	{
		(*iter)->Update(deltaTime);
	}
}


void BulletManager::DrawBullets()
{
	for (iter = bulletVector.begin(); iter != bulletVector.end(); iter++)
	{
		if ((*iter) != nullptr)
		(*iter)->Draw(m_spriteBatch);
	}
}


void BulletManager::CreateBullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, bool playerShot, Texture * bulletTexture)
{
	Bullet * newBullet = new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, playerShot, bulletTexture);
	bulletVector.push_back(newBullet);
	m_collisionManager->AddEntity((GameObject*)newBullet);

	//bulletVector.push_back(new Bullet(startingPosition, targetPosition, gunAngle, bulletSpeed, playerShot, bulletTexture));
	//m_collisionManager->AddEntity(bulletVector.back);
}


void BulletManager::ClearBullets()
{
	for (iter = bulletVector.begin(); iter != bulletVector.end(); iter++)
	{
		delete (*iter);
		bulletVector.erase(iter);
	}
}


bool BulletManager::BulletOutOfWindow(Bullet * bullet)
{
	if (bullet->m_position.x > windowWidth + 100) //RHS
	{
		return true;
	}
	else if (bullet->m_position.x < -100) //LHS
	{
		return true;
	}
	else if (bullet->m_position.y > windowHeight + 100) //Bottom
	{
		return true;
	}
	else if (bullet->m_position.y < -100) //Top
	{
		return true;
	}
	else
		return false;
}


void BulletManager::RemoveDead()
{
	for (iter = bulletVector.begin(); iter != bulletVector.end(); /*iter++*/)
	{


		if ((*iter) != nullptr && (*iter)->m_alive == false)
		{
			m_collisionManager->RemoveDead();
			/*delete *iter;
			*iter = nullptr;*/
			//m_collisionManager->RemoveDead();
			iter = bulletVector.erase(iter);

		}
		else {
			iter++;
		}
	}
}