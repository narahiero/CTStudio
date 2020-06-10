//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "Core/Callbacks.hpp"

namespace Callbacks
{

//////////////////////////////
/// Callback holders

static ProjectStateChangedCallback s_projectStateCB = nullptr;

//////////////////////////////
/// Callback invokers

void projectStateChanged()
{
    if (s_projectStateCB)
    {
        s_projectStateCB();
    }
}

//////////////////////////////
/// Callback setters

void setProjectStateChangedCallback(ProjectStateChangedCallback cb)
{
    s_projectStateCB = cb;
}
}
