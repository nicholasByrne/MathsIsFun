#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	myGraph =  new Graph();
	myGraph->AddNode(35, 420);
	myGraph->AddNode(500, 560);
	myGraph->AddNode(250, 40);
	myGraph->AddNode(100, 350);

	myGraph->a_nodeArray[0]->InsertEdge(myGraph->a_nodeArray[1], 10);
	myGraph->a_nodeArray[1]->InsertEdge(myGraph->a_nodeArray[2], 10);

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.
	
	for (int i = 0; i < 10; i++)
	{
		if (myGraph->a_nodeArray[i] != nullptr)
			myGraph->DrawCircle(*m_spritebatch, myGraph->a_nodeArray[i]->position, 10.0f);
	}

	for (int i = 0; i < 10; i++)
	{
		if (myGraph->a_nodeArray[i] != nullptr)
		{
			for (int j = 0; j < 10; j++)
			{
				myGraph->a_nodeArray[i]->DrawEdge(*m_spritebatch, myGraph->a_nodeArray[i]->nodeEdges[j], 10);
			}
		}
	}

	m_spritebatch->End();

}