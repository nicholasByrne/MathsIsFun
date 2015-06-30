#include "Tank.h"


Tank::Tank()
{
	tag = "tank";
	m_alive = true;
	m_position.x = 200;
	m_position.y = 200;
	m_position.y = 100;
	m_velocity.x = 100;
	m_velocity.y = 0;
	m_rotation = 90;
	m_scale.x = 1;
	m_scale.y = 1;

	m_direction = 1;
}


Tank::Tank(float pos_x, float pos_y, float rotation, Texture * tankTexture, float screenWidth, float screenHeight, int direction)
{
	tag = "tank";
	m_alive = true;
	m_position.x = pos_x;
	m_position.y = pos_y;
	m_rotation = PI * rotation;
	m_scale.x = 0.5f;
	m_scale.y = 0.5f;

	m_texture = tankTexture;

	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_direction = direction;

	if (direction == 1) //north
	{
		m_velocity.x = 0.0f;
		m_velocity.y = -100.0f;
	}
	else if (direction == 2) //east
	{
		m_velocity.x = 100.0f;
		m_velocity.y = 0.0f;
	}
	else if (direction == 3) //south
	{
		m_velocity.x = 0.0f;
		m_velocity.y = 100.0f;
	}
	else if (direction == 4) //west
	{
		m_velocity.x = -100.0f;
		m_velocity.y = 0.0f;
	}
}


Tank::~Tank()
{

}


void Tank::Update(float deltaTime) //N=1, E=2, S=3, W=4
{
	if ((m_direction == 1) && (m_position.y < 75.0f)) //travelling north
	{
		m_velocity.x = -100.0f;
		m_velocity.y = 0.0f;
		m_rotation = PI * 1.5f;
		m_direction = 4;
	}
	else if ((m_direction == 4) && (m_position.x < 75.0f)) //travelling west
	{
		m_velocity.x = 0.0f;
		m_velocity.y = 100.0f;
		m_rotation = PI * 1.0f;
		m_direction = 3;
	}
	else if ((m_direction == 3) && (m_position.y > m_screenHeight - 75.0f)) //travelling south
	{
		m_velocity.x = 100.0f;
		m_velocity.y = 0.0f;
		m_rotation = PI * 0.5f;
		m_direction = 2;
	}
	else if ((m_direction == 2) && (m_position.x > m_screenWidth - 75)) //travelling east
	{
		m_velocity.x = 0.0f;
		m_velocity.y = -100.0f;
		m_rotation = PI * 0.0f;
		m_direction = 1;
	}


	m_position += m_velocity * deltaTime;
	UpdateMatrix();
}


void Tank::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform.data[0]);
}


void Tank::OnCollision(GameObject * a_other)
{
	if (a_other->tag == "bullet") //if tank hit bullet
	{

	}
	else if (a_other->tag == "player") //if tank hit player
	{
		a_other->m_alive = false;
	}
	else if (a_other->tag == "tank") //if tank hit tank
	{
		
	}
	else if (a_other->tag == "rock") //if tank hit rock
	{

	}
	else //hit something else// tankTurret
	{

	}
}