#include "endtrip.h"
#include "ui_endtrip.h"
#include "mainwindow.h"

EndTrip::EndTrip(double bigTotal, float dist, int souvs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndTrip)
{
    ui->setupUi(this);
    if (dist != 0)
    {
        ui->distance->setText(QString().append("You traveled ").append(QString().number(dist)).append(" miles!"));
    }
    ui->numStadiums->setText(QString().append("You Purchased ").append(QString().number(souvs)).append(" souvenirs for a total of $").append(QString().number(bigTotal)));

}

EndTrip::~EndTrip()
{
    delete ui;
}

void EndTrip::on_mainMenu_clicked()
{
    MainWindow *gg = new MainWindow;
    gg->show();
    this->close();
}

void EndTrip::on_exit_clicked()
{
    this->close();
}
