#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

enum KeyState {
	KEY_NO_STATE,
	KEY_PRESS_STATE,
	KEY_HELD_STATE,
	KEY_RELEASED_STATE
};

struct GameKey {
	int keyCode;
	KeyState state;
};

const int keyCount = 6;

class Keyboard
{
public:
	Keyboard(void);
	~Keyboard(void);

	void Update();
	KeyState GetKeyState(int keyCode);

private:	
	GameKey m_keyStates[keyCount];
};

#endif