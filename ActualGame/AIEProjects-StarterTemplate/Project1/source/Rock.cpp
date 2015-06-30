#include "Rock.h"


Rock::Rock()
{
	tag = "rock";
	m_alive = true;
	m_position.x = 100;
	m_position.y = 100;
	m_velocity.x = 0;
	m_velocity.y = 0;
	m_rotation = 90;
	m_scale.x = 1;
	m_scale.y = 1;
}


Rock::Rock(float pos_x, float pos_y, Texture * rockTexture)
{
	tag = "rock";
	m_alive = true;
	m_position.x = pos_x;
	m_position.y = pos_y;
	m_velocity.x = 0;
	m_velocity.y = 0;
	m_rotation = 90;
	m_scale.x = 1;
	m_scale.y = 1;
}


Rock::~Rock()
{
}


void Rock::Update(float deltaTime)
{

}


void Rock::Draw(SpriteBatch * m_spriteBatch)
{
	
}


void Rock::OnCollision(GameObject * a_other)
{
	if (a_other->tag == "bullet") //if rock hit bullet
	{
		a_other->m_alive = false;
	}
	else if (a_other->tag == "player") //if rock hit player
	{

	}
	else if (a_other->tag == "tank") //if rock hit tank
	{
		m_alive = false;
	}
	else if (a_other->tag == "rock") //if rock hit rock
	{

	}
	else //hit something else// tankTurret
	{

	}
}