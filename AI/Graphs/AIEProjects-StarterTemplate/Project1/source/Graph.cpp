#include "Graph.h"
#include <math.h>
Graph::Graph()
{
	for (int i = 0; i < 10; i++)
	{
		a_nodeVector[i] = nullptr;
	}
}

Graph::~Graph()
{
	//delete[] a_nodeArray;
}


void Graph::RemoveNode(node * toRemove)
{
	for (; iter < a_nodeVector.end(); iter++)
	{
		a_nodeVector[iter]->RemoveEdge(toRemove);
	}

	delete toRemove;
	toRemove = nullptr;
}


void Graph::AddNode(float x, float y)
{
	for (; iter < a_nodeVector.end(); iter++)
	{
		if (a_nodeArray[i] == nullptr)
		{
			a_nodeArray[i] = new node(x, y);
			return;
		}
	}
}


void Graph::DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius)
{
	Vector2 oldPos = Vector2(pos.x + (cos(0.0f) * radius), pos.y + (sin(0.0f) * radius));

	for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
	{
		Vector2 newPos;

		newPos.x = pos.x + (cos(i) * radius);
		newPos.y = pos.y + (sin(i) * radius);

		a_spriteBatch.DrawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

		oldPos = newPos;
	}
}