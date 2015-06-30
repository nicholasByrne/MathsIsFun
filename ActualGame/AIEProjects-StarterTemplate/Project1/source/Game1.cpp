#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>


Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	m_playerTexture = new Texture("./Images/box0_256.png");
	m_bulletTexture = new Texture("./Images/crate.png");
	//m_tankTexture = new Texture();
	m_tankTurretTexture = new Texture ("./Images/box1_256.png");
	m_blood = new Texture("./Images/realblood.png");

	m_font = new Font("./Fonts/Hobo_22px.fnt");

	player1 = new Player(m_playerTexture, m_blood);
	tank[0] = new Tank(74.0f, 74.0f, 1.0f, m_playerTexture, (float)windowWidth, (float)windowHeight, 3); //NW
	tank[1] = new Tank(windowWidth - 76.0f, 74.0f, 1.5f, m_playerTexture, (float)windowWidth, (float)windowHeight, 4); //NE
	tank[2] = new Tank(windowWidth - 76.0f, windowHeight - 76.0f, 0.0f, m_playerTexture, (float)windowWidth, (float)windowHeight, 1); //SE
	tank[3] = new Tank(74.0f, windowHeight - 76.0f, 0.5f, m_playerTexture, (float)windowWidth, (float)windowHeight, 2); //SW
	tankTurret[0] = new TankTurret(tank[0], player1, m_tankTurretTexture);
	tankTurret[1] = new TankTurret(tank[1], player1, m_tankTurretTexture);
	tankTurret[2] = new TankTurret(tank[2], player1, m_tankTurretTexture);
	tankTurret[3] = new TankTurret(tank[3], player1, m_tankTurretTexture);
	
	mousePos.x = 0.0f;
	mousePos.y = 0.0f;
	playerRotate = 0.0f;
	playerGunAngle = 0.0f;
	angle = 0.0f;

	collisionManager = new CollisionManager();
	bulletManager = new BulletManager(m_spritebatch, windowHeight, windowWidth, collisionManager);

	collisionManager->AddEntity(player1);
	collisionManager->AddEntity(tank[0]);
	collisionManager->AddEntity(tank[1]);
	collisionManager->AddEntity(tank[2]);
	collisionManager->AddEntity(tank[3]);
	collisionManager->AddEntity(tankTurret[0]);
	collisionManager->AddEntity(tankTurret[1]);
	collisionManager->AddEntity(tankTurret[2]);
	collisionManager->AddEntity(tankTurret[3]);

	aliveTanks = 4;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete player1;

	delete bulletManager;
	delete collisionManager;
	delete m_playerTexture;
	delete m_bulletTexture;
	//delete m_tankTexture;
	delete m_tankTurretTexture;
	for (int i = 0; i < 4; i++)
	{
		delete tank[i];
		delete tankTurret[i];
	}
}


void Game1::Update(float deltaTime)
{
	//Get && store mouse position
	GetInput()->GetMouseXY(xpos, ypos);
	mousePos.x = (float)*xpos;
	mousePos.y = (float)*ypos;
	angle = atan2(GetInput()->GetMouseY() - player1->m_position.y, GetInput()->GetMouseX() - player1->m_position.x);
	aliveTanks = 0;
	for (int i = 0; i < 4; i++)
		if (tank[i] != nullptr)
			aliveTanks++;

	//Player Movement
	if (GetInput()->IsKeyDown(GLFW_KEY_W) && GetInput()->IsKeyDown(GLFW_KEY_A) && player1->m_alive == true)
		player1->MoveNorthWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_W) && GetInput()->IsKeyDown(GLFW_KEY_D) && player1->m_alive == true)
		player1->MoveNorthEast(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S) && GetInput()->IsKeyDown(GLFW_KEY_A) && player1->m_alive == true)
		player1->MoveSouthWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S) && GetInput()->IsKeyDown(GLFW_KEY_D) && player1->m_alive == true)
		player1->MoveSouthEast(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_W) && player1->m_alive == true)
		player1->MoveNorth(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_A) && player1->m_alive == true)
		player1->MoveWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S) && player1->m_alive == true)
		player1->MoveSouth(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_D) && player1->m_alive == true)
		player1->MoveEast(deltaTime);
	//Player shoot
	if (GetInput()->IsMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT) && player1->m_alive == true)
	{
		if (player1->attackCooldown <= 0)
		{
			bulletManager->CreateBullet(player1->m_position, mousePos, angle, 1000, true, m_bulletTexture);
			player1->attackCooldown = 0.5;
		}
	}


	for (int i = 0; i < 4; i++)
	{
		//if tanks died
		if (tank[i] != nullptr && tank[i]->m_alive == false)
		{
			delete tank[i];
			tank[i] = nullptr;
		}
		if (tankTurret[i] != nullptr && tankTurret[i]->tank == nullptr)
		{
			delete tankTurret[i];
			tankTurret[i] = nullptr;
		}

		//if tanks are alive
		if (tank[i] != nullptr)
		{
			tank[i]->Update(deltaTime);
		}
		if (tank[i] != nullptr)
		{
			tankTurret[i]->Update(deltaTime / aliveTanks);
		}
	}

	player1->Update(deltaTime);
	bulletManager->UpdateBullets(deltaTime);

	collisionManager->UpdateCollisions();
	bulletManager->RemoveDead();
	std::cout << deltaTime << std::endl;

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();
	//Draw Player
	player1->Draw(m_spritebatch);
	//Cursor
	m_spritebatch->DrawSprite(m_playerTexture, mousePos.x, mousePos.y, m_playerTexture->GetWidth() / 4.0f, m_playerTexture->GetHeight() / 4.0f, angle + 90.0f);

	//Tanks && Turrets
	for (int i = 0; i < 4; i++)
	{
		if (tank[i] != nullptr)
			tank[i]->Draw(m_spritebatch);
		if (tank[i] != nullptr)
			tankTurret[i]->Draw(m_spritebatch);
	}
	

	//m_spritebatch->DrawSprite(m_bulletTexture, playerPos.x, playerPos.y, m_bulletTexture->GetWidth(), m_playerTexture->GetHeight());
	bulletManager->DrawBullets();

	// TODO: draw stuff.
	if (player1->m_alive == false)
	{
		m_spritebatch->DrawString(m_font, "YOU ARE DEAD!", 500.0f, 500.0f);
	}


	m_spritebatch->End();

}