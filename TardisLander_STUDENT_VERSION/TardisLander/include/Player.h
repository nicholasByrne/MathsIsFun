#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Vector3.h"

class Player
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
	int m_fireSprite;
	bool m_bFlameOn;
	float m_rotation;
	Vector3 m_position;
	Vector3 m_velocity;
	bool m_bIsDead;
	bool m_bHasLanded;
};

#endif