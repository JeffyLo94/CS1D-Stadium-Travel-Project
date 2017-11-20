/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminwindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *stadiumPg;
    QFrame *stadiumSelectFrame;
    QLabel *stadiumSelectLabel;
    QListWidget *stadiumSelectWidget;
    QPushButton *addStadBtn;
    QFrame *leagueSelectFrame;
    QComboBox *leagueSelectComboBox;
    QLabel *leagueSelectLabel;
    QFrame *frame;
    QPushButton *saveBtn;
    QPushButton *backBtn;
    QTabWidget *tabWidget;
    QWidget *stadEditTab;
    QLineEdit *stadNameEdit;
    QLabel *stadNameLabel;
    QLabel *teamNameLabel;
    QLineEdit *teamNameEdit;
    QLabel *streetAddressLavel;
    QLineEdit *streetAddressEdit;
    QLineEdit *cityNameEdit;
    QLabel *cityNameLabel;
    QLabel *stateLabel;
    QLineEdit *zipCodeEdit;
    QLabel *zipCodeLabel;
    QLineEdit *phoneNumEdit;
    QLabel *phoneNumLabel;
    QFrame *lineStadToAddress;
    QFrame *lineAddressToExtra;
    QLabel *openDateLabel;
    QFrame *lineExtraToCapacity;
    QComboBox *stateComboBox;
    QLabel *countryLabel;
    QComboBox *countryComboBox;
    QLineEdit *maxCapacity;
    QLineEdit *maxCapacityFrameEdit;
    QLabel *capacityLabel_1;
    QLabel *capacitySeason_1;
    QLineEdit *minCapacity;
    QLabel *capacitySeason_2;
    QLabel *capacityLabel_2;
    QLineEdit *minCapacityFrameEdit;
    QLabel *leagueEditLabel;
    QComboBox *leagueEditComboBox;
    QLabel *grassLabel;
    QComboBox *grassEdit;
    QLineEdit *dateEdit;
    QWidget *souvEditTab;
    QTableView *souvenirTableEdit;
    QLabel *souvenirEditLabel;
    QLineEdit *souvNameLineEdit;
    QLineEdit *souvPriceLineEdit;
    QLabel *nameLabel;
    QLabel *priceLabel;
    QLabel *instruction1;
    QLabel *instruction2;
    QPushButton *updateBtn;
    QPushButton *addNewBtn;
    QPushButton *deleteSouv;
    QWidget *EdgesEdit;
    QTableView *adjMatrix;
    QLabel *label;
    QPushButton *addNewStadBtn;

    void setupUi(QDialog *adminwindow)
    {
        if (adminwindow->objectName().isEmpty())
            adminwindow->setObjectName(QStringLiteral("adminwindow"));
        adminwindow->resize(1205, 710);
        stackedWidget = new QStackedWidget(adminwindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 20, 1181, 671));
        stackedWidget->setMinimumSize(QSize(1181, 671));
        stackedWidget->setFrameShape(QFrame::Box);
        stackedWidget->setFrameShadow(QFrame::Raised);
        stadiumPg = new QWidget();
        stadiumPg->setObjectName(QStringLiteral("stadiumPg"));
        stadiumPg->setMinimumSize(QSize(1179, 669));
        stadiumSelectFrame = new QFrame(stadiumPg);
        stadiumSelectFrame->setObjectName(QStringLiteral("stadiumSelectFrame"));
        stadiumSelectFrame->setGeometry(QRect(20, 120, 361, 521));
        stadiumSelectFrame->setFrameShape(QFrame::StyledPanel);
        stadiumSelectFrame->setFrameShadow(QFrame::Sunken);
        stadiumSelectLabel = new QLabel(stadiumSelectFrame);
        stadiumSelectLabel->setObjectName(QStringLiteral("stadiumSelectLabel"));
        stadiumSelectLabel->setGeometry(QRect(20, 10, 121, 16));
        stadiumSelectWidget = new QListWidget(stadiumSelectFrame);
        stadiumSelectWidget->setObjectName(QStringLiteral("stadiumSelectWidget"));
        stadiumSelectWidget->setGeometry(QRect(20, 40, 321, 461));
        addStadBtn = new QPushButton(stadiumSelectFrame);
        addStadBtn->setObjectName(QStringLiteral("addStadBtn"));
        addStadBtn->setGeometry(QRect(200, 10, 141, 21));
        addStadBtn->setAutoDefault(false);
        leagueSelectFrame = new QFrame(stadiumPg);
        leagueSelectFrame->setObjectName(QStringLiteral("leagueSelectFrame"));
        leagueSelectFrame->setGeometry(QRect(20, 20, 361, 71));
        leagueSelectFrame->setFrameShape(QFrame::StyledPanel);
        leagueSelectFrame->setFrameShadow(QFrame::Sunken);
        leagueSelectComboBox = new QComboBox(leagueSelectFrame);
        leagueSelectComboBox->setObjectName(QStringLiteral("leagueSelectComboBox"));
        leagueSelectComboBox->setGeometry(QRect(20, 40, 321, 21));
        leagueSelectLabel = new QLabel(leagueSelectFrame);
        leagueSelectLabel->setObjectName(QStringLiteral("leagueSelectLabel"));
        leagueSelectLabel->setGeometry(QRect(20, 10, 121, 16));
        frame = new QFrame(stadiumPg);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(410, 20, 741, 621));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        saveBtn = new QPushButton(frame);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(20, 560, 141, 41));
        saveBtn->setToolTipDuration(-1);
        saveBtn->setAutoDefault(false);
        backBtn = new QPushButton(frame);
        backBtn->setObjectName(QStringLiteral("backBtn"));
        backBtn->setGeometry(QRect(580, 560, 141, 41));
        backBtn->setAutoDefault(false);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 701, 521));
        tabWidget->setTabShape(QTabWidget::Triangular);
        stadEditTab = new QWidget();
        stadEditTab->setObjectName(QStringLiteral("stadEditTab"));
        stadNameEdit = new QLineEdit(stadEditTab);
        stadNameEdit->setObjectName(QStringLiteral("stadNameEdit"));
        stadNameEdit->setGeometry(QRect(30, 90, 291, 21));
        stadNameLabel = new QLabel(stadEditTab);
        stadNameLabel->setObjectName(QStringLiteral("stadNameLabel"));
        stadNameLabel->setGeometry(QRect(30, 70, 131, 16));
        teamNameLabel = new QLabel(stadEditTab);
        teamNameLabel->setObjectName(QStringLiteral("teamNameLabel"));
        teamNameLabel->setGeometry(QRect(370, 70, 131, 16));
        teamNameEdit = new QLineEdit(stadEditTab);
        teamNameEdit->setObjectName(QStringLiteral("teamNameEdit"));
        teamNameEdit->setGeometry(QRect(370, 90, 291, 21));
        streetAddressLavel = new QLabel(stadEditTab);
        streetAddressLavel->setObjectName(QStringLiteral("streetAddressLavel"));
        streetAddressLavel->setGeometry(QRect(30, 140, 131, 16));
        streetAddressEdit = new QLineEdit(stadEditTab);
        streetAddressEdit->setObjectName(QStringLiteral("streetAddressEdit"));
        streetAddressEdit->setGeometry(QRect(30, 160, 291, 21));
        cityNameEdit = new QLineEdit(stadEditTab);
        cityNameEdit->setObjectName(QStringLiteral("cityNameEdit"));
        cityNameEdit->setGeometry(QRect(370, 160, 291, 21));
        cityNameLabel = new QLabel(stadEditTab);
        cityNameLabel->setObjectName(QStringLiteral("cityNameLabel"));
        cityNameLabel->setGeometry(QRect(370, 140, 131, 16));
        stateLabel = new QLabel(stadEditTab);
        stateLabel->setObjectName(QStringLiteral("stateLabel"));
        stateLabel->setGeometry(QRect(370, 190, 131, 16));
        zipCodeEdit = new QLineEdit(stadEditTab);
        zipCodeEdit->setObjectName(QStringLiteral("zipCodeEdit"));
        zipCodeEdit->setGeometry(QRect(30, 260, 291, 21));
        zipCodeLabel = new QLabel(stadEditTab);
        zipCodeLabel->setObjectName(QStringLiteral("zipCodeLabel"));
        zipCodeLabel->setGeometry(QRect(30, 240, 131, 16));
        phoneNumEdit = new QLineEdit(stadEditTab);
        phoneNumEdit->setObjectName(QStringLiteral("phoneNumEdit"));
        phoneNumEdit->setGeometry(QRect(370, 260, 291, 21));
        phoneNumLabel = new QLabel(stadEditTab);
        phoneNumLabel->setObjectName(QStringLiteral("phoneNumLabel"));
        phoneNumLabel->setGeometry(QRect(370, 240, 131, 16));
        lineStadToAddress = new QFrame(stadEditTab);
        lineStadToAddress->setObjectName(QStringLiteral("lineStadToAddress"));
        lineStadToAddress->setGeometry(QRect(30, 110, 631, 16));
        lineStadToAddress->setFrameShape(QFrame::HLine);
        lineStadToAddress->setFrameShadow(QFrame::Sunken);
        lineAddressToExtra = new QFrame(stadEditTab);
        lineAddressToExtra->setObjectName(QStringLiteral("lineAddressToExtra"));
        lineAddressToExtra->setGeometry(QRect(30, 290, 631, 16));
        lineAddressToExtra->setFrameShape(QFrame::HLine);
        lineAddressToExtra->setFrameShadow(QFrame::Sunken);
        openDateLabel = new QLabel(stadEditTab);
        openDateLabel->setObjectName(QStringLiteral("openDateLabel"));
        openDateLabel->setGeometry(QRect(370, 310, 131, 16));
        lineExtraToCapacity = new QFrame(stadEditTab);
        lineExtraToCapacity->setObjectName(QStringLiteral("lineExtraToCapacity"));
        lineExtraToCapacity->setGeometry(QRect(30, 360, 631, 16));
        lineExtraToCapacity->setFrameShape(QFrame::HLine);
        lineExtraToCapacity->setFrameShadow(QFrame::Sunken);
        stateComboBox = new QComboBox(stadEditTab);
        stateComboBox->setObjectName(QStringLiteral("stateComboBox"));
        stateComboBox->setGeometry(QRect(370, 210, 291, 22));
        countryLabel = new QLabel(stadEditTab);
        countryLabel->setObjectName(QStringLiteral("countryLabel"));
        countryLabel->setGeometry(QRect(30, 190, 131, 16));
        countryComboBox = new QComboBox(stadEditTab);
        countryComboBox->setObjectName(QStringLiteral("countryComboBox"));
        countryComboBox->setGeometry(QRect(30, 210, 291, 22));
        maxCapacity = new QLineEdit(stadEditTab);
        maxCapacity->setObjectName(QStringLiteral("maxCapacity"));
        maxCapacity->setGeometry(QRect(30, 400, 291, 21));
        maxCapacityFrameEdit = new QLineEdit(stadEditTab);
        maxCapacityFrameEdit->setObjectName(QStringLiteral("maxCapacityFrameEdit"));
        maxCapacityFrameEdit->setGeometry(QRect(370, 400, 291, 21));
        capacityLabel_1 = new QLabel(stadEditTab);
        capacityLabel_1->setObjectName(QStringLiteral("capacityLabel_1"));
        capacityLabel_1->setGeometry(QRect(30, 380, 141, 16));
        capacitySeason_1 = new QLabel(stadEditTab);
        capacitySeason_1->setObjectName(QStringLiteral("capacitySeason_1"));
        capacitySeason_1->setGeometry(QRect(370, 380, 141, 16));
        minCapacity = new QLineEdit(stadEditTab);
        minCapacity->setObjectName(QStringLiteral("minCapacity"));
        minCapacity->setEnabled(true);
        minCapacity->setGeometry(QRect(30, 450, 291, 21));
        capacitySeason_2 = new QLabel(stadEditTab);
        capacitySeason_2->setObjectName(QStringLiteral("capacitySeason_2"));
        capacitySeason_2->setEnabled(true);
        capacitySeason_2->setGeometry(QRect(370, 430, 141, 16));
        capacityLabel_2 = new QLabel(stadEditTab);
        capacityLabel_2->setObjectName(QStringLiteral("capacityLabel_2"));
        capacityLabel_2->setEnabled(true);
        capacityLabel_2->setGeometry(QRect(30, 430, 141, 16));
        minCapacityFrameEdit = new QLineEdit(stadEditTab);
        minCapacityFrameEdit->setObjectName(QStringLiteral("minCapacityFrameEdit"));
        minCapacityFrameEdit->setEnabled(true);
        minCapacityFrameEdit->setGeometry(QRect(370, 450, 291, 21));
        leagueEditLabel = new QLabel(stadEditTab);
        leagueEditLabel->setObjectName(QStringLiteral("leagueEditLabel"));
        leagueEditLabel->setGeometry(QRect(30, 20, 131, 16));
        leagueEditComboBox = new QComboBox(stadEditTab);
        leagueEditComboBox->setObjectName(QStringLiteral("leagueEditComboBox"));
        leagueEditComboBox->setGeometry(QRect(30, 40, 291, 22));
        grassLabel = new QLabel(stadEditTab);
        grassLabel->setObjectName(QStringLiteral("grassLabel"));
        grassLabel->setGeometry(QRect(30, 310, 131, 16));
        grassEdit = new QComboBox(stadEditTab);
        grassEdit->setObjectName(QStringLiteral("grassEdit"));
        grassEdit->setGeometry(QRect(30, 330, 291, 22));
        dateEdit = new QLineEdit(stadEditTab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(370, 330, 291, 21));
        tabWidget->addTab(stadEditTab, QString());
        souvEditTab = new QWidget();
        souvEditTab->setObjectName(QStringLiteral("souvEditTab"));
        souvenirTableEdit = new QTableView(souvEditTab);
        souvenirTableEdit->setObjectName(QStringLiteral("souvenirTableEdit"));
        souvenirTableEdit->setGeometry(QRect(20, 90, 311, 391));
        souvenirEditLabel = new QLabel(souvEditTab);
        souvenirEditLabel->setObjectName(QStringLiteral("souvenirEditLabel"));
        souvenirEditLabel->setGeometry(QRect(20, 20, 211, 16));
        souvNameLineEdit = new QLineEdit(souvEditTab);
        souvNameLineEdit->setObjectName(QStringLiteral("souvNameLineEdit"));
        souvNameLineEdit->setGeometry(QRect(380, 130, 271, 21));
        souvPriceLineEdit = new QLineEdit(souvEditTab);
        souvPriceLineEdit->setObjectName(QStringLiteral("souvPriceLineEdit"));
        souvPriceLineEdit->setGeometry(QRect(380, 210, 271, 21));
        nameLabel = new QLabel(souvEditTab);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(380, 100, 71, 21));
        priceLabel = new QLabel(souvEditTab);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        priceLabel->setGeometry(QRect(380, 180, 71, 21));
        instruction1 = new QLabel(souvEditTab);
        instruction1->setObjectName(QStringLiteral("instruction1"));
        instruction1->setGeometry(QRect(20, 60, 151, 16));
        instruction2 = new QLabel(souvEditTab);
        instruction2->setObjectName(QStringLiteral("instruction2"));
        instruction2->setGeometry(QRect(380, 70, 211, 16));
        updateBtn = new QPushButton(souvEditTab);
        updateBtn->setObjectName(QStringLiteral("updateBtn"));
        updateBtn->setGeometry(QRect(380, 350, 271, 51));
        addNewBtn = new QPushButton(souvEditTab);
        addNewBtn->setObjectName(QStringLiteral("addNewBtn"));
        addNewBtn->setGeometry(QRect(380, 270, 271, 51));
        deleteSouv = new QPushButton(souvEditTab);
        deleteSouv->setObjectName(QStringLiteral("deleteSouv"));
        deleteSouv->setGeometry(QRect(380, 430, 271, 51));
        tabWidget->addTab(souvEditTab, QString());
        EdgesEdit = new QWidget();
        EdgesEdit->setObjectName(QStringLiteral("EdgesEdit"));
        adjMatrix = new QTableView(EdgesEdit);
        adjMatrix->setObjectName(QStringLiteral("adjMatrix"));
        adjMatrix->setGeometry(QRect(10, 40, 671, 451));
        label = new QLabel(EdgesEdit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(15, 10, 161, 20));
        tabWidget->addTab(EdgesEdit, QString());
        addNewStadBtn = new QPushButton(frame);
        addNewStadBtn->setObjectName(QStringLiteral("addNewStadBtn"));
        addNewStadBtn->setEnabled(true);
        addNewStadBtn->setGeometry(QRect(300, 560, 141, 41));
        addNewStadBtn->setToolTipDuration(-1);
        addNewStadBtn->setAutoDefault(false);
        stackedWidget->addWidget(stadiumPg);
        frame->raise();
        stadiumSelectFrame->raise();
        leagueSelectFrame->raise();

        retranslateUi(adminwindow);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminwindow);
    } // setupUi

    void retranslateUi(QDialog *adminwindow)
    {
        adminwindow->setWindowTitle(QApplication::translate("adminwindow", "Dialog", 0));
        stadiumSelectLabel->setText(QApplication::translate("adminwindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Select Stadium:</span></p></body></html>", 0));
        addStadBtn->setText(QApplication::translate("adminwindow", "Add a Stadium", 0));
        leagueSelectLabel->setText(QApplication::translate("adminwindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Select League:</span></p></body></html>", 0));
        saveBtn->setText(QApplication::translate("adminwindow", "Save Changes", 0));
        backBtn->setText(QApplication::translate("adminwindow", "Back", 0));
        stadNameLabel->setText(QApplication::translate("adminwindow", "Stadium Name:", 0));
        teamNameLabel->setText(QApplication::translate("adminwindow", "Team Name:", 0));
        streetAddressLavel->setText(QApplication::translate("adminwindow", "Street Address:", 0));
        cityNameLabel->setText(QApplication::translate("adminwindow", "City Name:", 0));
        stateLabel->setText(QApplication::translate("adminwindow", "State:", 0));
        zipCodeLabel->setText(QApplication::translate("adminwindow", "Zip Code:", 0));
        phoneNumLabel->setText(QApplication::translate("adminwindow", "Phone Number:", 0));
        openDateLabel->setText(QApplication::translate("adminwindow", "Opening Date:", 0));
        countryLabel->setText(QApplication::translate("adminwindow", "Country:", 0));
        capacityLabel_1->setText(QApplication::translate("adminwindow", "Max Capacity:", 0));
        capacitySeason_1->setText(QApplication::translate("adminwindow", "Season/Time Frame:", 0));
        capacitySeason_2->setText(QApplication::translate("adminwindow", "Season/Time Frame:", 0));
        capacityLabel_2->setText(QApplication::translate("adminwindow", "Min Capacity:", 0));
        leagueEditLabel->setText(QApplication::translate("adminwindow", "League:", 0));
        grassLabel->setText(QApplication::translate("adminwindow", "Grass Type", 0));
        tabWidget->setTabText(tabWidget->indexOf(stadEditTab), QApplication::translate("adminwindow", "Stadium Edit", 0));
        souvenirEditLabel->setText(QApplication::translate("adminwindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Souvenir Edit Table:</span></p></body></html>", 0));
        nameLabel->setText(QApplication::translate("adminwindow", "Item Name:", 0));
        priceLabel->setText(QApplication::translate("adminwindow", "Price:", 0));
        instruction1->setText(QApplication::translate("adminwindow", "1. Select Item To Change", 0));
        instruction2->setText(QApplication::translate("adminwindow", "2. Edit Values", 0));
        updateBtn->setText(QApplication::translate("adminwindow", "Update with Edits", 0));
        addNewBtn->setText(QApplication::translate("adminwindow", "Add New", 0));
        deleteSouv->setText(QApplication::translate("adminwindow", "Delete Selected Item", 0));
        tabWidget->setTabText(tabWidget->indexOf(souvEditTab), QApplication::translate("adminwindow", "Souvenir Edit", 0));
        label->setText(QApplication::translate("adminwindow", "Adjacency Matrix", 0));
        tabWidget->setTabText(tabWidget->indexOf(EdgesEdit), QApplication::translate("adminwindow", "Edges Edit", 0));
        addNewStadBtn->setText(QApplication::translate("adminwindow", "Add New Stadium", 0));
    } // retranslateUi

};

namespace Ui {
    class adminwindow: public Ui_adminwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
