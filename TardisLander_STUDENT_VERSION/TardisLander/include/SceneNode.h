#pragma once
#include "Matrix4x4.h"
class SceneNode
{
public:
	SceneNode();
	~SceneNode();

	void SetParent(SceneNode * parent);
	void AddChild(SceneNode * newChild);
	void RemoveChild(SceneNode * removeChild);
	void UpdateTransforms();

private:
	//list of children		//pointer to children?
	SceneNode * m_children[10];
	SceneNode * m_parent;
	//transform relative to parent
	Matrix4x4 m_local_transform;
	//transform relative to world origin
	//recalculated evrey frame
	Matrix4x4 m_global_transform;

};

