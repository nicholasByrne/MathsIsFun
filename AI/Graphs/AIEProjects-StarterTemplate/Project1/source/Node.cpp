#include "Node.h"
#include "SpriteBatch.h"

Node::Node()
{
	position.x = 0.0f;
	position.y = 0.0f;
	nodeEdges.reserve(10);
	iter = nodeEdges.begin();
}


Node::Node(float a_x, float a_y)
{
	position.x = a_x;
	position.y = a_y;		
	nodeEdges.reserve(10);
	iter = nodeEdges.begin();
}


Node::~Node()
{
	//delete[] nodeEdges;
}


void Node::InsertEdge(Node * end, int a_cost)
{
	//for (; iter < nodeEdges.end(); iter++)
	//{
	//	if (*iter == nullptr)
	//	{
	//		*iter = new Edge();
	//		(*iter)->startNode = this;
	//		(*iter)->endNode = end;
	//		(*iter)->cost = a_cost;
	//		return; 
	//	}
	//}
	
	nodeEdges.push_back(new Edge(this, end, a_cost));
}


void Node::RemoveEdge(Node * toRemove)
{
	for (iter = nodeEdges.begin(); iter != nodeEdges.end(); iter++)
	{
		if ((*iter)->endNode == toRemove)
		{
			delete *iter;
			*iter = nullptr;
		}
	}
}

void Node::DrawEdge(SpriteBatch & a_spriteBatch, Edge * edge, float thickness)
{
	if (edge != nullptr)
		a_spriteBatch.DrawLine(edge->startNode->position.x, edge->startNode->position.y, edge->endNode->position.x, edge->endNode->position.y, 2.0f);
}


void Node::DrawEdgeAll(SpriteBatch & a_spriteBatch, float thickness)
{
	for (iter = nodeEdges.begin(); iter != nodeEdges.end(); iter++)
	{
		DrawEdge(a_spriteBatch, *iter, thickness);
	}
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
