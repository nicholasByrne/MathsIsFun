#include "Bullet.h"
#include "SpriteBatch.h"


Bullet::Bullet()
{
}

Bullet::Bullet(Vector2 startingPosition, Vector2 targetPosition, float gunAngle, float bulletSpeed, Texture * bulletTexture)
{
	position = startingPosition;
	angle = gunAngle;
	
	velocity.x = targetPosition.x - startingPosition.x;
	velocity.y = targetPosition.y - startingPosition.y;
	velocity.Normalise();


	//velocity.x = bulletSpeed * (cos(angle * PI / 180));
	//velocity.y = bulletSpeed * (sin(angle * PI / 180));
	texture = bulletTexture;
	speed = bulletSpeed;
}


Bullet::~Bullet()
{
}


void Bullet::Update(float deltaTime)
{
	position += velocity * speed * deltaTime;
}


void Bullet::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSprite(texture, position.x, position.y, texture->GetWidth()/10, texture->GetHeight()/10, angle + 90);
}