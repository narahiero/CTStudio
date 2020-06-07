//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QStatusBar>

class StatusBar final : public QStatusBar
{
    Q_OBJECT

public:

    explicit StatusBar(QWidget* parent = nullptr);
    ~StatusBar();
};
