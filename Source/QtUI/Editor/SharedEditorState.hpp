//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QObject>

class NodeManager;

class SharedEditorState final : public QObject
{

public:

    explicit SharedEditorState(QObject* parent = nullptr);
    ~SharedEditorState();

    NodeManager* getNodeManager() const;

private:

    NodeManager* m_nodeManager;
};
