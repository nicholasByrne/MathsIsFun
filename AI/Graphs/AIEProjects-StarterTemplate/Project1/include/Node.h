#ifndef NODE_H 
#define NODE_H
#include <vector>
#include "Edge.h"


class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);
	Vector2(Vector2 &other);
	~Vector2();

	float x;
	float y;

private:

};


class Node
{
public:
	Node();
	Node(float a_x, float a_y);
	~Node();

	Vector2 position;
	std::vector<Edge*> nodeEdges;
	std::vector<Edge*>::iterator iter;

	void InsertEdge(Node * end, int a_cost);
	void RemoveEdge(Node * toRemove);

	void DrawEdge(SpriteBatch & a_spriteBatch, Edge * edge, float thickness);
	void DrawEdgeAll(SpriteBatch & a_spriteBatch, float thickness);


private:

};



#endif