#pragma once
#include "GameObject.h"
//#include "TankTurret.h"

class GameObject;

class Tank :	public GameObject
{
public:
	Tank();
	Tank(float pos_x, float pos_y, float radius, Texture * tankTexture, float screenWidth, float screenHeight, int direction);
	~Tank();

	void Update(float deltaTime);
	void Draw(SpriteBatch * m_spriteBatch);

	int m_direction; //N=1, E=2, S=3, W=4
	float m_screenWidth;
	float m_screenHeight;

};

