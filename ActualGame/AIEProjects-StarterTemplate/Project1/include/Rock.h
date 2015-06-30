#pragma once
#include "GameObject.h"

class Rock :	public GameObject
{
public:
	Rock();
	Rock(float pos_x, float pos_y, Texture * rockTexture);
	~Rock();

	void Update(float deltaTime);
	void Draw(SpriteBatch * m_spriteBatch);
	void OnCollision(GameObject * a_other);

};

