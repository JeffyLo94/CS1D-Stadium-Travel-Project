/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminLogin
{
public:
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *tryLoginBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *AdminLogin)
    {
        if (AdminLogin->objectName().isEmpty())
            AdminLogin->setObjectName(QStringLiteral("AdminLogin"));
        AdminLogin->resize(704, 323);
        frame = new QFrame(AdminLogin);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(19, 19, 661, 211));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 81, 41));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 130, 71, 41));
        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setGeometry(QRect(240, 40, 361, 41));
        passwordEdit = new QLineEdit(frame);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(240, 130, 361, 41));
        passwordEdit->setEchoMode(QLineEdit::Password);
        tryLoginBtn = new QPushButton(AdminLogin);
        tryLoginBtn->setObjectName(QStringLiteral("tryLoginBtn"));
        tryLoginBtn->setGeometry(QRect(70, 250, 221, 51));
        cancelBtn = new QPushButton(AdminLogin);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(410, 250, 221, 51));

        retranslateUi(AdminLogin);

        QMetaObject::connectSlotsByName(AdminLogin);
    } // setupUi

    void retranslateUi(QDialog *AdminLogin)
    {
        AdminLogin->setWindowTitle(QApplication::translate("AdminLogin", "Dialog", 0));
        label->setText(QApplication::translate("AdminLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">Username:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("AdminLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">Password:</span></p></body></html>", 0));
        tryLoginBtn->setText(QApplication::translate("AdminLogin", "Login", 0));
        cancelBtn->setText(QApplication::translate("AdminLogin", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminLogin: public Ui_AdminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
