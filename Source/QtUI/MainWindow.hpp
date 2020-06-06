//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QMainWindow>

class MenuBar;

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();
    ~MainWindow();

    void terminate();

    bool requestTerminate();

    void showAboutDialog();

private:

    void createMenuBar();

    MenuBar* m_menubar;
};
