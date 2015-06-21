#pragma once
#include "Matrix3x3.h"

class SceneNode
{
public:
	SceneNode();
	~SceneNode();


	void SetParent(SceneNode * parent);
	SceneNode * GetParent();

	void AddChild(SceneNode * newChild);
	SceneNode * GetChild(int index);
	void RemoveChild(SceneNode * removeChild);

	void UpdateTransforms();

	Matrix3x3 GetGlobalTransform() const;
	Matrix3x3 GetLocalTransform() const;

	void SetLocalTransform(const Matrix3x3& a_transform);

protected:
	//list of children		//pointer to children?
	SceneNode * m_children[10];
	SceneNode * m_parent;

	//transform relative to parent
	Matrix3x3 m_localTransform;

	//transform relative to world origin
	//recalculated evrey frame
	Matrix3x3 m_globalTransform;


};

