#include "TankTurret.h"
#include "Player.h"

TankTurret::TankTurret()
{
	tag = "tankTurret";
	m_alive = true;
	m_scale = Vector2(0.5f, 0.5f);
}


TankTurret::TankTurret(Tank * tankBody, Player * target, Texture * texture)
{
	tag = "tankTurret";
	m_alive = true;
	tank = tankBody;
	m_texture = texture;
	m_target = target;
	m_scale = Vector2(0.5f, 2.f);
	m_position.y += 200.0f;
}


TankTurret::~TankTurret()
{

}


void TankTurret::Update(float deltaTime)
{
	if (tank == nullptr || tank->m_alive == false)
	{
		m_alive = false;
		return;
	}

	float angle = atan2(m_target->m_position.y - tank->m_position.y, m_target->m_position.x - tank->m_position.x);
	m_rotation = angle;

	UpdateMatrix();
}


//m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform.data[0]);
//m_spritebatch->DrawSpriteTransformed3x3(m_texture, &(localMatrix * localMatrix2).m[0]); 
void TankTurret::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSpriteTransformed3x3(m_texture, ( tank->GetLocalTransform() * m_localTransform ).data[0]);
}


void TankTurret::OnCollision(GameObject * a_other)
{

}