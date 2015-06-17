#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Vector3.h"
#include "SceneNode.h"
#include "Sprite.h"
#include "Matrix3x3.h"

class Player : SceneNode
{
public:
	Player(void);
	~Player(void);
	
	void Update(float dt);
	void Draw();
	void Reset();

	inline bool IsDead() {return m_bIsDead;}
	inline bool HasLanded() {return m_bHasLanded;}

private:
	int m_sprite;
	Sprite* m_pFlame;
	bool m_bFlameOn;
	Vector3 m_velocity;
	float m_rotation;
	bool m_bIsDead;
	bool m_bHasLanded;
};

#endif