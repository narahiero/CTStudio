//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/CoreCallbacks.hpp"

#include "Core/Callbacks.hpp"

#include "QtUI/MainWindow.hpp"

CoreCallbacks* CoreCallbacks::getInstance()
{
    return MainWindow::getInstance()->getCoreCallbacks();
}

CoreCallbacks::CoreCallbacks(QObject* parent) : QObject(parent)
{
    Callbacks::setProjectStateChangedCallback([this]() { emit projectStateChanged(); });
}

CoreCallbacks::~CoreCallbacks() = default;
