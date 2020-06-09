//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/ProjectOutliner.hpp"

#include <QBoxLayout>
#include <QStringList>
#include <QTreeWidget>

ProjectOutliner::ProjectOutliner(EditorContainer* container) : EditorBase(container, 0)
{
    QHBoxLayout* layout = new QHBoxLayout;

    m_tree = new QTreeWidget;
    m_tree->setColumnCount(1);
    m_tree->setHeaderHidden(true);

    m_project = new QTreeWidgetItem(m_tree);
    m_project->setExpanded(true);
    m_project->setText(0, "Untitled");

    QTreeWidgetItem* item = new QTreeWidgetItem;
    item->setText(0, "Course Data");
    m_project->addChild(item);

    QTreeWidgetItem* item2 = new QTreeWidgetItem;
    item2->setText(0, "Course Information");
    item->addChild(item2);

    layout->addWidget(m_tree);

    setContents(layout);
}

ProjectOutliner::~ProjectOutliner() = default;

EditorBase* ProjectOutliner::duplicate()
{
    return new ProjectOutliner(m_container);
}
