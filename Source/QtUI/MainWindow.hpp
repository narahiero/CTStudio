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
    void createEditorContainer();

    MenuBar* m_menubar;

    EditorContainer* m_container;
};
