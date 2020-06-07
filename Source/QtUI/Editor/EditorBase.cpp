//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/EditorBase.hpp"

#include <QBoxLayout>

#include "QtUI/Editor/EditorBar.hpp"
#include "QtUI/Editor/EditorContainer.hpp"

EditorBase::EditorBase(EditorContainer* container) : QWidget(),
    m_container{container}
{
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_bar = new EditorBar(this);
    m_layout->addWidget(m_bar);

    setLayout(m_layout);
}

EditorBase::~EditorBase() = default;

bool EditorBase::splitH()
{
    return m_container->split(this, Qt::Orientation::Horizontal);
}

bool EditorBase::splitV()
{
    return m_container->split(this, Qt::Orientation::Vertical);
}

bool EditorBase::remove()
{
    return m_container->remove(this);
}

void EditorBase::setContents(QLayout* layout)
{
    if (m_layout->count() > 1)
    {
        QLayout* old = m_layout->itemAt(1)->layout();
        m_layout->removeItem(old);
        old->deleteLater();
    }
    m_layout->addLayout(layout);
}
