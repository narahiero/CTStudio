//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include "QtUI/Editor/EditorBase.hpp"

#include <functional>

#include <QTableWidget>

class QHBoxLayout;
class QLabel;

class AbstractNode;

class NodeProperties final : public EditorBase
{
    Q_OBJECT

public:

    explicit NodeProperties(EditorContainer* container);
    ~NodeProperties();

    EditorBase* duplicate() override;

private:

    class PropertyName final : public QTableWidgetItem
    {

    public:

        explicit PropertyName(const QString& name);
        ~PropertyName();
    };

    class PropertyValue final : public QTableWidgetItem
    {

    public:

        using ValueChangeCallback = std::function<void(const QString&)>;

        static PropertyValue* readOnlyValue(const QString& value);
        static PropertyValue* stringValue(const QString& defVal, ValueChangeCallback cb);

        explicit PropertyValue();
        ~PropertyValue();

        // nullable
        ValueChangeCallback valueChangeCB;
    };

    void createNoSelectionLabel();
    void createPropsView();
    void initFromNodeManager();
    void connectAll();

    // NodeManager selected node must not be nullptr
    void updatePropsView(AbstractNode* node);
    void projectPropsView(AbstractNode* node);
    void folderPropsView(AbstractNode* node);

    void onNodeSelected(AbstractNode* node);
    void onPropertyChange(QTableWidgetItem* item);

    QHBoxLayout* m_layout;
    bool m_hasSelection;

    QLabel* m_noSelection;

    QTableWidget* m_propsView;
};
