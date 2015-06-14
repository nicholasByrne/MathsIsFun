#include "Keyboard.h"
#include "AIE.h"

Keyboard::Keyboard(void)
{
	m_keyStates[0].state = KEY_NO_STATE;
	m_keyStates[0].keyCode = KEY_UP;
	m_keyStates[1].state = KEY_NO_STATE;
	m_keyStates[1].keyCode = KEY_DOWN;
	m_keyStates[2].state = KEY_NO_STATE;
	m_keyStates[2].keyCode = KEY_LEFT;
	m_keyStates[3].state = KEY_NO_STATE;
	m_keyStates[3].keyCode = KEY_RIGHT;

	m_keyStates[4].state = KEY_NO_STATE;
	m_keyStates[4].keyCode = KEY_ENTER;
	m_keyStates[5].state = KEY_NO_STATE;
	m_keyStates[5].keyCode = KEY_SPACE;
}

Keyboard::~Keyboard(void)
{
}

void Keyboard::Update() {
	for(int i=0; i<keyCount; i++) {
		if(IsKeyDown(m_keyStates[i].keyCode) == true)  {
			// key being pressed
			if(m_keyStates[i].state == KEY_NO_STATE)
				m_keyStates[i].state = KEY_PRESS_STATE;
			else 
				m_keyStates[i].state = KEY_HELD_STATE;
		} else {
			// key not being pressed
			if(m_keyStates[i].state == KEY_PRESS_STATE ||
				m_keyStates[i].state == KEY_HELD_STATE)
				m_keyStates[i].state = KEY_RELEASED_STATE;
			else
				m_keyStates[i].state = KEY_NO_STATE;
		}		
	}
}

KeyState Keyboard::GetKeyState(int keyCode) {
	for(int i=0; i<keyCount; i++) { 
		if(m_keyStates[i].keyCode == keyCode)
			return m_keyStates[i].state;
	}
	return KEY_NO_STATE;
}
