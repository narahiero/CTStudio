//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/ProjectOutliner.hpp"

#include <QBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QTreeWidget>

#include "QtUI/Editor/EditorContainer.hpp"
#include "QtUI/Editor/Node/NodeManager.hpp"
#include "QtUI/Editor/SharedEditorState.hpp"

ProjectOutliner::ProjectOutliner(EditorContainer* container) : EditorBase(container, 0)
{
    createNoProjectLabel();
    createTree();

    m_layout = new QHBoxLayout;
    setContents(m_layout);

    m_layout->addWidget(m_noProject);

    connectAll();
}

ProjectOutliner::~ProjectOutliner() = default;

EditorBase* ProjectOutliner::duplicate()
{
    return new ProjectOutliner(m_container);
}

void ProjectOutliner::createNoProjectLabel()
{
    m_noProject = new QLabel(
        QStringLiteral("<center>%1</center>").arg(tr("No active project to show outline from..."))
    );
    m_noProject->setWordWrap(true);
    m_noProject->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ProjectOutliner::createTree()
{
    m_tree = new QTreeWidget;
    m_tree->setColumnCount(1);
    m_tree->setHeaderHidden(true);
}

void ProjectOutliner::connectAll()
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();

    connect(manager, &NodeManager::nodesUpdated, this, &ProjectOutliner::onNodesUpdate);
    connect(m_tree, &QTreeWidget::currentItemChanged, this, &ProjectOutliner::nodeSelected);
}

void ProjectOutliner::onNodesUpdate()
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();

    ProjectNode* project = manager->getProjectNode();
    if (project)
    {
        if (!m_treeSet)
        {
            m_layout->removeWidget(m_noProject);
            m_layout->addWidget(m_tree);
        }
    }
    else
    {
        if (m_treeSet)
        {
            m_layout->removeWidget(m_tree);
            m_layout->addWidget(m_noProject);
        }
    }
}

void ProjectOutliner::nodeSelected(QTreeWidgetItem* curr, QTreeWidgetItem* old)
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();
    manager->setSelectedNode(((OutlinerNode*)curr)->m_node);
}

OutlinerNode::OutlinerNode(AbstractNode* node, QTreeWidget* parent) :
    QObject(),
    QTreeWidgetItem(parent),
    m_node{node}
{
    setText(0, node->getName());

    createChilds();

    connect(node, &AbstractNode::nameChanged, this, &OutlinerNode::onNodeRenamed);
}

OutlinerNode::OutlinerNode(AbstractNode* node, OutlinerNode* parent) :
    QObject(parent),
    QTreeWidgetItem(),
    m_node{node}
{
    setText(0, node->getName());

    createChilds();

    connect(node, &AbstractNode::nameChanged, this, &OutlinerNode::onNodeRenamed);
}

OutlinerNode::~OutlinerNode() = default;

void OutlinerNode::createChilds()
{
    if (m_node->getType() == NodeType::Project)
    {
        for (FolderNode* folder : ((ProjectNode*)m_node)->getFolders())
        {
            OutlinerNode* folderNode = new OutlinerNode(folder);
            addChild(folderNode);
        }
    }
    else if (m_node->getType() == NodeType::Folder)
    {
        for (ObjectNode* object : ((FolderNode*)m_node)->getObjects())
        {
            OutlinerNode* objectNode = new OutlinerNode(object);
            addChild(objectNode);
        }
    }
}

void OutlinerNode::onNodeRenamed(const QString& name)
{
    setText(0, name);
}
