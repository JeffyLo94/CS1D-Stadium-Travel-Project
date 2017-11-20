/********************************************************************************
** Form generated from reading UI file 'purchase.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASE_H
#define UI_PURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Purchase
{
public:
    QScrollArea *scrollArea;
    QWidget *list_of_souvenir_scroll_area_2;
    QPushButton *addToCart;
    QPushButton *next;
    QPushButton *backToTripType;
    QLabel *subtotal_2;
    QScrollArea *scrollArea_2;
    QWidget *cart_scroll_area_2;
    QPushButton *removeFromCart;
    QLabel *cart;
    QLabel *stadiumName;
    QPushButton *prev_stadium;
    QLabel *labelSouvenir;

    void setupUi(QDialog *Purchase)
    {
        if (Purchase->objectName().isEmpty())
            Purchase->setObjectName(QStringLiteral("Purchase"));
        Purchase->resize(751, 513);
        scrollArea = new QScrollArea(Purchase);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 120, 221, 321));
        scrollArea->setWidgetResizable(true);
        list_of_souvenir_scroll_area_2 = new QWidget();
        list_of_souvenir_scroll_area_2->setObjectName(QStringLiteral("list_of_souvenir_scroll_area_2"));
        list_of_souvenir_scroll_area_2->setGeometry(QRect(0, 0, 219, 319));
        scrollArea->setWidget(list_of_souvenir_scroll_area_2);
        addToCart = new QPushButton(Purchase);
        addToCart->setObjectName(QStringLiteral("addToCart"));
        addToCart->setGeometry(QRect(320, 150, 93, 28));
        next = new QPushButton(Purchase);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(580, 460, 111, 41));
        backToTripType = new QPushButton(Purchase);
        backToTripType->setObjectName(QStringLiteral("backToTripType"));
        backToTripType->setGeometry(QRect(10, 10, 75, 23));
        subtotal_2 = new QLabel(Purchase);
        subtotal_2->setObjectName(QStringLiteral("subtotal_2"));
        subtotal_2->setGeometry(QRect(460, 460, 81, 31));
        scrollArea_2 = new QScrollArea(Purchase);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(470, 120, 221, 321));
        scrollArea_2->setWidgetResizable(true);
        cart_scroll_area_2 = new QWidget();
        cart_scroll_area_2->setObjectName(QStringLiteral("cart_scroll_area_2"));
        cart_scroll_area_2->setGeometry(QRect(0, 0, 219, 319));
        scrollArea_2->setWidget(cart_scroll_area_2);
        removeFromCart = new QPushButton(Purchase);
        removeFromCart->setObjectName(QStringLiteral("removeFromCart"));
        removeFromCart->setGeometry(QRect(310, 240, 111, 28));
        cart = new QLabel(Purchase);
        cart->setObjectName(QStringLiteral("cart"));
        cart->setGeometry(QRect(470, 80, 81, 31));
        stadiumName = new QLabel(Purchase);
        stadiumName->setObjectName(QStringLiteral("stadiumName"));
        stadiumName->setGeometry(QRect(260, 20, 271, 51));
        prev_stadium = new QPushButton(Purchase);
        prev_stadium->setObjectName(QStringLiteral("prev_stadium"));
        prev_stadium->setGeometry(QRect(30, 460, 131, 41));
        labelSouvenir = new QLabel(Purchase);
        labelSouvenir->setObjectName(QStringLiteral("labelSouvenir"));
        labelSouvenir->setGeometry(QRect(40, 80, 81, 31));

        retranslateUi(Purchase);

        QMetaObject::connectSlotsByName(Purchase);
    } // setupUi

    void retranslateUi(QDialog *Purchase)
    {
        Purchase->setWindowTitle(QApplication::translate("Purchase", "Dialog", 0));
        addToCart->setText(QApplication::translate("Purchase", "Add to Cart", 0));
        next->setText(QApplication::translate("Purchase", "Next Stadium", 0));
        backToTripType->setText(QApplication::translate("Purchase", "Back", 0));
        subtotal_2->setText(QApplication::translate("Purchase", "TextLabel", 0));
        removeFromCart->setText(QApplication::translate("Purchase", "Remove from Cart", 0));
        cart->setText(QApplication::translate("Purchase", "Cart", 0));
#ifndef QT_NO_TOOLTIP
        stadiumName->setToolTip(QApplication::translate("Purchase", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        stadiumName->setText(QApplication::translate("Purchase", "TextLabel", 0));
        prev_stadium->setText(QApplication::translate("Purchase", "Previous Stadium", 0));
        labelSouvenir->setText(QApplication::translate("Purchase", "List of Souvenirs", 0));
    } // retranslateUi

};

namespace Ui {
    class Purchase: public Ui_Purchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASE_H
