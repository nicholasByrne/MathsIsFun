#pragma once
#include "Vector2.h"
#include "SceneNode.h"
#include "Texture.h"
#include "SpriteBatch.h"
#include "CollisionCircle.h"

class SpriteBatch;
class Texture;

//m_spriteBatch->DrawSpriteTransformed3x3(m_texture, m_localTransform);

class GameObject : public SceneNode
{
public:
	GameObject();
	virtual ~GameObject();

	void UpdateMatrix();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch * m_spriteBatch);

	//CollisionCircle collisionCircle;

	Matrix3x3 localMatrix;

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_scale;
	float m_rotation;
	float m_radius;
	void Translate(Vector2 & translation);

	Texture * m_texture;
	
	virtual void OnCollision(GameObject & a_other);
	
protected:
	int m_maxHealth;
	int m_currentHealth;
	float m_attackCooldown;
	float m_speed;

};

