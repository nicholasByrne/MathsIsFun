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

	std::vector<Node*> a_nodeVector;
	std::vector<Node*>::iterator iter;

	void RemoveNode(Node * toRemove);
	void AddNode(float x, float y);

	void DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius);
	void DrawCircleAll(SpriteBatch& a_spriteBatch, float radius);
	void DrawEdgeAll(SpriteBatch & a_spriteBatch, float thickness);


private:

};

#endif