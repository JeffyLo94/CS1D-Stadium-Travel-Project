#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminlogin.h"
#include "userselectionwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Database
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("stadiumproject");
    db.setUserName("root");
    db.setPassword("");
    if(db.open())
    {
        qDebug() << "Database connection established!\n";
    }
    else
    {
        qDebug() << "Database connection failed!\n";
    }

    //Test Stubs for the Graph
    QString names[30] = {"Angels Stadium of Anaheim",  //0
                         "Comercia Park",//1
                         "Fenway Park", //2
                         "Globe Life Park in Arlington",   //3
                         "Kauffman Stadium", //4
                         "Minute Maid Park",  //5
                         "O.co Coliseum",//6
                         "Oriole Park at Camden Yards",  //7
                         "Progressive Field",  //8
                         "Rogers Centre",//9
                         "SafeCo Field",//10
                         "Target Field",
                         "Tropicana Field",
                         "US Celllar Field",
                         "Yankee Stadium",
                         "AT&T Park",
                         "Busch Stadium",
                         "Chase Field",
                         "Citi Field",
                         "Citizens Bank Park",
                         "Coors Field",
                         "Dodger Stadium",
                         "Great America Ball Park",
                         "Marlins Park",
                         "Miller Park",
                         "Nationals Park",
                         "Petco Park",
                         "PNC Park",
                         "Turner Field",
                         "Wrigley Field"}; //11

//       Date* tempdate;
//       Stadium* temp;
//       for(int i = 0;i < 12;i++){
//           if((i%2) == 0){
//               tempdate = new Date(i,i,i);
//               temp = new Stadium(i,names[i]+"StadiumName",names[i]+"TeamName",
//                             names[i]+"Address",names[i]+"City",
//                             names[i]+"State",names[i]+"Zip",
//                             names[i]+"Country",true,names[i]+"PhoneNum",
//                             "11/11/11",i*100,i*10,"national");
//           graph.addVertex(*temp);
//           }
//           else{
//               tempdate = new Date(i+2,i+2,i+3);
//               temp = new Stadium(i,names[i]+"StadiumName",names[i]+"TeamName",
//                             names[i]+"Address",names[i]+"City",
//                             names[i]+"State",names[i]+"Zip",
//                             names[i]+"Country",false,names[i]+"PhoneNum",
//                             "12/12/12",i*200,i*20,"american");
//               graph.addVertex(*temp);
//           }
//       }

//        //From Boston
//        graph.addEdge(0,1,214);
//        graph.addEdge(0,7,983);
//        //From New York
//        graph.addEdge(1,2,888);
//        graph.addEdge(1,6,1260);
//        graph.addEdge(1,7,787);
//        //From Atlanta
//        graph.addEdge(2,3,661);
//        graph.addEdge(2,4,810);
//        graph.addEdge(2,6,864);
//        //From Miami
//        graph.addEdge(3,4,1187);
//        //From Houston
//        graph.addEdge(4,5,239);
//        //From Dallas
//        graph.addEdge(5,2,781);
//        graph.addEdge(5,6,496);
//        graph.addEdge(5,11,1435);
//        //From Kansas City
//        graph.addEdge(6,7,533);
//        graph.addEdge(6,8,599);
//        graph.addEdge(6,11,1663);
//        //From Chicago
//        graph.addEdge(7,9,2097);
//        graph.addEdge(7,8,1003);
//        //From Denver
//        graph.addEdge(8,9,1331);
//        graph.addEdge(8,10,1267);
//        graph.addEdge(8,11,1015);
//        //From Seattle
//        graph.addEdge(9,10,807);
//        //From San Fran
//        graph.addEdge(10,11,381);

    QSqlQuery query2(db);
   query2.prepare("SELECT * FROM stadium");
   query2.exec();
   int num = query2.size();

   graph.SetVertNum(num);

    QSqlQuery query(db);
    QSqlRecord record;
    query.prepare("SELECT * FROM edges");
    query.exec();
    query.first();

    record = query.record();

    int** matrix = new int*[query.size()];
    for(int index = 0; index < query.size(); index++)
    {
        matrix[index] = new int[record.count() - 1];
    }

    int index = 0;
    while(query.isValid())
    {
        for(int kndex = 0; kndex < record.count(); kndex++)
        {
            matrix[index][kndex] = query.record().value(kndex + 1).toInt();
        }

        query.next();
        index++;
    }
    graph.SetMatrix(matrix);
    query.prepare("SELECT * FROM stadium");
    query.exec();
    query.first();

    record = query.record();
    Stadium* newStadium = new Stadium();

    while(query.isValid())
    {
        newStadium->SetName(query.record().value(0).toString());
        newStadium->SetId(query.record().value(1).toInt());
        newStadium->SetTeamName(query.record().value(2).toString());
        newStadium->SetAddress(query.record().value(3).toString(), query.record().value(4).toString(), query.record().value(5).toString(), query.record().value(7).toString(), query.record().value(6).toString());
        newStadium->SetPhone(query.record().value(8).toString());
        newStadium->SetOpenDate(query.record().value(9).toString());
        newStadium->SetCapacity(query.record().value(10).toInt());
        newStadium->SetCapFrame(query.record().value(11).toString());
        newStadium->SetMin(query.record().value(12).toInt());
        newStadium->SetMinFrame(query.record().value(13).toString());
        if(query.record().value(14).toString() == "Grass")
        {
            newStadium->SetGrass(1);
        }
        else
        {
            newStadium->SetGrass(0);
        }
        newStadium->SetLeague(query.record().value(15).toString());

        QSqlQuery query2(db);
        query2.prepare("SELECT * FROM souvenirs WHERE stadiumID = :id");
        query2.bindValue(":id", query.record().value(1).toInt());
        query2.exec();
        query2.first();
        qDebug() << query2.size();
        for(int kndex = 0; kndex < query2.size(); kndex++)
        {
            Souvenir temp;
//            qDebug() << query2.record().value(0).toString();
            temp.SetAll(query2.record().value(0).toString(), query2.record().value(1).toDouble());
            newStadium->AddSouvenir(temp);
            query2.next();
        }
        query.next();
        graph.addVertex(*newStadium);
        newStadium = new Stadium();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_adminButton_clicked()
{
    AdminLogin* temp = new AdminLogin;
    temp->show();
    this->close();
}


void MainWindow::on_chooseEndButton_clicked()
{
    UserSelectionWindow* temp = new UserSelectionWindow("chooseEnd",graph);
    temp->show();
    this->close();
}

void MainWindow::on_dreamButton_clicked()
{
    UserSelectionWindow* temp = new UserSelectionWindow("dream",graph);
    temp->show();
    this->close();
}

void MainWindow::on_chooseStartButton_clicked()
{
    UserSelectionWindow* temp = new UserSelectionWindow("chooseStart",graph);
    temp->show();
    this->close();
}
