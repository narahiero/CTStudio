//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/EditorBar.hpp"

#include <QBoxLayout>
#include <QContextMenuEvent>
#include <QLabel>
#include <QMenu>

#include "QtUI/Editor/EditorBase.hpp"

EditorBar::EditorBar(EditorBase* editor) : QWidget(),
    m_editor{editor}
{
    m_layout = new QHBoxLayout;

    QLabel* label = new QLabel("Editor Bar");
    m_layout->addWidget(label);

    setLayout(m_layout);

    createActions();
}

EditorBar::~EditorBar() = default;

void EditorBar::createActions()
{
    m_splitHAct = new QAction(tr("Split &Horizontally"), this);
    connect(m_splitHAct, &QAction::triggered, m_editor, &EditorBase::splitH);

    m_splitVAct = new QAction(tr("Split &Vertically"), this);
    connect(m_splitVAct, &QAction::triggered, m_editor, &EditorBase::splitV);

    m_removeAct = new QAction(tr("&Close"), this);
    connect(m_removeAct, &QAction::triggered, m_editor, &EditorBase::remove);
}

void EditorBar::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu menu(this);
    menu.addAction(m_splitHAct);
    menu.addAction(m_splitVAct);
    menu.addAction(m_removeAct);
    menu.exec(event->globalPos());
}
