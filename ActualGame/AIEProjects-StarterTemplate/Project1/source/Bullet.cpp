#include "Bullet.h"
#include "SpriteBatch.h"


Bullet::Bullet()
{
	m_texture = nullptr;
}

Bullet::Bullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, bool playerShot, Texture * bulletTexture)
{
	m_position = startingPosition;
	m_rotation = gunAngle;
	
	m_velocity.x = targetPosition.x - startingPosition.x;
	m_velocity.y = targetPosition.y - startingPosition.y;
	m_velocity.NormaliseThis();

	m_playerShot = playerShot;

	//velocity.x = bulletSpeed * (cos(angle * PI / 180));
	//velocity.y = bulletSpeed * (sin(angle * PI / 180));
	m_texture = bulletTexture;
	m_speed = bulletSpeed;
}


Bullet::~Bullet()
{
}


void Bullet::Update(float deltaTime)
{
	m_position += m_velocity * m_speed * deltaTime;
}


void Bullet::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSprite(m_texture, m_position.x, m_position.y, m_texture->GetWidth()/10, m_texture->GetHeight()/10, m_rotation + 90);
}


void Bullet::OnCollision(GameObject * a_other)
{
	if (a_other->tag == "bullet") //if bullet hit bullet
	{

	}
	else if (m_playerShot == false && a_other->tag == "player") //if tankBullet hit player
	{
		//a_other->m_alive = false;
		//m_alive = false;
	}
	else if (m_playerShot == true && a_other->tag == "tank") //if playerBullet hit tank
	{
		a_other->m_alive = false;
		m_alive = false;
	}
	else if (a_other->tag == "rock") //bullet hit rock
	{
		//m_alive = false;
	}
	else //hit something else// tankTurret
	{

	}
}