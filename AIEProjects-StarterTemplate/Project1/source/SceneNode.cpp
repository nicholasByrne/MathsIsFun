#include "SceneNode.h"


SceneNode::SceneNode()
{
	m_parent = nullptr;
	for (int i = 0; i < 10; i++)
	{
		m_children[i] = nullptr;
	}
	m_globalTransform = Matrix3x3::Identity();
	m_localTransform = Matrix3x3::Identity();
}


SceneNode::~SceneNode()
{
	//delete children?
}


void SceneNode::SetParent(SceneNode * pNode)
{
	m_parent = pNode;
}


SceneNode * SceneNode::GetParent()
{
	return m_parent;
}


void SceneNode::AddChild(SceneNode * pNode)
{
	for (int i = 0; i < 10; i++)
	{
		if (m_children[i] == nullptr)
		{
			m_children[i] = pNode;
			pNode->m_parent = this;
			break;
		}
	}
}


SceneNode * SceneNode::GetChild(int index)
{
	if (index >= 10)
	{
		return nullptr;
	}
	else
		return m_children[index];
}


void SceneNode::RemoveChild(SceneNode * pNode)
{
	for (int i = 0; i < 10; i++)
	{
		if (m_children[i] == pNode)
		{
			pNode->SetParent(nullptr);
			m_children[i] = nullptr;
			break;
		}
	}
}


void SceneNode::UpdateTransforms()
{
	if (m_parent != nullptr)
	{
		m_globalTransform = m_localTransform * m_parent->m_globalTransform;
	}
	else
	{
		m_globalTransform = m_localTransform;
	}

	//for (int i = 0; i < m_children_size(); i++)
	for (int i = 0; i < 10; i++)
	{
		if (m_children[i] != nullptr)
		{
			m_children[i]->UpdateTransforms();
		}
	}
}


Matrix3x3 SceneNode::GetGlobalTransform() const
{
	return m_globalTransform;
}


Matrix3x3 SceneNode::GetLocalTransform() const
{
	return m_localTransform;
}


void SceneNode::SetLocalTransform(const Matrix3x3& a_transform)
{
	m_localTransform = a_transform;
}