//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/MainWindow.hpp"

#include "QtUI/AboutDialog.hpp"
#include "QtUI/CoreCallbacks.hpp"
#include "QtUI/Editor/EditorContainer.hpp"
#include "QtUI/MenuBar.hpp"
#include "QtUI/StatusBar.hpp"
#include "QtUI/Wizard/ProjectWizard.hpp"

MainWindow* MainWindow::s_instance = nullptr;

MainWindow* MainWindow::getInstance()
{
    return s_instance;
}

MainWindow::MainWindow() : QMainWindow()
{
    s_instance = this;

    resize(1080, 720);

    m_coreCBs = new CoreCallbacks(this);

    createMenuBar();
    createStatusBar();
    createEditorContainer();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenuBar()
{
    m_menubar = new MenuBar(this);

    // file menu
    connect(m_menubar, &MenuBar::newProject, this, &MainWindow::showProjectWizard);
    connect(m_menubar, &MenuBar::exit, this, &MainWindow::requestTerminate);

    // help menu
    connect(m_menubar, &MenuBar::showAboutDialog, this, &MainWindow::showAboutDialog);

    setMenuBar(m_menubar);
}

void MainWindow::createStatusBar()
{
    m_statusbar = new StatusBar(this);

    setStatusBar(m_statusbar);
}

void MainWindow::createEditorContainer()
{
    m_container = new EditorContainer(this);

    setCentralWidget(m_container);
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

CoreCallbacks* MainWindow::getCoreCallbacks() const
{
    return m_coreCBs;
}

void MainWindow::showProjectWizard()
{
    ProjectWizard wizard;
    wizard.exec();
}

void MainWindow::showAboutDialog()
{
    AboutDialog dialog;
    dialog.exec();
}
