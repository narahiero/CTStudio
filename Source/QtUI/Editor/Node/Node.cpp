//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/Node/Node.hpp"

#include "Core/Core.hpp"
#include "Core/ProjectManager.hpp"

QString nameOf(NodeType type)
{
    switch (type)
    {
    case NodeType::Project:
        return QStringLiteral("Project");

    case NodeType::Folder:
        return QStringLiteral("Folder");

    case NodeType::Object:
        return QStringLiteral("Object");

    default:
        return QStringLiteral("???");
    }
}

AbstractNode::AbstractNode(QObject* parent) : QObject(parent)
{

}

AbstractNode::~AbstractNode() = default;

void AbstractNode::setName(const QString& name)
{
    m_name = name;
    emit nameChanged(name);
}

QString AbstractNode::getName() const
{
    return m_name;
}

ProjectNode::ProjectNode(QObject* parent) : AbstractNode(parent)
{

}

ProjectNode::~ProjectNode() = default;

NodeType ProjectNode::getType() const
{
    return NodeType::Project;
}

void ProjectNode::setName(const QString& name)
{
    AbstractNode::setName(name);
    Core::getProjectManager().renameProject(name.toStdString());
}

QList<FolderNode*> ProjectNode::getFolders() const
{
    return m_folders;
}

FolderNode::FolderNode(QObject* parent) : AbstractNode(parent)
{

}

FolderNode::~FolderNode() = default;

NodeType FolderNode::getType() const
{
    return NodeType::Folder;
}

QList<ObjectNode*> FolderNode::getObjects() const
{
    return m_objects;
}

ObjectNode::ObjectNode(QObject* parent) : AbstractNode(parent)
{

}

ObjectNode::~ObjectNode() = default;

NodeType ObjectNode::getType() const
{
    return NodeType::Object;
}
