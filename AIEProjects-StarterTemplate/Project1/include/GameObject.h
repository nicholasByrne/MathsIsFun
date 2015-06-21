#pragma once
#include "Vector2.h"
#include "SceneNode.h"
#include "Collider.h"

class SpriteBatch;
class Texture;

class GameObject : SceneNode
{
public:
	GameObject();
	virtual ~GameObject();

	void UpdateMatrix();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch * m_spriteBatch);

	//sets the gameobject's texture. If autoUpdateCollider is set to true, collider will be scaled to texture size
	void SetTexture(Texture* a_texture, bool autoUpdateCollider = true);

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_scale;
	float m_rotation;
	void Translate(Vector2 & translation);

	Texture * m_texture;
	Collider * m_collider;
	
	void SetCollider(Collider * a_collider, bool autoUpdateCollider = false);
	void UpdateCollider();
	//handles collision between 2 gameobjects
	void OnCollision(GameObject * a_other);
	
protected:
	int m_maxHealth;
	int m_currentHealth;
	float m_attackCooldown;
	float m_speed;

};

