#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include "stadium.h"
#include "graph.h"
#include "date.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_adminButton_clicked();

    void on_chooseEndButton_clicked();

    void on_dreamButton_clicked();

    void on_chooseStartButton_clicked();

private:
    Ui::MainWindow *ui;
    Graph<Stadium,int> graph;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
