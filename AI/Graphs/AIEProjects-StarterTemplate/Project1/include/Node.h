#ifndef NODE_H 
#define NODE_H
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

class node
{
public:
	node();
	node(float a_x, float a_y);
	~node();

	Vector2 position;
	Edge * nodeEdges[10];

	void InsertEdge(node * end, int a_cost);
	void RemoveEdge(node * toRemove);

	void DrawEdge(SpriteBatch & a_spriteBatch, Edge * edge, float thickness);


private:

};



#endif