#include "AIE.h"
#include "Player.h"
#include "GameDefs.h"
#include "Keyboard.h"
#include "Matrix3x3.h"

extern Keyboard g_keyboard;

const int iPlayerHalfH = 150/2;

Player::Player(void)
{
	m_sprite = CreateSprite("./images/ship.png", 81, 150, true);
	m_fireSprite = CreateSprite("./images/fire.png", 40, 67, true);
	Reset();
}

Player::~Player(void)
{
	DestroySprite(m_sprite);
	DestroySprite(m_fireSprite);
}

void Player::Reset() {
	m_position.x = iHalfScrW;
	m_position.y = iHalfScrH;
	m_velocity.x = 0;
	m_velocity.y = 1;
	m_rotation = 0.0;
	m_bIsDead = false;
	m_bHasLanded = false;
	m_bFlameOn = false;
}

void Player::Update(float dt) {
	if(m_bHasLanded)
		return;

	//drop ship due to gravity
	m_velocity.y += 0.05;
	
	//turn ship left or right
	if(g_keyboard.GetKeyState(KEY_LEFT) == KEY_HELD_STATE)
		m_rotation += 0.1;
	if(g_keyboard.GetKeyState(KEY_RIGHT) == KEY_HELD_STATE)
		m_rotation -= 0.1;

	 //calculate thrust according to current rotation
	if(g_keyboard.GetKeyState(KEY_UP) == KEY_HELD_STATE) {
		m_bFlameOn = true;
		m_velocity.y -= 0.1; 
	}
	else {
		m_bFlameOn = false;
	}

	//modify player position based on rotation
	Matrix3x3 m = Matrix3x3::CreateRotation(m_rotation * (M_PI / 180));

	Vector3 v = m * m_velocity;
	m_position += v*dt;
	

	// check if crashed into the ground	
	if(m_position.y + iPlayerHalfH > iGroundY) {
		float speed = m_velocity.Magnitude() * dt;		//float speed = m_velocity.Length() * dt;		
		if(speed > 0.05) {
			// CRASH!!!!1
			m_bIsDead = true;
		}
		m_velocity.x = 0;
		m_velocity.y = 0;
		m_bHasLanded = true;
	}
}

void Player::Draw() {
	RotateSprite(m_sprite, m_rotation);
	MoveSprite(m_sprite, m_position.x, m_position.y);
	DrawSprite(m_sprite);

	//set up position and rotation of thruster flame so we can draw it
	if(m_bFlameOn) {
		
		Matrix3x3 transpose = Matrix3x3::CreateTranslation(Vector3(m_position.x, m_position.y, 0));

		Matrix3x3 rotation = Matrix3x3::CreateRotation(m_rotation * (M_PI / 180));

		Matrix3x3 translation = rotation * transpose;

		//origin can be thought of as displacement from ship
		Vector3 origin(0, 110, 1);
		Vector3 v = translation * origin;

		RotateSprite(m_fireSprite, m_rotation + 180);
		MoveSprite(m_fireSprite, v.x, v.y);
		DrawSprite(m_fireSprite);
	}
}
