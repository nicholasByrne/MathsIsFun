#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "SpriteBatch.h"

class Graph
{
public:
	Graph();
	~Graph();

	node * a_nodeArray[10];

	void RemoveNode(node * toRemove);
	void AddNode(float x, float y);

	void DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius);
	
private:

};

#endif