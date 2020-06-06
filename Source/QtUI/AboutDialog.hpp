//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QDialog>

class AboutDialog final : public QDialog
{
    Q_OBJECT

public:

    explicit AboutDialog(QWidget* parent = nullptr);
    ~AboutDialog();
};
