//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include "QtUI/Editor/EditorBase.hpp"

class QTreeWidget;
class QTreeWidgetItem;

class ProjectOutliner final : public EditorBase
{
    Q_OBJECT

public:

    explicit ProjectOutliner(EditorContainer* container);
    ~ProjectOutliner();

    EditorBase* duplicate() override;

private:

    QTreeWidget* m_tree;
    QTreeWidgetItem* m_project;
};
