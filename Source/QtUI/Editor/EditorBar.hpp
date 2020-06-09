//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QWidget>

class EditorBase;

class QComboBox;
class QHBoxLayout;

class EditorBar final : public QWidget
{
    Q_OBJECT

    friend class EditorBase;

public:

    ~EditorBar();

protected:

    void contextMenuEvent(QContextMenuEvent* event) override;

private:

    explicit EditorBar(EditorBase* editor, int typeId);

    void createTypeSelect(int typeId);
    void createActions();

    EditorBase* m_editor;

    QHBoxLayout* m_layout;
    QComboBox* m_typeSelect;

    QAction* m_splitHAct;
    QAction* m_splitVAct;
    QAction* m_removeAct;
};
