#include "purchase.h"
#include "ui_purchase.h"
#include "stadium.h"
#include <qdebug.h>
#include "endtrip.h"
#include "mainwindow.h"

Purchase::Purchase(QList<Stadium> lamoo, float dist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Purchase)
{
    ui->setupUi(this);

    currStadium = 0;

    totalDist = dist;

    QCheckBox *SouvCheckbox;
    QVBoxLayout *laySouvList;
    QWidget *StadiumWidget;

    names.clear();
    cartPrices.clear();
    cartList.clear();
    scrollAreaListStacked = new QStackedWidget;

    numSouvs = "Number of Souvenirs purchased: 0";
    ui->subtotal_2->setText("Total: $0");

    cartWidget = new QWidget;
    ui->scrollArea_2->setWidget(cartWidget);

    ui->next->setEnabled(true);
    ui->prev_stadium->setEnabled(true);

    for(int c = 0;c < StadiumWidgetList.size();c++)
    {
        scrollAreaListStacked->removeWidget(StadiumWidgetList.at(c));
    }
    ui-> stadiumName->setText(lamoo[0].GetName());

    for (int l = 0; l < lamoo.size(); l++)
    {
        laySouvList = new QVBoxLayout();
        StadiumWidget  = new QWidget;
        names.push_back(lamoo[l].GetName());
        QList<Souvenir> temp;

        lamoo[l].GetSouvenirs(temp);

        for (int sIndex = 0; sIndex < temp.size();sIndex++)
        {
            price = QString::number(temp.at(sIndex).GetPrice());
            SouvCheckbox = new QCheckBox(lamoo[l].GetTeamName() + "\n" + temp.at(sIndex).GetName() + '\n' + "Price: $" + price, this);
            souvPrices.push_back(temp.at(sIndex).GetPrice());
            laySouvList->addWidget(SouvCheckbox);
            StadiumWidget->setLayout(laySouvList);
            SouvCheckBoxList1.push_back(SouvCheckbox);
        }


        scrollAreaListStacked->addWidget(StadiumWidget);

        StadiumWidgetList.push_back(StadiumWidget);

    }

    ui->scrollArea->setWidget(scrollAreaListStacked);

    scrollAreaListStacked->setCurrentIndex(0);
}

Purchase::~Purchase()
{
    delete ui;
    delete scrollAreaListStacked;

}

void Purchase::on_addToCart_clicked()
{
    cartWidget = new QWidget();
    QVBoxLayout *cartLayout = new QVBoxLayout();
    bool atLeastOnce = false;
    QCheckBox   *temp;


    for(int count = 0; count < SouvCheckBoxList1.size(); count++)
    {

        qDebug() << "CURRENT TOTAL";

        if(SouvCheckBoxList1.at(count)->isChecked())
        {


                temp = new QCheckBox(SouvCheckBoxList1.at(count)->text());
                cartList.push_back(temp);
                cartPrices.push_back(souvPrices.at(count));

           atLeastOnce = true;

        }


        SouvCheckBoxList1.at(count)->setChecked(false);
    }


    if (atLeastOnce)
    {

        for(int numCheckBox = 0; numCheckBox < cartList.size(); numCheckBox++)
        {
           cartLayout->addWidget(cartList.at(numCheckBox));
        }

        cartWidget->setLayout(cartLayout);
        ui->scrollArea_2->setWidget(cartWidget);

        intTotal = 0;
        for(int g=0; g<cartPrices.size();g++)
        {
            intTotal = intTotal + cartPrices.at(g);
        }

        ui->subtotal_2->setText("Total: $" + QString::number(intTotal));
    }


}

void Purchase::on_removeFromCart_clicked()
{
    QWidget *cartWidgetUpdated = new QWidget();
    QVBoxLayout *cartLayoutUpdated = new QVBoxLayout();
    bool atLeastOnce = false;


    for(int i = 0; i < cartList.size(); i++)
    {
       if(cartList.at(i)->isChecked())
       {
           atLeastOnce = true;

           cartList.remove(i);
           cartPrices.removeAt(i);
           i--;
       }

    }

     if(atLeastOnce)
     {
         for(int j = 0; j < cartList.size(); j++)
         {
             cartLayoutUpdated->addWidget(cartList.at(j));
         }


         cartWidgetUpdated->setLayout(cartLayoutUpdated);
         ui->scrollArea_2->setWidget(cartWidgetUpdated);

         intTotal = 0;
         for(int g=0; g<cartPrices.size();g++)
         {
             intTotal = intTotal + cartPrices.at(g);
         }


         ui->subtotal_2->setText("Total: $" + QString::number(intTotal));
     }
}

void Purchase::on_next_clicked()
{
    if(currStadium < scrollAreaListStacked->count() - 1)
    {
        currStadium++;

        scrollAreaListStacked->setCurrentIndex(currStadium);

        ui-> stadiumName->setText(names[currStadium]);

        ui->prev_stadium->setEnabled(true);

    }
    else
    {

        ui->next->setEnabled(false);
        EndTrip *endtrip = new EndTrip(intTotal, totalDist, cartList.size());
        endtrip->show();
        this->close();
    }

}

void Purchase::on_prev_stadium_clicked()
{
    if(currStadium > 0)
    {
         currStadium--;

         scrollAreaListStacked->setCurrentIndex(currStadium);

         ui->stadiumName->setText(names[currStadium]);

         ui->next->setEnabled(true);

    }
    else
    {
       ui->prev_stadium->setEnabled(false);
    }

}

void Purchase::on_backToTripType_clicked()
{
    MainWindow *gg = new MainWindow;
    gg->show();
    this->close();

}
