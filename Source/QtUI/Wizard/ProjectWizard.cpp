//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/Wizard/ProjectWizard.hpp"

#include <QAbstractButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

#include "Core/Core.hpp"
#include "Core/ProjectManager.hpp"

ProjectWizard::ProjectWizard(QWidget* parent) : QWizard(parent)
{
    setWindowTitle(tr("Project Wizard"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    addPage(new Page);

    QAbstractButton* finishButton = button(FinishButton);
    connect(finishButton, &QAbstractButton::clicked, this, &ProjectWizard::finish);
}

ProjectWizard::~ProjectWizard() = default;

void ProjectWizard::finish()
{
    Core::getProjectManager().createProject(field("name").toString().toStdString());
}

ProjectWizard::Page::Page(QWidget* parent) : QWizardPage(parent)
{
    setTitle(tr("Create new Project"));

    QGridLayout* layout = new QGridLayout;

    QLabel* nameLabel = new QLabel(tr("Project name:"));
    QLineEdit* nameEdit = new QLineEdit;

    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameEdit, 0, 1);

    setLayout(layout);

    registerField("name*", nameEdit);
}

ProjectWizard::Page::~Page() = default;
