/********************************************************************************
** Form generated from reading UI file 'endtrip.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDTRIP_H
#define UI_ENDTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndTrip
{
public:
    QLabel *endTitle;
    QPushButton *exit;
    QLabel *numStadiums;
    QLabel *distance;
    QPushButton *mainMenu;
    QLabel *total;

    void setupUi(QDialog *EndTrip)
    {
        if (EndTrip->objectName().isEmpty())
            EndTrip->setObjectName(QStringLiteral("EndTrip"));
        EndTrip->resize(674, 480);
        endTitle = new QLabel(EndTrip);
        endTitle->setObjectName(QStringLiteral("endTitle"));
        endTitle->setGeometry(QRect(250, 20, 291, 71));
        exit = new QPushButton(EndTrip);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(290, 440, 93, 28));
        numStadiums = new QLabel(EndTrip);
        numStadiums->setObjectName(QStringLiteral("numStadiums"));
        numStadiums->setGeometry(QRect(100, 140, 471, 31));
        distance = new QLabel(EndTrip);
        distance->setObjectName(QStringLiteral("distance"));
        distance->setGeometry(QRect(110, 180, 451, 31));
        mainMenu = new QPushButton(EndTrip);
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        mainMenu->setGeometry(QRect(290, 400, 93, 28));
        total = new QLabel(EndTrip);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(130, 230, 421, 31));

        retranslateUi(EndTrip);

        QMetaObject::connectSlotsByName(EndTrip);
    } // setupUi

    void retranslateUi(QDialog *EndTrip)
    {
        EndTrip->setWindowTitle(QApplication::translate("EndTrip", "Dialog", 0));
        endTitle->setText(QApplication::translate("EndTrip", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Welcome back!</span></p></body></html>", 0));
        exit->setText(QApplication::translate("EndTrip", "Exit", 0));
        numStadiums->setText(QString());
        distance->setText(QApplication::translate("EndTrip", "<html><head/><body><p><br/></p></body></html>", 0));
        mainMenu->setText(QApplication::translate("EndTrip", "Main Menu", 0));
        total->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EndTrip: public Ui_EndTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDTRIP_H
