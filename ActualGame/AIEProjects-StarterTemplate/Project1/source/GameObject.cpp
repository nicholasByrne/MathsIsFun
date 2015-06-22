#include "GameObject.h"

GameObject::GameObject()
{

}


GameObject::~GameObject()
{

}


void GameObject::UpdateMatrix()
{
	Matrix3x3 newMatrix = Matrix3x3::CreateTranslation(m_position.x, m_position.y) * Matrix3x3::CreateRotation(m_rotation) * Matrix3x3::CreateScale(m_scale.x, m_scale.y);
	m_localTransform = newMatrix;
}


void GameObject::Update(float deltaTime)
{

}



void GameObject::Draw(SpriteBatch * m_spriteBatch)
{

}


void GameObject::Translate(Vector2& translation)
{
	m_position += translation;
}


void GameObject::OnCollision(GameObject & a_other)
{
	
}