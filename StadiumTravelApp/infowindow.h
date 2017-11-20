#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QDialog>

namespace Ui {
class infoWindow;
}

class infoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit infoWindow(QString passing, QWidget *parent = 0);
    ~infoWindow();

private:
    Ui::infoWindow *ui;
};

#endif // INFOWINDOW_H
