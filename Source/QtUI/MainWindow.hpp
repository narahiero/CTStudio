//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QMainWindow>

class EditorContainer;
class MenuBar;
class StatusBar;

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
    void createStatusBar();
    void createEditorContainer();

    MenuBar* m_menubar;
    StatusBar* m_statusbar;

    EditorContainer* m_container;
};
