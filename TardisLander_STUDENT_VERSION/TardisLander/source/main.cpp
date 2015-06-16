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

#include "Matrix3x3.h"
#include "Vector3.h"
void PrintMatrix(Matrix3x3 toPrint)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << i << j << ": " << toPrint.data[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "------------------" << std::endl;
}

void PrintVector(Vector3 toPrint)
{
	std::cout << "x: " << toPrint.x << " y: " << toPrint.y << " z: " << toPrint.z << std::endl;
	std::cout << "------------------" << std::endl;
}

void Test() //matrix
{
	Matrix3x3 test(1, 2, 3, 4, 5, 5, 5, 10, 11);
	PrintMatrix(test);
	//std::cout << test(1, 1) << std::endl;
	Matrix3x3 addition(0, 1, 2, 3, 4, 5, 6, 7, 8);
	Vector3 vector(10, 20, 30);
	Vector3 testVector;
	//test = test + addition;
	//test = addition;
	//test += addition;
	//test = test - addition;
	//test -= addition;
	// test *= addition; //ERROR
	//testVector = test * vector;
	//test.Transpose();
	//addition = test.GetTranspose();

	//PrintVector(testVector);
	//PrintMatrix(addition);
	PrintMatrix(test);
}


void Test2()//vector
{
	Vector3 test(3, 1, 2);
	Vector3 addition(2, 2, 1);
	Vector3 subtraction(4, 2, 5);
	//test = test + addition;
	//test += addition;
	//bool bol = test == addition;
	//std::cout << bol << std::endl;
	//test = test - addition;
	//test -= addition;
	//test = test * 2;
	//test *= 2;;
	//float floaty = test.Magnitude();
	//std::cout << floaty << std::endl;
		// Normalise, normalisethis, dot, cross
	//test.NormaliseThis();
	test = Vector3::Cross(addition, subtraction);
	PrintVector(test);
}

Keyboard g_keyboard;

int main( int argc, char* argv[] )
{	
	//Test();
	Test2();

	int stopper;
	std::cin >> stopper; // Stop before loading rest 
	
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

