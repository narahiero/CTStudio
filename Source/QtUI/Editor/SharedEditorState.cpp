//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/SharedEditorState.hpp"

#include "QtUI/Editor/Node/NodeManager.hpp"

SharedEditorState::SharedEditorState(QObject* parent) : QObject(parent)
{
    m_nodeManager = new NodeManager(this);
}

SharedEditorState::~SharedEditorState() = default;

NodeManager* SharedEditorState::getNodeManager() const
{
    return m_nodeManager;
}
