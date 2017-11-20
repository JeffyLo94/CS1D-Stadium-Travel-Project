#include "userselectionwindow.h"
#include "ui_userselectionwindow.h"
#include "QDebug"
#include "mainwindow.h"
#include "graph2.h"
#include "graph3.h"
#include "purchase.h"
#include "infowindow.h"

UserSelectionWindow::UserSelectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSelectionWindow)
{
    ui->setupUi(this);

    //819 is the total width of the table widge
    ui->allStadiumsTableWidget->setColumnWidth(0,163);
    ui->allStadiumsTableWidget->setColumnWidth(1,163);
    ui->allStadiumsTableWidget->setColumnWidth(2,163);
    ui->allStadiumsTableWidget->setColumnWidth(3,163);
    ui->allStadiumsTableWidget->setColumnWidth(4,167);
}

UserSelectionWindow::UserSelectionWindow(QString typeOfSearch,Graph<Stadium,int> newgraph,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSelectionWindow)
{
    ui->setupUi(this);

     QStringList* stringList = new QStringList;
     stringList->append("Team Name");
     stringList->append("Stadium Name");
     stringList->append("League");
     stringList->append("Date Opened");
     stringList->append("Grass");
    ui->allStadiumsTableWidget->setHorizontalHeaderLabels(*stringList);
    graph = newgraph;
    Stadium* vertList = graph.GetUnsortedVertList();
    ui->allStadiumsTableWidget->setColumnCount(5);
    ui->allStadiumsTableWidget->setRowCount(100);
    ui->allStadiumsTableWidget->sortByColumn(0);
    //819 is the total width of the table widge
    ui->allStadiumsTableWidget->setColumnWidth(0,163);
    ui->allStadiumsTableWidget->setColumnWidth(1,163);
    ui->allStadiumsTableWidget->setColumnWidth(2,163);
    ui->allStadiumsTableWidget->setColumnWidth(3,163);
    ui->allStadiumsTableWidget->setColumnWidth(4,167);

    ui->mileageLabel->setText(QString::number(primMST(graph.GetMatrix())));


    numberOfRows = 0;
    QTableWidgetItem *temp;
    for(int i = 0; i < graph.GetTotVerts();i++){
        ui->allStadiumsTableWidget->setRowCount(i + 1);
        temp = new QTableWidgetItem;
        temp->setText(vertList[i].GetTeamName());
        ui->allStadiumsTableWidget->setItem(i,0,temp);
        temp = new QTableWidgetItem;
        temp->setText(vertList[i].GetName());
        ui->allStadiumsTableWidget->setItem(i,1,temp);

        temp = new QTableWidgetItem;
        QString text;
        if(vertList[i].GetLeague() == "AM")
        {
            text = "American League";
        }
        else
        {
            text = "National League";
        }
        temp->setText(text);
        ui->allStadiumsTableWidget->setItem(i,2,temp);

        temp = new QTableWidgetItem;
        temp->setText(vertList[i].GetOpenDate());
        ui->allStadiumsTableWidget->setItem(i,3,temp);

        temp = new QTableWidgetItem;
        if(vertList[i].GetGrass())
        {
            text = "Grass";
        }
        else
        {
            text = "Astro Turf";
        }
        temp->setText(text);
        ui->allStadiumsTableWidget->setItem(i,4,temp);
        numberOfRows++;
    }

    if(typeOfSearch != "dream"){
        ui->addButton->hide();
        ui->removeButton->hide();
        ui->selectedStadiumsListWidget->hide();
        this->resize(900,710);
        ui->backButton->move(770,680);
    }
    searchType = typeOfSearch;
    ui->hiddenLabel->hide();
    if (typeOfSearch != "chooseEnd")
    {
        ui->hiddenLabel->show();
    }
}

UserSelectionWindow::~UserSelectionWindow()
{
    delete ui;
}


void UserSelectionWindow::on_backButton_clicked()
{
    MainWindow* temp = new MainWindow;
    temp->show();
    this->close();
}

void UserSelectionWindow::on_goOnATripButton_clicked()
{
    if(searchType == "dream"){
        if(ui->selectedStadiumsListWidget->selectedItems().size() != 0){
            Stadium startPoint;
            QListWidgetItem* temp3  = ui->selectedStadiumsListWidget->selectedItems().front();

            Stadium* vertList = graph.GetUnsortedVertList();
            bool found = false;
            int i = 0;
            while(!found&& i<graph.GetTotVerts()){
                if(vertList[i].GetTeamName() == temp3->text()){
                    found = true;
                }else{
                    i++;
                }
            }
            startPoint = vertList[i];


            graph.Dijkstras(i);
            Stadium* fullSortedList = graph.GetSortedVertList();


            QList<QListWidgetItem*> temp1;
            for(i = 0; i <ui->selectedStadiumsListWidget->count();i++){
                temp1.append(ui->selectedStadiumsListWidget->item(i));
            }

            QList<Stadium> temp2;

            for(i = 0; i< graph.GetTotVerts();i++){
                for(int j = 0; j<temp1.size();j++){

                    if(fullSortedList[i].GetTeamName() == ui->selectedStadiumsListWidget->item(j)->text()){
                        temp2.push_back(fullSortedList[i]);
                    }
                }
            }

            float distance = 0;
            qDebug() << "size " << temp2.size();
            for (int index = 0; index < temp2.size()-1; index++)
            {
                distance += (graph.GetMatrix())[temp2.at(index).GetId()][temp2.at(index+1).GetId()];
                qDebug() << (graph.GetMatrix())[temp2.at(index).GetId()][temp2.at(index+1).GetId()];
            }

            int* fuck = new int[temp2.size()];
            for(int i = 0; i < temp2.size();i++){
                fuck[i] = temp2.at(i).GetId();
            }
            distance = graph.Dream(fuck,temp2.size());

            qDebug() << distance;
            Purchase *purchase = new Purchase(temp2, distance);
            purchase->show();
            this->close();
        }
    }
    else if(searchType == "chooseStart")
    {
        int rowId = ui->allStadiumsTableWidget->selectedItems().front()->row();
        graph.Dijkstras(rowId);
       Stadium* fullSortedList = graph.GetSortedVertList();

        QList<Stadium> temp2;

        for(int i = 0; i< graph.GetTotVerts();i++){
            temp2.push_back(fullSortedList[i]);
        }

        Purchase* purchase = new Purchase(temp2);
        purchase->show();
        this->close();

    }
    else
    {
        if(ui->allStadiumsTableWidget->selectedItems().size() != 0)
        {
            Graph2<int> temp(graph.GetTotVerts());
            temp.setNames(graph.GetUnsortedVertList());
            temp.setMatrix(graph.GetMatrix());

            Stadium* temp2 = graph.GetUnsortedVertList();
            int i = 0;
            while(temp2[i].GetTeamName() != "Los Angeles Angels of Anaheim")
            {//"Los Angeles Angels of Anaheim"){
                i++;
            }

            int j = 0;
            while(temp2[j].GetTeamName() != ui->allStadiumsTableWidget->selectedItems().front()->text()){
                j++;
            }

            QList<Stadium> passingThis = temp.PathFromXtoY(i,j);
            int distanceToPass = temp.GetDistance(j);

            Purchase *purchase = new Purchase(passingThis,distanceToPass);
            qDebug() << "here\n";

            purchase->show();
            this->close();
        }
    }
}

void UserSelectionWindow::on_removeButton_clicked()
{
    if(ui->selectedStadiumsListWidget->selectedItems().length() != 0){
        QList<QListWidgetItem*> list = ui->selectedStadiumsListWidget->selectedItems();
        ui->selectedStadiumsListWidget->setCurrentItem(list.front());
        QString temp1 = ui->selectedStadiumsListWidget->currentItem()->text();
        delete ui->selectedStadiumsListWidget->takeItem(ui->selectedStadiumsListWidget->currentRow());


        Stadium* vertList = graph.GetUnsortedVertList();
        bool found = false;
        int i = 0;
        while(!found&& i<graph.GetTotVerts()){
            if(vertList[i].GetTeamName() == temp1){
                found = true;
                qDebug() << "found" << endl;
            }else{
                i++;
            }
        }

        if(found){
            QTableWidgetItem *temp = new QTableWidgetItem;
            temp->setText(vertList[i].GetTeamName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,0,temp);
            temp = new QTableWidgetItem;
            temp->setText(vertList[i].GetName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,1,temp);
            temp= new QTableWidgetItem;
            temp->setText(vertList[i].GetLeague());
            ui->allStadiumsTableWidget->setItem(numberOfRows,2,temp);
            temp = new QTableWidgetItem;
            temp->setText(vertList[i].GetOpenDate());
            ui->allStadiumsTableWidget->setItem(numberOfRows,3,temp);
            numberOfRows++;
        }
    }
}

void UserSelectionWindow::on_addButton_clicked()
{
    if(ui->allStadiumsTableWidget->selectedItems().length() != 0){
        QList<QTableWidgetItem*> list = ui->allStadiumsTableWidget->selectedItems();
        ui->allStadiumsTableWidget->setCurrentItem(list.front());
        QTableWidgetItem* temp = list.front();
        QTableWidgetItem* temp2 = new QTableWidgetItem;
        ui->allStadiumsTableWidget->setCurrentCell(ui->allStadiumsTableWidget->currentRow(),0);
        temp2->setText(ui->allStadiumsTableWidget->currentItem()->text());
        ui->allStadiumsTableWidget->removeRow(ui->allStadiumsTableWidget->currentRow());
        ui->selectedStadiumsListWidget->addItem(temp2->text());
        numberOfRows--;
    }
}

void UserSelectionWindow::on_onlyNationalButton_clicked()
{
    QStringList* stringList = new QStringList;
    stringList->append("Team Name");
    stringList->append("Stadium Name");
    stringList->append("League");
    stringList->append("Date Opened");
    stringList->append("Grass");
   ui->allStadiumsTableWidget->setHorizontalHeaderLabels(*stringList);
    ui->allStadiumsTableWidget->clear();
    ui->selectedStadiumsListWidget->clear();
//    ui->allStadiumsTableWidget->sortByColumn(0,Qt::AscendingOrder);
    numberOfRows = 0;
    QTableWidgetItem *temp;
    Stadium* temp1 = graph.GetUnsortedVertList();
    for(int i = 0; i < graph.GetTotVerts();i++){
        if(temp1[i].GetLeague() == "NL"){
            temp = new QTableWidgetItem;

            temp->setText(temp1[i].GetTeamName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,0,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,1,temp);
            temp= new QTableWidgetItem;
            temp->setText(temp1[i].GetLeague());
            ui->allStadiumsTableWidget->setItem(numberOfRows,2,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetOpenDate());
            ui->allStadiumsTableWidget->setItem(numberOfRows,3,temp);
            numberOfRows++;
        }
    }

}

void UserSelectionWindow::on_onlyAmericanButton_clicked()
{
    QStringList* stringList = new QStringList;
    stringList->append("Team Name");
    stringList->append("Stadium Name");
    stringList->append("League");
    stringList->append("Date Opened");
    stringList->append("Grass");
   ui->allStadiumsTableWidget->setHorizontalHeaderLabels(*stringList);
    ui->allStadiumsTableWidget->clear();
    ui->selectedStadiumsListWidget->clear();
//    ui->allStadiumsTableWidget->sortByColumn(0,Qt::AscendingOrder);
    numberOfRows = 0;
    QTableWidgetItem *temp;
    Stadium* temp1 = graph.GetUnsortedVertList();
    for(int i = 0; i < graph.GetTotVerts();i++){
        if(temp1[i].GetLeague() == "AM"){
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetTeamName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,0,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,1,temp);
            temp= new QTableWidgetItem;
            temp->setText(temp1[i].GetLeague());
            ui->allStadiumsTableWidget->setItem(numberOfRows,2,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetOpenDate());
            ui->allStadiumsTableWidget->setItem(numberOfRows,3,temp);
            numberOfRows++;
        }
    }
}

void UserSelectionWindow::on_onlyGrassButton_clicked()
{
    QStringList* stringList = new QStringList;
    stringList->append("Team Name");
    stringList->append("Stadium Name");
    stringList->append("League");
    stringList->append("Date Opened");
    stringList->append("Grass");
   ui->allStadiumsTableWidget->setHorizontalHeaderLabels(*stringList);
    ui->allStadiumsTableWidget->clear();
    ui->selectedStadiumsListWidget->clear();
//    ui->allStadiumsTableWidget->sortByColumn(0,Qt::AscendingOrder);
    numberOfRows = 0;
    QTableWidgetItem *temp;
    Stadium* temp1 = graph.GetUnsortedVertList();
    for(int i = 0; i < graph.GetTotVerts();i++){
        if(temp1[i].GetGrass() == true){
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetTeamName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,0,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,1,temp);
            temp= new QTableWidgetItem;
            temp->setText(temp1[i].GetLeague());
            ui->allStadiumsTableWidget->setItem(numberOfRows,2,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetOpenDate());
            ui->allStadiumsTableWidget->setItem(numberOfRows,3,temp);
            numberOfRows++;
        }
    }
}

void UserSelectionWindow::on_noGrassButton_clicked()
{
    QStringList* stringList = new QStringList;
    stringList->append("Team Name");
    stringList->append("Stadium Name");
    stringList->append("League");
    stringList->append("Date Opened");
    stringList->append("Grass");
   ui->allStadiumsTableWidget->setHorizontalHeaderLabels(*stringList);
    ui->allStadiumsTableWidget->clear();
    ui->selectedStadiumsListWidget->clear();
//    ui->allStadiumsTableWidget->sortByColumn(0,Qt::AscendingOrder);
    numberOfRows = 0;
    QTableWidgetItem *temp;
    Stadium* temp1 = graph.GetUnsortedVertList();
    for(int i = 0; i < graph.GetTotVerts();i++){
        if(temp1[i].GetGrass() != true){
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetTeamName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,0,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetName());
            ui->allStadiumsTableWidget->setItem(numberOfRows,1,temp);
            temp= new QTableWidgetItem;
            temp->setText(temp1[i].GetLeague());
            ui->allStadiumsTableWidget->setItem(numberOfRows,2,temp);
            temp = new QTableWidgetItem;
            temp->setText(temp1[i].GetOpenDate());
            ui->allStadiumsTableWidget->setItem(numberOfRows,3,temp);
            numberOfRows++;
        }
    }
}

void UserSelectionWindow::on_pushButton_clicked()
{
    if(ui->allStadiumsTableWidget->selectedItems().size() != 0)
       {
           QList<QTableWidgetItem*> list = ui->allStadiumsTableWidget->selectedItems();
           ui->allStadiumsTableWidget->setCurrentItem(list.front());
           QTableWidgetItem* temp = list.front();

           Stadium* vertList = graph.GetUnsortedVertList();
           bool found = false;
           int i = 0;
           while(!found&& i<graph.GetTotVerts()){
               if(vertList[i].GetTeamName() == temp->text()){
                   found = true;
                   qDebug() << "found" << endl;
               }else{
                   i++;
               }
           }

           QString passing = vertList[i].GetName() + '\n' + vertList[i].GetTeamName() + '\n' +
                             vertList[i].GetAddress() + ",  " + vertList[i].GetCity() + "  " +
                             vertList[i].GetZip() + "  " + vertList[i].GetCountry() + '\n' +
                             "Min seating - " + QString::number(vertList[i].GetMin()) + '\n' + "Max seating - " +
                              QString::number(vertList[i].GetCapacity()) + '\n' + vertList[i].GetPhone() + '\n' +
                              "Open date - " + vertList[i].GetOpenDate() + '\n' + vertList[i].GetLeague();
           infoWindow *bla = new infoWindow(passing);
           bla->show();
       }
}
