#include "GameObject.h"

GameObject::GameObject()
{
	m_position = Vector2();
	m_rotation = 0.f;
	m_scale = Vector2();
	m_alive = true;
}


GameObject::~GameObject()
{

}


void GameObject::UpdateMatrix()
{
	m_localTransform = Matrix3x3::CreateTranslation(m_position.x, m_position.y) * Matrix3x3::CreateRotation(m_rotation) * Matrix3x3::CreateScale(m_scale.x, m_scale.y);
}


void GameObject::Update(float deltaTime)
{


	UpdateMatrix();
}


void GameObject::Draw(SpriteBatch * m_spriteBatch)
{
	m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform.data[0]);
}


void GameObject::Translate(Vector2& translation)
{
	m_position += translation;
}


void GameObject::OnCollision(GameObject * a_other)
{
	
}