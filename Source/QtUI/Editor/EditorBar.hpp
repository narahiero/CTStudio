//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QWidget>

class EditorBase;

class QHBoxLayout;

class EditorBar final : public QWidget
{
    Q_OBJECT

public:

    explicit EditorBar(EditorBase* editor);
    ~EditorBar();

protected:

    void contextMenuEvent(QContextMenuEvent* event) override;

private:

    void createActions();

    EditorBase* m_editor;

    QHBoxLayout* m_layout;

    QAction* m_splitHAct;
    QAction* m_splitVAct;
    QAction* m_removeAct;
};
