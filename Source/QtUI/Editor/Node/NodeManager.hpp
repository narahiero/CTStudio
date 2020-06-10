//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include "QtUI/Editor/Node/Node.hpp"

class NodeManager final : public QObject
{
    Q_OBJECT

public:

    explicit NodeManager(QObject* parent = nullptr);
    ~NodeManager();

    void setSelectedNode(AbstractNode* node);
    AbstractNode* getSelectedNode() const;

    ProjectNode* getProjectNode() const;

signals:

    void nodesUpdated();
    void nodeSelected(AbstractNode* node);

private:

    void projectStateChanged();

    AbstractNode* m_selected;

    ProjectNode* m_project;
};
