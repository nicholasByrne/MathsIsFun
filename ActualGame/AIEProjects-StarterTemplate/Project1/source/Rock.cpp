#include "Rock.h"


Rock::Rock()
{
	tag = "rock";
	m_position.x = 100;
	m_position.y = 100;
	m_velocity.x = 0;
	m_velocity.y = 0;
	m_rotation = 90;
	m_radius = 100;
	m_scale.x = 1;
	m_scale.y = 1;
}


Rock::Rock(float pos_x, float pos_y, float radius, Texture * rockTexture)
{
	tag = "rock";
	m_position.x = pos_x;
	m_position.y = pos_y;
	m_velocity.x = 0;
	m_velocity.y = 0;
	m_rotation = 90;
	m_radius = radius;
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


