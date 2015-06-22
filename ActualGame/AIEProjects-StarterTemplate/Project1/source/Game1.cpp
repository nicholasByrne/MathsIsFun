#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>


Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	m_playerTexture = new Texture("./Images/box0_256.png");
	m_bulletTexture = new Texture("./Images/crate.png");
	player1 = new Player(m_playerTexture);

	
	mousePos.x = 0.0f;
	mousePos.y = 0.0f;
	playerRotate = 0.0f;
	playerGunAngle = 0.0f;
	angle = 0.0f;
	bulletManager = new BulletManager(m_spritebatch, windowHeight, windowWidth);
	collisionManager;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete player1;

	delete bulletManager;
	delete m_playerTexture;
	delete m_bulletTexture;
}


void Game1::Update(float deltaTime)
{
	
	//movement of player
	GetInput()->GetMouseXY(xpos, ypos);
	mousePos.x = *xpos;
	mousePos.y = *ypos;
	
	angle = atan2(GetInput()->GetMouseY() - player1->m_position.y, GetInput()->GetMouseX() - player1->m_position.x);
	if (GetInput()->IsKeyDown(GLFW_KEY_W))
	{
		player1->MoveNorth(deltaTime);
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_A))
	{
		player1->MoveWest(deltaTime);
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_S))
	{
		player1->MoveSouth(deltaTime);
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_D))
	{
		player1->MoveEast(deltaTime);
	}
	//
	if (GetInput()->IsKeyDown(GLFW_KEY_E))
	{
		player1->m_rotation += (10 * deltaTime);
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_Q))
	{
		//playerRotate -= 10 * deltaTime;
		player1->m_rotation -= (10 * deltaTime);
	}

	if (GetInput()->IsMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (player1->attackCooldown <= 0)
		{
			bulletManager->CreateBullet(player1->m_position, mousePos, angle, 1000, m_bulletTexture);
			player1->attackCooldown = 0.5;
		}
	}
	player1->Update(deltaTime);
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


	//m_spritebatch->DrawSprite(m_bulletTexture, playerPos.x, playerPos.y, m_bulletTexture->GetWidth(), m_playerTexture->GetHeight());
	bulletManager->DrawBullets();

	// TODO: draw stuff.

	m_spritebatch->End();

}