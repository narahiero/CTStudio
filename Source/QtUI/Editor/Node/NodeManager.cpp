//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/Node/NodeManager.hpp"

#include "Core/Core.hpp"
#include "Core/ProjectManager.hpp"

#include "QtUI/CoreCallbacks.hpp"

NodeManager::NodeManager(QObject* parent) : QObject(parent),
    m_selected{nullptr},
    m_project{nullptr}
{
    connect(CoreCallbacks::getInstance(), &CoreCallbacks::projectStateChanged,
        this, &NodeManager::projectStateChanged);
}

NodeManager::~NodeManager() = default;

void NodeManager::setSelectedNode(AbstractNode* node)
{
    m_selected = node;
    emit nodeSelected(node);
}

AbstractNode* NodeManager::getSelectedNode() const
{
    return m_selected;
}

ProjectNode* NodeManager::getProjectNode() const
{
    return m_project;
}

void NodeManager::projectStateChanged()
{
    ProjectManager& manager = Core::getProjectManager();

    if (manager.hasActiveProject())
    {
        if (!m_project)
        {
            m_project = new ProjectNode(this);

            emit nodesUpdated();
        }
    }
    else
    {
        if (m_project)
        {
            m_project->deleteLater();
            m_project = nullptr;

            emit nodesUpdated();
        }
    }
}
