#include "Player.h"
#include "BulletManager.h"

Player::Player()
{

}


Player::Player(Texture * playerTexture)
{
	tag = "player";
	m_texture = playerTexture;
	attackCooldown = 1;
	m_position.x = 200;
	m_position.y = 200;
	m_scale.x = 0.25f;
	m_scale.y = 0.25f;
}


Player::~Player()
{

}


void Player::Update(float deltaTime)
{
	attackCooldown -= deltaTime;
	UpdateMatrix();
}


void Player::Draw(SpriteBatch * m_spriteBatch)
{
	//m_spriteBatch->DrawSprite(m_texture, m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
	m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform.data[0]);
}

void Player::OnCollision(GameObject& other)
{
	//deal with collision
	if (other.tag == "Bullet")
	{
		//you're a bullet

	}
	//check if bullet and handle appropriately
	

}

void Player::MoveNorth(float deltaTime)
{
	m_position.y -= 300 * deltaTime;
	m_rotation = PI * 0.0f;
}


void Player::MoveEast(float deltaTime)
{
	m_position.x += 300 * deltaTime;
	m_rotation = PI * 0.5f;
}


void Player::MoveSouth(float deltaTime)
{
	m_position.y += 300 * deltaTime;
	m_rotation = PI * 1.0f;
}


void Player::MoveWest(float deltaTime)
{
	m_position.x -= 300 * deltaTime;
	m_rotation = PI * 1.5f;
}

	 

void Player::MoveNorthEast(float deltaTime)
{
	m_position.y -= 300 * deltaTime * 0.707;
	m_position.x += 300 * deltaTime * 0.707;
	m_rotation = PI * 0.25f;
}


void Player::MoveSouthEast(float deltaTime)
{
	m_position.x += 300 * deltaTime * 0.707;
	m_position.y += 300 * deltaTime * 0.707;
	m_rotation = PI * 0.75f;
}


void Player::MoveSouthWest(float deltaTime)
{
	m_position.y += 300 * deltaTime * 0.707;
	m_position.x -= 300 * deltaTime * 0.707;
	m_rotation = PI * 1.25f;
}


void Player::MoveNorthWest(float deltaTime)
{
	m_position.y -= 300 * deltaTime * 0.707;
	m_position.x -= 300 * deltaTime * 0.707;
	m_rotation = PI * 1.75f;
}

