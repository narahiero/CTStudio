//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Editor/NodeProperties.hpp"

NodeProperties::NodeProperties(EditorContainer* container) : EditorBase(container, 1)
{

}

NodeProperties::~NodeProperties() = default;

EditorBase* NodeProperties::duplicate()
{
    return new NodeProperties(m_container);
}
