#include "Edge.h"
#include "SpriteBatch.h"
#include "Node.h"

Edge::Edge()
{
	startNode = nullptr;
	endNode = nullptr;
	cost = 0;
}


Edge::Edge(Node * start, Node * end, int a_cost)
{
	startNode = start;
	endNode = end;
	cost = a_cost;
}


Edge::~Edge()
{

}


