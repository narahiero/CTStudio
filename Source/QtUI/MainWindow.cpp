//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/MainWindow.hpp"

#include "QtUI/AboutDialog.hpp"
#include "QtUI/MenuBar.hpp"

MainWindow::MainWindow() : QMainWindow()
{
    resize(1080, 720);

    createMenuBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenuBar()
{
    m_menubar = new MenuBar(this);

    // file menu
    connect(m_menubar, &MenuBar::exit, this, &MainWindow::requestTerminate);

    // help menu
    connect(m_menubar, &MenuBar::showAboutDialog, this, &MainWindow::showAboutDialog);

    setMenuBar(m_menubar);
}

void MainWindow::terminate()
{
    close();
}

// later, will ask whether the user wants to quit if project not saved
bool MainWindow::requestTerminate()
{
    terminate();
    return true;
}

void MainWindow::showAboutDialog()
{
    AboutDialog dialog;
    dialog.exec();
}
