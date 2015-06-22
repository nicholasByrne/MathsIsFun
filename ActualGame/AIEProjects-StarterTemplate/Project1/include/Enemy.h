#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch * m_spriteBatch);

};

