//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include <QApplication>

#include "Common/CMake.hpp"

#include "QtUI/MainWindow.hpp"

int main(int argc, char* argv[])
{
    QCoreApplication::setApplicationName("CT Studio");
    QCoreApplication::setApplicationVersion(CT_STUDIO_VERSION_STRING);

    QApplication app(argc, argv);

#ifdef _WIN32
    // use menu font
    QApplication::setFont(QApplication::font("QMenu"));
#endif

    MainWindow w;
    w.show();

    return app.exec();
}
