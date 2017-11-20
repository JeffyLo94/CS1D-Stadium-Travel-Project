/********************************************************************************
** Form generated from reading UI file 'userselectionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSELECTIONWINDOW_H
#define UI_USERSELECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSelectionWindow
{
public:
    QTableWidget *allStadiumsTableWidget;
    QListWidget *selectedStadiumsListWidget;
    QPushButton *backButton;
    QPushButton *goOnATripButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *onlyNationalButton;
    QPushButton *onlyAmericanButton;
    QPushButton *onlyGrassButton;
    QPushButton *noGrassButton;
    QLabel *label;
    QLabel *mileageLabel;
    QLabel *hiddenLabel;
    QPushButton *pushButton;

    void setupUi(QDialog *UserSelectionWindow)
    {
        if (UserSelectionWindow->objectName().isEmpty())
            UserSelectionWindow->setObjectName(QStringLiteral("UserSelectionWindow"));
        UserSelectionWindow->resize(1219, 709);
        allStadiumsTableWidget = new QTableWidget(UserSelectionWindow);
        if (allStadiumsTableWidget->columnCount() < 5)
            allStadiumsTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        allStadiumsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        allStadiumsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        allStadiumsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        allStadiumsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        allStadiumsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (allStadiumsTableWidget->rowCount() < 100)
            allStadiumsTableWidget->setRowCount(100);
        allStadiumsTableWidget->setObjectName(QStringLiteral("allStadiumsTableWidget"));
        allStadiumsTableWidget->setGeometry(QRect(20, 50, 821, 611));
        allStadiumsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        allStadiumsTableWidget->setTabKeyNavigation(false);
        allStadiumsTableWidget->setProperty("showDropIndicator", QVariant(false));
        allStadiumsTableWidget->setDragDropOverwriteMode(false);
        allStadiumsTableWidget->setSortingEnabled(true);
        allStadiumsTableWidget->setRowCount(100);
        selectedStadiumsListWidget = new QListWidget(UserSelectionWindow);
        selectedStadiumsListWidget->setObjectName(QStringLiteral("selectedStadiumsListWidget"));
        selectedStadiumsListWidget->setGeometry(QRect(900, 50, 291, 611));
        backButton = new QPushButton(UserSelectionWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(1100, 680, 111, 21));
        backButton->setStyleSheet(QStringLiteral("color:black;"));
        goOnATripButton = new QPushButton(UserSelectionWindow);
        goOnATripButton->setObjectName(QStringLiteral("goOnATripButton"));
        goOnATripButton->setGeometry(QRect(20, 660, 111, 21));
        addButton = new QPushButton(UserSelectionWindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(810, 660, 31, 21));
        addButton->setStyleSheet(QStringLiteral("color:black;"));
        removeButton = new QPushButton(UserSelectionWindow);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(780, 660, 31, 21));
        removeButton->setStyleSheet(QStringLiteral("color:black;"));
        onlyNationalButton = new QPushButton(UserSelectionWindow);
        onlyNationalButton->setObjectName(QStringLiteral("onlyNationalButton"));
        onlyNationalButton->setGeometry(QRect(20, 10, 121, 41));
        onlyAmericanButton = new QPushButton(UserSelectionWindow);
        onlyAmericanButton->setObjectName(QStringLiteral("onlyAmericanButton"));
        onlyAmericanButton->setGeometry(QRect(160, 10, 121, 41));
        onlyGrassButton = new QPushButton(UserSelectionWindow);
        onlyGrassButton->setObjectName(QStringLiteral("onlyGrassButton"));
        onlyGrassButton->setGeometry(QRect(300, 10, 121, 41));
        noGrassButton = new QPushButton(UserSelectionWindow);
        noGrassButton->setObjectName(QStringLiteral("noGrassButton"));
        noGrassButton->setGeometry(QRect(440, 10, 121, 41));
        label = new QLabel(UserSelectionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 30, 91, 16));
        mileageLabel = new QLabel(UserSelectionWindow);
        mileageLabel->setObjectName(QStringLiteral("mileageLabel"));
        mileageLabel->setGeometry(QRect(680, 30, 59, 16));
        hiddenLabel = new QLabel(UserSelectionWindow);
        hiddenLabel->setObjectName(QStringLiteral("hiddenLabel"));
        hiddenLabel->setGeometry(QRect(1010, 30, 71, 16));
        pushButton = new QPushButton(UserSelectionWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 0, 75, 23));

        retranslateUi(UserSelectionWindow);

        QMetaObject::connectSlotsByName(UserSelectionWindow);
    } // setupUi

    void retranslateUi(QDialog *UserSelectionWindow)
    {
        UserSelectionWindow->setWindowTitle(QApplication::translate("UserSelectionWindow", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = allStadiumsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserSelectionWindow", "Team Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = allStadiumsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserSelectionWindow", "Stadium Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = allStadiumsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserSelectionWindow", "League", 0));
        QTableWidgetItem *___qtablewidgetitem3 = allStadiumsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserSelectionWindow", "Open Date", 0));
        QTableWidgetItem *___qtablewidgetitem4 = allStadiumsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserSelectionWindow", "Grass", 0));
#ifndef QT_NO_ACCESSIBILITY
        allStadiumsTableWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        backButton->setText(QApplication::translate("UserSelectionWindow", "Back", 0));
        goOnATripButton->setText(QApplication::translate("UserSelectionWindow", "Go On A Trip!!", 0));
        addButton->setText(QApplication::translate("UserSelectionWindow", "+", 0));
        removeButton->setText(QApplication::translate("UserSelectionWindow", "-", 0));
        onlyNationalButton->setText(QApplication::translate("UserSelectionWindow", "Only National", 0));
        onlyAmericanButton->setText(QApplication::translate("UserSelectionWindow", "Only American", 0));
        onlyGrassButton->setText(QApplication::translate("UserSelectionWindow", "Only Grass", 0));
        noGrassButton->setText(QApplication::translate("UserSelectionWindow", "No Grass", 0));
        label->setText(QApplication::translate("UserSelectionWindow", "MST Mileage:", 0));
        mileageLabel->setText(QApplication::translate("UserSelectionWindow", "TextLabel", 0));
        hiddenLabel->setText(QApplication::translate("UserSelectionWindow", "Choose Start", 0));
        pushButton->setText(QApplication::translate("UserSelectionWindow", "Get Info", 0));
    } // retranslateUi

};

namespace Ui {
    class UserSelectionWindow: public Ui_UserSelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSELECTIONWINDOW_H
