#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QtSql/QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QtSql/QSqlError>
#include "mainwindow.h"
#include "ui_adminwindow.h"
#include <QDebug>
#include "responsewindow.h"

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = 0);
    ~adminwindow();

private slots:
//    void on_editStadiumBtn_clicked();

//    void on_editSouvenirsBtn_clicked();

    void on_backBtn_clicked();

    void on_leagueSelectComboBox_currentIndexChanged(int index);

    void on_addStadBtn_clicked();

    void on_stadiumSelectWidget_itemClicked(QListWidgetItem *item);

    void on_countryComboBox_currentIndexChanged(int index);

    void on_saveBtn_clicked();

    void on_updateBtn_clicked();

    void on_addNewBtn_clicked();

    void on_deleteSouv_clicked();

    void on_addNewStadBtn_clicked();

private:
    void FillStateComboBox(bool isUS );
    void destroySouvTable();
    void createSouvTable();
    void createAdjMatrix();

    Ui::adminwindow *ui;
    QSqlDatabase db;
    QList<Stadium> amLeague;
    QList<Stadium> ntLeague;
    QStringList amStrList;
    QStringList ntStrList;

    QStringList usList;
    QStringList canList;
};

#endif // ADMINWINDOW_H
