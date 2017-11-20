/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_infoWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *infoWindow)
    {
        if (infoWindow->objectName().isEmpty())
            infoWindow->setObjectName(QStringLiteral("infoWindow"));
        infoWindow->resize(527, 389);
        label = new QLabel(infoWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 401, 351));

        retranslateUi(infoWindow);

        QMetaObject::connectSlotsByName(infoWindow);
    } // setupUi

    void retranslateUi(QDialog *infoWindow)
    {
        infoWindow->setWindowTitle(QApplication::translate("infoWindow", "Dialog", 0));
        label->setText(QApplication::translate("infoWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class infoWindow: public Ui_infoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
