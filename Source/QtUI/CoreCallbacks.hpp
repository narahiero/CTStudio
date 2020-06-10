//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QObject>

class CoreCallbacks final : public QObject
{
    Q_OBJECT

public:

    static CoreCallbacks* getInstance();

    explicit CoreCallbacks(QObject* parent = nullptr);
    ~CoreCallbacks();

signals:

    void projectStateChanged();
};
