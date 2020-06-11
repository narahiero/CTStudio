//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include "QtUI/Editor/EditorBase.hpp"

#include <QTreeWidget>

class QHBoxLayout;
class QLabel;

class AbstractNode;
class OutlinerNode;

class ProjectOutliner final : public EditorBase
{
    Q_OBJECT

public:

    explicit ProjectOutliner(EditorContainer* container);
    ~ProjectOutliner();

    EditorBase* duplicate() override;

private:

    void createNoProjectLabel();
    void createTree();
    void initFromNodeManager();
    void connectAll();

    void onNodesUpdate();

    void nodeSelected(QTreeWidgetItem* curr, QTreeWidgetItem* old);

    QHBoxLayout* m_layout;
    bool m_treeSet;

    QLabel* m_noProject;

    QTreeWidget* m_tree;
    OutlinerNode* m_project;
};

class OutlinerNode final : public QObject, public QTreeWidgetItem
{

    friend class ProjectOutliner;

public:

    explicit OutlinerNode(AbstractNode* node, QTreeWidget* parent = nullptr);
    explicit OutlinerNode(AbstractNode* node, OutlinerNode* parent);
    ~OutlinerNode();

private:

    void createChilds();

    void onNodeRenamed(const QString& name);

    AbstractNode* m_node;
};
