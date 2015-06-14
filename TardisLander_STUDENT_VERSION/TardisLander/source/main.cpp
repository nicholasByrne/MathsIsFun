//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Player.h"
#include "Keyboard.h"
#include "GameDefs.h"

Keyboard g_keyboard;

int main( int argc, char* argv[] )
{	
    Initialise(1024, 768, false, "Test Game");

	Player* g_pPlayer;
	

	g_pPlayer = new Player();
	
	bool bPause = true;

    do 
    {
        //Game Logic goes here
		ClearScreen();

		float dt = GetDeltaTime();
		g_keyboard.Update();

		if(bPause) {
			DrawString("Press Enter to Start", iHalfScrW - 200, iHalfScrH);
			if(g_keyboard.GetKeyState(KEY_ENTER) == KEY_PRESS_STATE)
				bPause = false;

			continue;
		}

		if(g_keyboard.GetKeyState(KEY_SPACE) == KEY_PRESS_STATE)
			g_pPlayer->Reset();
				
		if(g_pPlayer->IsDead()) {
			DrawString("Game Over... You Suck", iHalfScrW - 200, iHalfScrH);
		} else if (g_pPlayer->HasLanded()) {
			DrawString("Winner!!!!!1", iHalfScrW - 200, iHalfScrH);
		} else {
			g_pPlayer->Update(dt);
		}

		g_pPlayer->Draw();

		DrawLine(0, iGroundY, iScreenWidth, iGroundY);
		

    } while ( FrameworkUpdate() == false );

    Shutdown();

    return 0;
}

