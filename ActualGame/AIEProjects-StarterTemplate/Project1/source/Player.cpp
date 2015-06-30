#include "Player.h"
#include "BulletManager.h"

Player::Player()
{
	m_alive = true;
}


Player::Player(Texture * playerTexture, Texture * deadTexture)
{
	tag = "player";
	m_alive = true;
	m_texture = playerTexture;
	m_textureDead = deadTexture;
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
	m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform.data[0]);
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


void Player::OnCollision(GameObject * a_other)
{
	if (a_other->tag == "bullet") //if player hit bullet
	{

	}
	else if (a_other->tag == "player") //if player hit player
	{
		
	}
	else if (a_other->tag == "tank") //if player hit tank
	{
		//m_alive = false;
		m_texture = m_textureDead;
	}
	else if (a_other->tag == "rock") //if player hit rock
	{
		
	}
	else //hit something else// tankTurret
	{

	}
}