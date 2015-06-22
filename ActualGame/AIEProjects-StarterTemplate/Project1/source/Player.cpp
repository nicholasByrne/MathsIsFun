#include "Player.h"
#include "BulletManager.h"

Player::Player()
{

}


Player::Player(Texture * playerTexture)
{
	m_texture = playerTexture;
	attackCooldown = 1;
}


Player::~Player()
{

}


void Player::Update(float deltaTime)
{
	attackCooldown -= deltaTime;
}


void Player::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSprite(m_texture, m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
	//m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform);
}


void Player::MoveNorth(float deltaTime)
{
	m_position.y -= 300 * deltaTime;
}


void Player::MoveEast(float deltaTime)
{
	m_position.x += 300 * deltaTime;
}


void Player::MoveSouth(float deltaTime)
{
	m_position.y += 300 * deltaTime;
}


void Player::MoveWest(float deltaTime)
{
	m_position.x -= 300 * deltaTime;
}

	 

void Player::MoveNorthEast(float deltaTime)
{
	m_position.y -= 300 * deltaTime * 0.707;
	m_position.x += 300 * deltaTime * 0.707;
}


void Player::MoveSouthEast(float deltaTime)
{
	m_position.x += 300 * deltaTime * 0.707;
	m_position.y += 300 * deltaTime * 0.707;
}


void Player::MoveSouthWest(float deltaTime)
{
	m_position.y += 300 * deltaTime * 0.707;
	m_position.x -= 300 * deltaTime * 0.707;
}


void Player::MoveNorthWest(float deltaTime)
{
	m_position.y -= 300 * deltaTime * 0.707;
	m_position.x -= 300 * deltaTime * 0.707;
}

