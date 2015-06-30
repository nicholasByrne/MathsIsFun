#pragma once
#include "Vector2.h"
#include "SceneNode.h"
#include "Texture.h"
#include "SpriteBatch.h"
#include <string>

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

	std::string tag;
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_scale;
	float m_rotation;
	void Translate(Vector2 & translation);
	bool m_alive;

	Texture * m_texture;
	
	virtual void OnCollision(GameObject * a_other);
	
protected:
	int m_maxHealth;
	int m_currentHealth;
	float m_attackCooldown;
	float m_speed;

};

