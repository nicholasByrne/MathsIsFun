#pragma once
#include "Vector2.h"
#include "Texture.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Kill();
	virtual void Update(float deltaTime);

	Vector2 position;
	Vector2 velocity;

	Texture * texture;

protected:

};

