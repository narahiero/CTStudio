//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QWidget>

class QVBoxLayout;

class EditorContainer final : public QWidget
{
    Q_OBJECT

    friend class EditorBase;

public:

    explicit EditorContainer(QWidget* parent = nullptr);
    ~EditorContainer();

    bool hasSingularEditor() const;

private:

    bool split(EditorBase* editor, Qt::Orientation orientation);
    bool remove(EditorBase* editor);

    QVBoxLayout* m_root;
    bool m_oneEditor;
};
