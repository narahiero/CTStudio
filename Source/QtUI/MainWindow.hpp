//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#pragma once

#include <QMainWindow>

class CoreCallbacks;
class EditorContainer;
class MenuBar;
class StatusBar;

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:

    static MainWindow* getInstance();

    MainWindow();
    ~MainWindow();

    void terminate();

    bool requestTerminate();

    CoreCallbacks* getCoreCallbacks() const;

    void showAboutDialog();

private:

    void createMenuBar();
    void createStatusBar();
    void createEditorContainer();

    static MainWindow* s_instance;

    CoreCallbacks* m_coreCBs;

    MenuBar* m_menubar;
    StatusBar* m_statusbar;

    EditorContainer* m_container;
};
