#ifndef ENDTRIP_H
#define ENDTRIP_H

#include <QDialog>

namespace Ui {
class EndTrip;
}

class EndTrip : public QDialog
{
    Q_OBJECT

public:
    explicit EndTrip(double bigTotal, float dist, int souvs, QWidget *parent = 0);
    ~EndTrip();

private slots:
    void on_mainMenu_clicked();

    void on_exit_clicked();

private:
    Ui::EndTrip *ui;
};

#endif // ENDTRIP_H
