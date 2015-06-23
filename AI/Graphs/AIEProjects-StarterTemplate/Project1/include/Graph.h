#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "SpriteBatch.h"
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();

	//node * a_nodeArray[10];

	std::vector<node*> a_nodeVector;
	std::vector<node*>::iterator iter = a_nodeVector.begin();

	void RemoveNode(node * toRemove);
	void AddNode(float x, float y);

	void DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius);
	
private:

};

#endif