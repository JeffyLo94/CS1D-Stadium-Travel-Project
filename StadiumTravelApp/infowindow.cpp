#include "infowindow.h"
#include "ui_infowindow.h"

infoWindow::infoWindow(QString passing, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoWindow)
{
    ui->setupUi(this);
    ui->label->setText(passing);
}

infoWindow::~infoWindow()
{
    delete ui;
}
