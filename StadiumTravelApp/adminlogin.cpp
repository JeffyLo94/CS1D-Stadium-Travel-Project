#include "adminlogin.h"
#include "adminwindow.h"
#include "ui_adminlogin.h"
#include "responsewindow.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_tryLoginBtn_clicked()
{
    //TODO: Check login password
    QString username;
    QString password;
    //Used for admin class
    //Admin*  admin = new Admin("NAN");

    // Gets text from lineEdit object in the GUI
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();

    // Checks if the text input by the user matches the admin login credentials
    if(username == "admin" && (password == "admin" || password == "anthonysux"))
    {
        this->close();

        //admin->SetName("Admin");

        // Declares new admin portal window
        adminwindow* adminPortal = new adminwindow();

        // Displays window
        adminPortal->show();

//        // Declares new response window
//        responseWindow* response;
//        response = new responseWindow(NULL, LOGIN_SUCCESSFUL);
//        // Displays window
//        response->show();
    }
    else
    {
        // Declares new response window
        responseWindow* response;
        response = new responseWindow(NULL, LOGIN_FAILED);
        // Displays window
        response->show();
    }
}
