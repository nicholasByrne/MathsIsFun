#pragma once
#include "Matrix3x3.h"

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
	Matrix3x3 m_localTransform;
	//transform relative to world origin
	//recalculated evrey frame
	Matrix3x3 m_globalTransform;

};

