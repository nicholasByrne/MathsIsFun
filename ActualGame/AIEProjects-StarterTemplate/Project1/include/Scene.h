#pragma once
//#include "SceneNode.h"

class SceneNode;
class SpriteBatch;
class GameObject;
class Input;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void UpdateTransforms();
	virtual void Update(float deltatime);
	virtual void Draw(SpriteBatch& a_spriteBatch) = 0;

	//adds a gameobject to this scene and returns a pointer to it
	void AddGameObject(GameObject & a_gameObject);

	void SetRoot(SceneNode * pNode);

protected:
	SceneNode * m_rootNode;
	GameObject ** gameObjectArray;

};

