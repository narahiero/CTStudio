//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

// Callbacks header is used to allow the UI to be notified of changes to the core
// without introducing a dependecy

#include <functional>

namespace Callbacks
{

//////////////////////////////
/// Callback invokers

void projectStateChanged();

//////////////////////////////
/// Callback setters

using ProjectStateChangedCallback = std::function<void()>;
void setProjectStateChangedCallback(ProjectStateChangedCallback cb);
}
