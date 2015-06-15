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
		m_global_transform = m_local_transform * m_parent->m_global_transform;
	}
	else
	{
		m_global_transform = m_local_transform;
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