//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include "QtUI/Editor/EditorBase.hpp"

class NodeProperties final : public EditorBase
{
    Q_OBJECT

public:

    explicit NodeProperties(EditorContainer* container);
    ~NodeProperties();

    EditorBase* duplicate() override;
};
