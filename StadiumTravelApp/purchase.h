#ifndef PURCHASE_H
#define PURCHASE_H

#include <QDialog>
#include "QCheckBox"
#include "QVBoxLayout"
#include "qstackedwidget.h"
#include "qlist.h"
#include "stadium.h"

namespace Ui {
class Purchase;
}

class Purchase : public QDialog
{
    Q_OBJECT

public:
    explicit Purchase(QList<Stadium> lamoo, float dist = 0, QWidget *parent = 0);
    ~Purchase();

private slots:
    void on_addToCart_clicked();

    void on_removeFromCart_clicked();

    void on_next_clicked();

    void on_prev_stadium_clicked();

    void on_backToTripType_clicked();

private:
    Ui::Purchase *ui;
    int currStadium;
    QString price;
    QList<double> cartPrices;
    QVector<QCheckBox*> cartList;
    QList<QString> cartNames;
    QList<QString> names;
    QList<double> souvPrices;
    QString numSouvs;
    int     totSouvs;
    double bigTotal;
    double intTotal;
    float   totalDist;
    QWidget *cartWidget = NULL;
    QList<QWidget*> StadiumWidgetList;
    QStackedWidget *scrollAreaListStacked;
    QVector<QCheckBox*> SouvCheckBoxList1;

};



#endif // PURCHASE_H
