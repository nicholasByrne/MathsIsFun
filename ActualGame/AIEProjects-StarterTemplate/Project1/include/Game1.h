
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
class SpriteBatch;
#include "CollisionManager.h"
#include "BulletManager.h"
#include "Vector2.h"
#include <cmath>
#include "Player.h"
#include "Rock.h"
#include "Tank.h"
#include "TankTurret.h"

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

	BulletManager * bulletManager;

protected:

	SpriteBatch *m_spritebatch;
	CollisionManager * collisionManager;
	Texture * m_playerTexture;
	Texture * m_bulletTexture;
	//Texture * m_tankTexture;
	Texture * m_tankTurretTexture;
	Texture * m_blood;

	Font * m_font;

	Vector2 mousePos;
	
	float playerRotate;
	float playerGunAngle;

	//GetInput()->GetMouseXY(xpos, ypos);
	int *ypos = new int; //cursor
	int *xpos = new int;
	float angle;

	Player * player1;
	Tank * tank[4];
	TankTurret* tankTurret[4];
	
	int aliveTanks;

private:
};

#endif