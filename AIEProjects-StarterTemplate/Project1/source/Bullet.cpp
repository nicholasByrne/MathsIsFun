#include "Bullet.h"
#include "SpriteBatch.h"


Bullet::Bullet()
{
}

Bullet::Bullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, Texture * bulletTexture)
{
	m_position = startingPosition;
	m_rotation = gunAngle;
	
	m_velocity.x = targetPosition.x - startingPosition.x;
	m_velocity.y = targetPosition.y - startingPosition.y;
	m_velocity.Normalise();


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
	m_spriteBatch->DrawSprite(m_texture, m_position.x, m_position.y, m_texture.GetWidth()/10, m_texture->GetHeight()/10, m_rotation + 90);
}