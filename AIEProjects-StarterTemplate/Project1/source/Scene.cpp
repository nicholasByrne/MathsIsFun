#include "Scene.h"
#include "SceneNode.h"
#include "GameObject.h"

Scene::Scene()
{
	gameObjectArray = new GameObject * [20];
}


Scene::~Scene()
{
	delete m_rootNode;
}


void Scene::UpdateTransforms()
{
	m_rootNode->UpdateTransforms();
}


void Scene::Update(float deltaTime)
{
	m_rootNode->UpdateTransforms();
}


void Scene::AddGameObject(GameObject& a_gameObject)
{
	for (int i = 0; i < 20; i++)
	{
		if (gameObjectArray[i] == nullptr)
		{
			//add scenenode to hierarchy
			a_gameObject.SetParent(m_rootNode);
		}
	}
}


void Scene::SetRoot(SceneNode * pNode)
{
	m_rootNode = pNode;
}