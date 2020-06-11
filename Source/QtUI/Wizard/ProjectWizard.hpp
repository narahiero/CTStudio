//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QWizard>

class ProjectWizard final : public QWizard
{
    Q_OBJECT

public:

    explicit ProjectWizard(QWidget* parent = nullptr);
    ~ProjectWizard();

private:

    class Page final : public QWizardPage
    {

    public:

        explicit Page(QWidget* parent = nullptr);
        ~Page();
    };

    void finish();
};
