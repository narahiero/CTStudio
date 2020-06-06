//////////////////////////////////////////////////
//  Copyright (c) 2020 Nara Hiero
//
// This file is licensed under GPLv3+
// Refer to the `License.txt` file included.
//////////////////////////////////////////////////

#include "QtUI/AboutDialog.hpp"

#include <QBoxLayout>
#include <QLabel>

#include "Common/CMake.hpp"

AboutDialog::AboutDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle(tr("About CT Studio"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setFixedSize(240, 180);

    QString text = QStringLiteral("%1: %2").arg(tr("Version")).arg(CT_STUDIO_VERSION_STRING);
    QLabel* label = new QLabel(text);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(label);

    setLayout(layout);
}

AboutDialog::~AboutDialog() = default;
