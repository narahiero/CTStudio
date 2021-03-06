//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/MenuBar.hpp"

MenuBar::MenuBar(QWidget* parent): QMenuBar(parent)
{
    createFileMenu();
    createHelpMenu();
}

MenuBar::~MenuBar() = default;

void MenuBar::createFileMenu()
{
    QMenu* file = addMenu(tr("&File"));

    file->addAction(tr("&New..."), this, &MenuBar::newProject, QKeySequence::New);

    file->addSeparator();

    file->addAction(tr("E&xit"), this, &MenuBar::exit, QKeySequence::Quit);
}

void MenuBar::createHelpMenu()
{
    QMenu* help = addMenu(tr("&Help"));

    help->addAction(tr("&About"), this, &MenuBar::showAboutDialog);
}
