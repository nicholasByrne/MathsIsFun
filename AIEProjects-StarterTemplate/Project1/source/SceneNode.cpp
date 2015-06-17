#include "SceneNode.h"


SceneNode::SceneNode()
{
	for (int i = 0; i < 10; i++)
	{
		m_children[i] = nullptr;
	}
}


SceneNode::~SceneNode()
{
	//delete children?
}


void SceneNode::SetParent(SceneNode * pNode)
{
	m_parent = pNode;
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