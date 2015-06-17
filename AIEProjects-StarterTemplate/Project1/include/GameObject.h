#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "SceneNode.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Kill();
	virtual void Update(float deltaTime);

	Vector2 position; //Use SceneNode Matrix instead?
	Vector2 velocity; //Use SceneNode Matrix instead?
	
	SceneNode sceneNode;

	Texture * texture;

protected:

};

