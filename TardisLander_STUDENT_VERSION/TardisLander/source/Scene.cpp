#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}


void Scene::UpdateTransforms()
{
	m_scene_root->UpdateTransforms();
}


void Scene::SetRoot(SceneNode * pNode)
{
	m_scene_root = pNode;
}