//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/EditorBar.hpp"

#include <QBoxLayout>
#include <QComboBox>
#include <QContextMenuEvent>
#include <QMenu>

#include "QtUI/Editor/EditorBase.hpp"
#include "QtUI/Editor/EditorContainer.hpp"

EditorBar::EditorBar(EditorBase* editor, int typeId) : QWidget(),
    m_editor{editor}
{
    m_layout = new QHBoxLayout;

    createTypeSelect(typeId);
    m_layout->addWidget(m_typeSelect);

    setLayout(m_layout);

    createActions();
}

EditorBar::~EditorBar() = default;

void EditorBar::createTypeSelect(int typeId)
{
    m_typeSelect = new QComboBox;

    auto typeInfoList = m_editor->getContainer()->getTypeInfo();
    for (auto typeInfo : typeInfoList)
    {
        m_typeSelect->addItem(typeInfo.m_name);
    }

    m_typeSelect->setCurrentIndex(typeId);

    connect(m_typeSelect, qOverload<int>(&QComboBox::currentIndexChanged), m_editor, &EditorBase::morphInto);
}

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
    m_removeAct->setDisabled(m_editor->getContainer()->hasSingularEditor());

    QMenu menu(this);
    menu.addAction(m_splitHAct);
    menu.addAction(m_splitVAct);
    menu.addAction(m_removeAct);
    menu.exec(event->globalPos());
}
