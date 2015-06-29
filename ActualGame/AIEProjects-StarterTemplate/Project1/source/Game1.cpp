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

	player1 = new Player(m_playerTexture);
	tank1 = new Tank(74.0f, 74.0f, 50.0f, m_playerTexture, windowWidth, windowHeight, 3); //NW
	tank2 = new Tank(windowWidth - 76.0f, 74.0f, 50.0f, m_playerTexture, windowWidth, windowHeight, 4); //NE
	tank3 = new Tank(windowWidth - 76.0f, windowHeight - 76.0f, 50.0f, m_playerTexture, windowWidth, windowHeight, 1); //SE
	tank4 = new Tank(74.0f, windowHeight - 76.0f, 50.0f, m_playerTexture, windowWidth, windowHeight, 2); //SW
	tank1Turret = new TankTurret(tank1, player1, m_tankTurretTexture);
	tank2Turret = new TankTurret(tank2, player1, m_tankTurretTexture);
	tank3Turret = new TankTurret(tank3, player1, m_tankTurretTexture);
	tank4Turret = new TankTurret(tank4, player1, m_tankTurretTexture);
	
	mousePos.x = 0.0f;
	mousePos.y = 0.0f;
	playerRotate = 0.0f;
	playerGunAngle = 0.0f;
	angle = 0.0f;
	bulletManager = new BulletManager(m_spritebatch, windowHeight, windowWidth);

	collisionManager = CollisionManager();
	collisionManager.AddEntity(*player1);
	collisionManager.AddEntity(*tank1);
	collisionManager.AddEntity(*tank2);
	collisionManager.AddEntity(*tank3);
	collisionManager.AddEntity(*tank4);
	collisionManager.AddEntity(*tank1Turret);
	collisionManager.AddEntity(*tank2Turret);
	collisionManager.AddEntity(*tank3Turret);
	collisionManager.AddEntity(*tank4Turret);

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete player1;

	delete bulletManager;
	delete m_playerTexture;
	delete m_bulletTexture;
	//delete m_tankTexture;
	delete m_tankTurretTexture;
}


void Game1::Update(float deltaTime)
{
	//Get && store mouse position
	GetInput()->GetMouseXY(xpos, ypos);
	mousePos.x = *xpos;
	mousePos.y = *ypos;
	
	angle = atan2(GetInput()->GetMouseY() - player1->m_position.y, GetInput()->GetMouseX() - player1->m_position.x);

	if (GetInput()->IsKeyDown(GLFW_KEY_W) && GetInput()->IsKeyDown(GLFW_KEY_A))
		player1->MoveNorthWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_W) && GetInput()->IsKeyDown(GLFW_KEY_D))
		player1->MoveNorthEast(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S) && GetInput()->IsKeyDown(GLFW_KEY_A))
		player1->MoveSouthWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S) && GetInput()->IsKeyDown(GLFW_KEY_D))
		player1->MoveSouthEast(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_W))
		player1->MoveNorth(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_A))
		player1->MoveWest(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_S))
		player1->MoveSouth(deltaTime);
	else if (GetInput()->IsKeyDown(GLFW_KEY_D))
		player1->MoveEast(deltaTime);
	





	if (GetInput()->IsMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (player1->attackCooldown <= 0)
		{
			bulletManager->CreateBullet(player1->m_position, mousePos, angle, 1000, m_bulletTexture);
			player1->attackCooldown = 0.5;
		}
	}
	player1->Update(deltaTime);
	tank1->Update(deltaTime);
	tank2->Update(deltaTime);
	tank3->Update(deltaTime);
	tank4->Update(deltaTime);
	tank1Turret->Update(deltaTime);
	tank2Turret->Update(deltaTime);
	tank3Turret->Update(deltaTime);
	tank4Turret->Update(deltaTime);
	bulletManager->UpdateBullets(deltaTime);
	std::cout << deltaTime << std::endl;
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	//Draw Player
	player1->Draw(m_spritebatch);
	//m_spritebatch->DrawSprite(m_playerTexture, playerPos.x, playerPos.y, m_playerTexture->GetWidth(), m_playerTexture->GetHeight());
	//m_spritebatch->DrawSprite(m_playerTexture, playerX, playerY, m_playerTexture->GetWidth(), m_playerTexture->GetHeight(), angle+90, m_playerTexture->GetHeight()/2, m_playerTexture->GetHeight()/2);

	m_spritebatch->DrawSprite(m_playerTexture, mousePos.x, mousePos.y, m_playerTexture->GetWidth() / 4, m_playerTexture->GetHeight() / 4, angle + 90);
	tank1->Draw(m_spritebatch);
	tank2->Draw(m_spritebatch);
	tank3->Draw(m_spritebatch);
	tank4->Draw(m_spritebatch);

	tank1Turret->Draw(m_spritebatch);
	tank2Turret->Draw(m_spritebatch);
	tank3Turret->Draw(m_spritebatch);
	tank4Turret->Draw(m_spritebatch);




	//m_spritebatch->DrawSprite(m_bulletTexture, playerPos.x, playerPos.y, m_bulletTexture->GetWidth(), m_playerTexture->GetHeight());
	bulletManager->DrawBullets();

	// TODO: draw stuff.

	m_spritebatch->End();

}