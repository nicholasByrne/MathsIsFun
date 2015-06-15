#pragma once
#include "SceneNode.h"
class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();
	void SetRoot(SceneNode * pNode);

private:
	SceneNode * m_scene_root;

};

