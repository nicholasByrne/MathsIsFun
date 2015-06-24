#include "Graph.h"
#include <math.h>
Graph::Graph()
{
	a_nodeVector.reserve(10);
	iter = a_nodeVector.begin();
}

Graph::~Graph()
{
	//delete[] a_nodeArray;
}


void Graph::RemoveNode(Node * toRemove)
{
	for (iter = a_nodeVector.begin(); iter != a_nodeVector.end(); iter++)
	{
		(*iter)->RemoveEdge(toRemove);	
	}

	delete toRemove;
	toRemove = nullptr;
}


void Graph::AddNode(float x, float y)
{
	a_nodeVector.push_back(new Node(x, y));
	//for (; iter < a_nodeVector.end(); iter++)
	//{
	//	if (*iter == nullptr)
	//	{
	//		*iter = new node(x, y);
	//		return;
	//	}
	//}
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


void Graph::DrawCircleAll(SpriteBatch& a_spriteBatch, float radius)
{
	for (iter = a_nodeVector.begin(); iter != a_nodeVector.end(); iter++)
	{
		if (*iter != nullptr)
			DrawCircle(a_spriteBatch, (*iter)->position, radius);
	}
}


void Graph::DrawEdgeAll(SpriteBatch & a_spriteBatch, float thickness)
{
	for (iter = a_nodeVector.begin(); iter != a_nodeVector.end(); iter++)
	{
		if (*iter != nullptr)
			(*iter)->DrawEdgeAll(a_spriteBatch, thickness);
	}
}


