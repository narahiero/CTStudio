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

    friend class EditorBar;
    friend class EditorContainer;

public:

    ~EditorBase();

    EditorContainer* getContainer() const;

    virtual EditorBase* duplicate() = 0;

    bool splitH();
    bool splitV();
    bool remove();

protected:

    explicit EditorBase(EditorContainer* container, int typeId);

    void setContents(QLayout* layout);

    EditorContainer* m_container;

private:

    void morphInto(int typeId);

    QVBoxLayout* m_layout;
    EditorBar* m_bar;
};
