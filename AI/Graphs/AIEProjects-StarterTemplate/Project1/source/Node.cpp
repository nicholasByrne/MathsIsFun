#include "Node.h"
#include "SpriteBatch.h"

node::node()
{
	position.x = 0.0f;
	position.y = 0.0f;



	for (int i = 0; i < 10; i++)
	{
		nodeEdges[i] = nullptr;
	}
}


node::node(float a_x, float a_y)
{
	position.x = a_x;
	position.y = a_y;

	for (int i = 0; i < 10; i++)
	{
		nodeEdges[i] = nullptr;
	}
}


node::~node()
{
	delete[] nodeEdges;
}


void node::InsertEdge(node * end, int a_cost)
{
	for (int i = 0; i < 10; i++)
	{
		if (nodeEdges[i] == nullptr)
		{
			nodeEdges[i] = new Edge();
			nodeEdges[i]->startNode = this;
			nodeEdges[i]->endNode = end;
			nodeEdges[i]->cost = a_cost;
			return; 
		}
	}
}


void node::RemoveEdge(node * toRemove)
{
	for (int i = 0; i < 10; i++)
	{
		if (nodeEdges[i]->endNode == toRemove)
		{
			delete nodeEdges[i];
			nodeEdges[i] = nullptr;
		}
	}
}

void node::DrawEdge(SpriteBatch & a_spriteBatch, Edge * edge, float thickness)
{
	if (edge != nullptr)
		a_spriteBatch.DrawLine(edge->startNode->position.x, edge->startNode->position.y, edge->endNode->position.x, edge->endNode->position.y, 2.0f);
}


Vector2::Vector2()
{
	x = 0;
	y = 0;
}


Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}


Vector2::~Vector2()
{

}


Vector2::Vector2(Vector2 &other)
{
	x = other.x;
	y = other.y;
}
