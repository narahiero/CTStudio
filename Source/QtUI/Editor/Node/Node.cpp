//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/Node/Node.hpp"

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
