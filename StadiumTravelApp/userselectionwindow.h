#ifndef USERSELECTIONWINDOW_H
#define USERSELECTIONWINDOW_H

#include <QDialog>
#include "graph.h"
#include "stadium.h"


namespace Ui {
class UserSelectionWindow;
}

class UserSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserSelectionWindow(QWidget *parent = 0);
    UserSelectionWindow(QString typeOfSearch,Graph<Stadium,int> newgraph,QWidget *parent = 0);
    ~UserSelectionWindow();

private slots:

    void on_backButton_clicked();

    void on_goOnATripButton_clicked();

    void on_removeButton_clicked();

    void on_addButton_clicked();

    void on_onlyNationalButton_clicked();

    void on_onlyAmericanButton_clicked();

    void on_onlyGrassButton_clicked();

    void on_noGrassButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserSelectionWindow *ui;
    Graph<Stadium,int> graph;
    QString searchType;
    int numberOfRows;
};

#endif // USERSELECTIONWINDOW_H
