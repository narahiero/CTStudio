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

    struct EditorTypeInfo
    {
        QString m_name;
        EditorBase*(*m_factory)(EditorContainer*);
    };

    explicit EditorContainer(QWidget* parent = nullptr);
    ~EditorContainer();

    bool hasSingularEditor() const;

    QList<EditorTypeInfo> getTypeInfo() const;

private:

    bool split(EditorBase* editor, Qt::Orientation orientation);
    bool remove(EditorBase* editor);

    void morph(EditorBase* editor, int typeId);

    void registerAllTypeInfo();
    void registerTypeInfo(const QString& name, EditorBase*(*factory)(EditorContainer*));

    QVBoxLayout* m_root;
    bool m_oneEditor;

    QList<EditorTypeInfo> m_typeInfo;
};
