//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QObject>

enum class NodeType
{
    Project,
    Folder,
    Object
};

QString nameOf(NodeType type);

class AbstractNode : public QObject
{
    Q_OBJECT

public:

    explicit AbstractNode(QObject* parent = nullptr);
    ~AbstractNode();

    virtual NodeType getType() const = 0;

    virtual void setName(const QString& name);
    QString getName() const;

signals:

    void nameChanged(const QString& name);

private:

    QString m_name;
};

class ProjectNode;
class FolderNode;
class ObjectNode;

class ProjectNode final : public AbstractNode
{

public:

    explicit ProjectNode(QObject* parent = nullptr);
    ~ProjectNode();

    NodeType getType() const override;

    void setName(const QString& name) override;

    QList<FolderNode*> getFolders() const;

private:

    QList<FolderNode*> m_folders;
};

class FolderNode final : public AbstractNode
{

public:

    explicit FolderNode(QObject* parent = nullptr);
    ~FolderNode();

    NodeType getType() const override;

    QList<ObjectNode*> getObjects() const;

private:

    QList<ObjectNode*> m_objects;
};

class ObjectNode final : public AbstractNode
{

public:

    explicit ObjectNode(QObject* parent = nullptr);
    ~ObjectNode();

    NodeType getType() const override;
};
