#include "GameObject.h"
#include "SpriteBatch.h"
#include "Texture.h"

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


void GameObject::SetTexture(Texture* a_texture, bool autoUpdateCollider)
{
	m_texture = a_texture;

	if (autoUpdateCollider)
	{
		UpdateCollider();
	}
}


void GameObject::Translate(Vector2& translation)
{
	m_position += translation;
}


void GameObject::SetCollider(Collider * a_collider, bool autoUpdateCollider)
{
	m_collider = a_collider;

	//update collider
	UpdateCollider();
}


void GameObject::UpdateCollider()
{
	if (m_collider == nullptr || m_texture == nullptr)
		return;

	if (m_collider->colliderType == ColliderType::CIRCLE)
	{
		//generate circle collider based on texture width
		((CircleCollider*)m_collider)->localCircle.radius = m_texture->GetWidth() / 2.0f;
	}
	else if (m_collider->colliderType == ColliderType::AABB)
	{
		//generate AABB size based on texture dimensions
		((BoxCollider*)m_collider)->localAABB.min = Vector2(-(m_texture->GetWidth() / 2.0f), -(m_texture->GetHeight() / 2.0f));
		((BoxCollider*)m_collider)->localAABB.max = Vector2(m_texture->GetWidth() / 2.0f, m_texture->GetHeight() / 2.0f);
	}
	else if (m_collider->colliderType == ColliderType::POLYGON)
	{

		Vector2 * tempPoints = ((PolygonCollider*)m_collider)->GetLocalPoints();

		//generate polygon collider size based on texture width - this is a very rudimentary solution that only takes into
		//account width and won't work for non-uniformly spaced, complex polygons
		for (int i = 0; i < ((PolygonCollider*)m_collider)->GetPointCount(); i++)
		{
			tempPoints[i] *= (float)m_texture->GetWidth();
		}

		//manually set the points back to refresh the collider - this function will also allow you to set different points
		//if required
		((PolygonCollider*)m_collider)->SetLocalPoints(((PolygonCollider*)m_collider)->GetPointCount(), tempPoints);
	}
}


void GameObject::OnCollision(GameObject * a_other)
{
	
}