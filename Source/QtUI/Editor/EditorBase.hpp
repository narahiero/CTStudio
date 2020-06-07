//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QWidget>

class EditorBar;
class EditorContainer;

class QLayout;
class QVBoxLayout;

class EditorBase : public QWidget
{
    Q_OBJECT

    friend class EditorContainer;

public:

    explicit EditorBase(EditorContainer* container);
    ~EditorBase();

    EditorContainer* getContainer() const;

    virtual EditorBase* duplicate() = 0;

    bool splitH();
    bool splitV();
    bool remove();

protected:

    void setContents(QLayout* layout);

    EditorContainer* m_container;

private:

    QVBoxLayout* m_layout;
    EditorBar* m_bar;
};
