#ifndef EDGE_H 
#define EDGE_H

class Vector2;
class node;
class SpriteBatch;

class Edge
{
public:
	Edge();
	~Edge();

	node * startNode;
	node * endNode;
	int cost;

	
};

#endif