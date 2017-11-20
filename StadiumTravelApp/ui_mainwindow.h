/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *adminButton;
    QPushButton *chooseStartButton;
    QPushButton *dreamButton;
    QPushButton *chooseEndButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(541, 408);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        adminButton = new QPushButton(centralWidget);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setGeometry(QRect(210, 290, 121, 41));
        chooseStartButton = new QPushButton(centralWidget);
        chooseStartButton->setObjectName(QStringLiteral("chooseStartButton"));
        chooseStartButton->setGeometry(QRect(210, 160, 121, 41));
        dreamButton = new QPushButton(centralWidget);
        dreamButton->setObjectName(QStringLiteral("dreamButton"));
        dreamButton->setGeometry(QRect(210, 110, 121, 41));
        chooseEndButton = new QPushButton(centralWidget);
        chooseEndButton->setObjectName(QStringLiteral("chooseEndButton"));
        chooseEndButton->setGeometry(QRect(210, 60, 121, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 541, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        adminButton->setText(QApplication::translate("MainWindow", "Admin", 0));
        chooseStartButton->setText(QApplication::translate("MainWindow", "Choose Start", 0));
        dreamButton->setText(QApplication::translate("MainWindow", "Dream Trip", 0));
        chooseEndButton->setText(QApplication::translate("MainWindow", "Choose End", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
