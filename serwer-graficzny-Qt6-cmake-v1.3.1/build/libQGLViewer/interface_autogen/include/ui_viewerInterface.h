/********************************************************************************
** Form generated from reading UI file 'viewerInterface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERINTERFACE_H
#define UI_VIEWERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "interface.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *vboxLayout;
    Viewer *viewer;
    QHBoxLayout *hboxLayout;
    QCheckBox *FPSCheckBox;
    QCheckBox *GridCheckBox;
    QCheckBox *AxisCheckBox;
    QSpacerItem *spacerItem;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(650, 468);
        vboxLayout = new QVBoxLayout(Dialog);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        viewer = new Viewer(Dialog);
        viewer->setObjectName("viewer");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(viewer->sizePolicy().hasHeightForWidth());
        viewer->setSizePolicy(sizePolicy);

        vboxLayout->addWidget(viewer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        FPSCheckBox = new QCheckBox(Dialog);
        FPSCheckBox->setObjectName("FPSCheckBox");

        hboxLayout->addWidget(FPSCheckBox);

        GridCheckBox = new QCheckBox(Dialog);
        GridCheckBox->setObjectName("GridCheckBox");

        hboxLayout->addWidget(GridCheckBox);

        AxisCheckBox = new QCheckBox(Dialog);
        AxisCheckBox->setObjectName("AxisCheckBox");

        hboxLayout->addWidget(AxisCheckBox);

        spacerItem = new QSpacerItem(141, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName("cancelButton");

        hboxLayout->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(Dialog);
        QObject::connect(cancelButton, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::reject));
        QObject::connect(FPSCheckBox, SIGNAL(clicked(bool)), viewer, SLOT(setFPSIsDisplayed(bool)));
        QObject::connect(AxisCheckBox, SIGNAL(clicked(bool)), viewer, SLOT(setAxisIsDrawn(bool)));
        QObject::connect(GridCheckBox, SIGNAL(clicked(bool)), viewer, SLOT(setGridIsDrawn(bool)));
        QObject::connect(viewer, SIGNAL(gridIsDrawnChanged(bool)), GridCheckBox, SLOT(setChecked(bool)));
        QObject::connect(viewer, SIGNAL(axisIsDrawnChanged(bool)), AxisCheckBox, SLOT(setChecked(bool)));
        QObject::connect(viewer, SIGNAL(FPSIsDisplayedChanged(bool)), FPSCheckBox, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Interface", nullptr));
        FPSCheckBox->setText(QCoreApplication::translate("Dialog", "FPS", nullptr));
        GridCheckBox->setText(QCoreApplication::translate("Dialog", "Grid", nullptr));
        AxisCheckBox->setText(QCoreApplication::translate("Dialog", "Axis", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERINTERFACE_H
