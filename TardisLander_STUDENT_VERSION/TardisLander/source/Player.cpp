#include "AIE.h"
#include "Player.h"
#include "GameDefs.h"
#include "Keyboard.h"
//#include "Matrix3x3.h"

extern Keyboard g_keyboard;

const int iPlayerHalfH = 150/2;

Player::Player(void)
{
	m_sprite = CreateSprite("./images/ship.png", 81, 150, true);
	m_pFlame = new Sprite("./images/fire.png", 40, 67, true);
	AddChild(m_pFlame);
	m_pFlame->SetLocalTransform(
		Matrix3x3::CreateRotation(M_PI) *
		Matrix3x3::CreateTranslation(Vector3(0, 110, 1)));
	Reset();
}

Player::~Player(void)
{
	DestroySprite(m_sprite);
	DestroySprite(m_fireSprite);
	delete m_pFlame;
}

void Player::Reset() {
	Vector3 screenDimensions(iHalfScrW, iHalfScrH, 1); //added
	Matrix3x3 screenDimensionsMatrix = Matrix3x3::CreateTranslation(screenDimensions); //added
	m_localTransform = screenDimensionsMatrix.Mat4(); //m_localTransform = Matrix3x3::CreateTranslation(iHalfScrW, iHalfScrH);
	m_velocity.x = 0;
	m_velocity.y = 1;
	m_bIsDead = false;
	m_bHasLanded = false;
	m_bFlameOn = false;
}

void Player::Update(float dt) {
	if (m_bHasLanded)
		return;
	m_velocity.y += 0.05; //drop ship due to gravity
	//turn ship left or right
	float rotation = 0;
	if (g_keyboard.GetKeyState(KEY_LEFT) == KEY_HELD_STATE)
		rotation += 0.1;
	if (g_keyboard.GetKeyState(KEY_RIGHT) == KEY_HELD_STATE)
		rotation -= 0.1;
	//calculate thrust according to current rotation
	if (g_keyboard.GetKeyState(KEY_UP) == KEY_HELD_STATE) {
		m_bFlameOn = true;
		m_velocity.y -= 0.1;
	}
	else {
		m_bFlameOn = false;
	}
	//modify player position based on rotation
	Matrix3x3 mR = Matrix3x3::CreateRotation(rotation * (M_PI / 180));
	Matrix3x3 mT = Matrix3x3::CreateTranslation(m_velocity.x*dt, m_velocity.y*dt);
	m_localTransform = mR * mT * m_localTransform;
	// check if crashed into the ground
	if (m_localTransform.data[2][2] + iPlayerHalfH > iGroundY) {
		float speed = m_velocity.Magnitude() * dt;
		if (speed > 0.05) {
			// CRASH!!!!1
			m_bIsDead = true;
		}
		m_velocity.x = 0;
		m_velocity.y = 0;
		m_bHasLanded = true;
	}
}

void Player::Draw() {
	SetSpriteMatrix(m_sprite, (float*)m_globalTransform.Mat4().m);
	DrawSprite(m_sprite);
	//set up position and rotation of thruster flame so we can draw it
	if (m_bFlameOn) {
		m_pFlame->Draw();
	}
}
