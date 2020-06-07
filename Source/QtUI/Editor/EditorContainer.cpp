//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/EditorContainer.hpp"

#include <QBoxLayout>
#include <QSplitter>

#include "QtUI/Editor/ProjectOutliner.hpp"

EditorContainer::EditorContainer(QWidget* parent) : QWidget(parent)
{
    m_root = new QVBoxLayout;
    m_root->setContentsMargins(0, 0, 0, 0);

    m_root->addWidget(new ProjectOutliner(this));
    m_oneEditor = true;

    setLayout(m_root);
}

EditorContainer::~EditorContainer() = default;

bool EditorContainer::hasSingularEditor() const
{
    return m_oneEditor;
}

bool EditorContainer::split(EditorBase* editor, Qt::Orientation orientation)
{
    // TODO: use same splitter if same orientation

    QSplitter* s = new QSplitter(orientation);
    s->setChildrenCollapsible(false);

    if (m_oneEditor)
    {
        m_root->removeWidget(editor);

        s->addWidget(editor);
        s->addWidget(editor->duplicate());

        m_root->addWidget(s);

        m_oneEditor = false;
    }
    else
    {
        QSplitter* sp = (QSplitter*)editor->parent();
        int index = sp->indexOf(editor);

        s->addWidget(editor);
        s->addWidget(editor->duplicate());

        sp->insertWidget(index, s);
    }

    return true;
}

bool EditorContainer::remove(EditorBase* editor)
{
    if (m_oneEditor)
    {
        return false;
    }

    QSplitter* sp = (QSplitter*)editor->parent();
    QWidget* other = sp->widget(1 - sp->indexOf(editor));

    if (sp == m_root->itemAt(0)->widget())
    {
        m_root->removeWidget(sp);
        m_root->addWidget(other);

        if (dynamic_cast<EditorBase*>(other))
        {
            m_oneEditor = true;
        }
    }
    else
    {
        QSplitter* spp = (QSplitter*)sp->parent();
        int index = spp->indexOf(sp);

        spp->replaceWidget(index, other);
    }
    sp->deleteLater();

    return true;
}
