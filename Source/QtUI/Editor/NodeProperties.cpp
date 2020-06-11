//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/NodeProperties.hpp"

#include <QBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QScrollBar>

#include "QtUI/Editor/EditorContainer.hpp"
#include "QtUI/Editor/Node/NodeManager.hpp"
#include "QtUI/Editor/SharedEditorState.hpp"

NodeProperties::NodeProperties(EditorContainer* container) : EditorBase(container, 1)
{
    createNoSelectionLabel();
    createPropsView();

    m_layout = new QHBoxLayout;
    setContents(m_layout);

    initFromNodeManager();

    connectAll();
}

NodeProperties::~NodeProperties() = default;

EditorBase* NodeProperties::duplicate()
{
    return new NodeProperties(m_container);
}

void NodeProperties::createNoSelectionLabel()
{
    m_noSelection = new QLabel(
        QStringLiteral("<center>%1</center>").arg(tr("No node selected in project outliner..."))
    );
    m_noSelection->setWordWrap(true);
    m_noSelection->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void NodeProperties::createPropsView()
{
    m_propsView = new QTableWidget;
    m_propsView->setColumnCount(2);
    m_propsView->setRowCount(2);

    m_propsView->horizontalHeader()->hide();
    m_propsView->verticalHeader()->hide();

    m_propsView->horizontalScrollBar()->setDisabled(true);
    m_propsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void NodeProperties::initFromNodeManager()
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();

    AbstractNode* selection = manager->getSelectedNode();
    if (selection)
    {
        m_hasSelection = true;
        m_layout->addWidget(m_propsView);

        updatePropsView(selection);
    }
    else
    {
        m_hasSelection = false;
        m_layout->addWidget(m_noSelection);
    }
}

void NodeProperties::connectAll()
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();

    connect(manager, &NodeManager::nodeSelected, this, &NodeProperties::onNodeSelected);
    connect(m_propsView, &QTableWidget::itemChanged, this, &NodeProperties::onPropertyChange);
}

void NodeProperties::updatePropsView(AbstractNode* node)
{
    switch (node->getType())
    {
    case NodeType::Project:
        projectPropsView(node);
        break;

    default:
        break;
    }
}

void NodeProperties::projectPropsView(AbstractNode* node)
{
    m_propsView->clear();
    m_propsView->setRowCount(2);

    PropertyName* nodeType = new PropertyName("Type");
    m_propsView->setItem(0, 0, nodeType);

    PropertyValue* nodeTypeVal = PropertyValue::readOnlyValue(nameOf(NodeType::Project));
    m_propsView->setItem(0, 1, nodeTypeVal);

    PropertyName* nodeName = new PropertyName("Name");
    m_propsView->setItem(1, 0, nodeName);

    PropertyValue* nodeNameVal = PropertyValue::stringValue(node->getName(),
        [node](const QString& value)
        {
            node->setName(value);
        }
    );
    m_propsView->setItem(1, 1, nodeNameVal);
}

void NodeProperties::onNodeSelected(AbstractNode* node)
{
    NodeManager* manager = m_container->getSharedEditorState()->getNodeManager();

    AbstractNode* selection = manager->getSelectedNode();
    if (selection)
    {
        if (!m_hasSelection)
        {
            m_hasSelection = true;
            
            m_layout->removeWidget(m_noSelection);
            m_layout->addWidget(m_propsView);
        }

        updatePropsView(selection);
    }
    else
    {
        if (m_hasSelection)
        {
            m_hasSelection = false;

            m_layout->removeWidget(m_propsView);
            m_layout->addWidget(m_noSelection);
        }
    }
}

void NodeProperties::onPropertyChange(QTableWidgetItem* item)
{
    if (PropertyValue* pval = dynamic_cast<PropertyValue*>(item))
    {
        if (pval->valueChangeCB)
        {
            pval->valueChangeCB(pval->text());
        }
    }
}

NodeProperties::PropertyName::PropertyName(const QString& name) : QTableWidgetItem(name)
{
    setFlags(flags() & ~(Qt::ItemIsEditable | Qt::ItemIsSelectable));
}

NodeProperties::PropertyName::~PropertyName() = default;

NodeProperties::PropertyValue::PropertyValue() : QTableWidgetItem()
{

}

NodeProperties::PropertyValue::~PropertyValue() = default;

NodeProperties::PropertyValue* NodeProperties::PropertyValue::readOnlyValue(const QString& value)
{
    PropertyValue* pval = new PropertyValue;

    pval->setFlags(pval->flags() & ~Qt::ItemIsEditable);
    pval->setText(value);

    return pval;
}

NodeProperties::PropertyValue* NodeProperties::PropertyValue::stringValue(
    const QString& defVal, ValueChangeCallback cb
)
{
    PropertyValue* pval = new PropertyValue;

    pval->setText(defVal);
    pval->valueChangeCB = cb;

    return pval;
}
