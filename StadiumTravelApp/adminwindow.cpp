#include "adminwindow.h"
#include "ui_adminwindow.h"

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
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

    QSqlQuery query1(db);
    query1.prepare("SELECT * FROM stadium");
    query1.exec();
    qDebug() << query1.size();


    QSqlQuery query(db);
    QSqlRecord record;

    query.prepare("SELECT * FROM stadium");
    query.exec();
    query.first();

    record = query.record();
    Stadium* newStadium = new Stadium();

    //Creating Stadiums
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
        query2.bindValue(":id", query2.record().value(1).toInt());
        query2.exec();
        query2.first();

        for(int kndex = 0; kndex < query2.size(); kndex++)
        {
            Souvenir temp;
            temp.SetAll(query2.record().value(0).toString(), query2.record().value(1).toDouble());
            newStadium->AddSouvenir(temp);
            query2.next();
        }
        query.next();

        //TODO: Code to add stadium to appropriate league list
        if(newStadium->GetLeague() == "AM"){
            amLeague.push_back(*newStadium);
            amStrList.push_back(newStadium->GetName());
        }
        else{
            ntLeague.push_back(*newStadium);
            ntStrList.push_back(newStadium->GetName());
        }

        newStadium = new Stadium();
    }

    QStringList list;
    list << "-- Select Legue --"
         << "American League"
         << "National League";

    ui->leagueSelectComboBox->clear();
    ui->leagueSelectComboBox->addItems(list);

    usList.clear();
    usList << ""
           << "AL" << "AK" << "AZ" << "AR" << "CA" << "CO" << "CT"
           << "DE" << "FL" << "GA" << "HI" << "ID" << "IL" << "IN"
           << "IA" << "KS" << "KY" << "LA" << "ME" << "MD" << "MA"
           << "MI" << "MN" << "MS" << "MO" << "MT" << "NE" << "NV"
           << "NJ" << "NM" << "NY" << "NC" << "ND" << "OH" << "OK"
           << "OR" << "PA" << "RI" << "SC" << "SD" << "TN" << "TX"
           << "UT" << "VT" << "VA" << "WA" << "WV" << "WI" << "WY"
           << "DC";

    canList.clear();
    canList << ""
            << "AB" << "BC" << "MB" << "NB" << "NL" << "NS" << "NT"
            << "NU" << "ON" << "PE" << "QC" << "SK" << "YT";

    //Disable button
    ui->addNewStadBtn->hide();

    //Connecting Signal and slot
    connect(ui->leagueSelectComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_leagueSelectComboBox_currentIndexChanged(int)) );
    connect(ui->stadiumSelectWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(on_stadiumSelectWidget_itemClicked(QListWidgetItem*)) );
    connect(ui->countryComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_countryComboBox_currentIndexChanged(int)));
}

adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_backBtn_clicked()
{    
    MainWindow *temp = new MainWindow();
    this->hide();
    temp->show();
}

void adminwindow::on_leagueSelectComboBox_currentIndexChanged(int index)
{
    //Disable button
    ui->addNewStadBtn->hide();

    ui->stadiumSelectWidget->clear();
    if(index > 0){
        if(index == 1){
            ui->stadiumSelectWidget->addItems(amStrList);
        }
        else{
            ui->stadiumSelectWidget->addItems(ntStrList);
        }
    }
}

void adminwindow::on_addStadBtn_clicked()
{
    ui->leagueSelectComboBox->setCurrentIndex(0);

    QStringList list;
    list << "-- Select Legue --"
         << "American League"
         << "National League";

    ui->leagueEditComboBox->clear();
    ui->leagueEditComboBox->addItems(list);

    QStringList country;
    country << "" << "US" << "Canada";
    ui->countryComboBox->clear();
    ui->countryComboBox->addItems(country);

    QStringList grass;
    grass << "" << "Grass" << "Astro Turf";
    ui->grassEdit->clear();
    ui->grassEdit->addItems(grass);

    //Stadium Page Fields
    ui->leagueEditComboBox->setCurrentIndex(0);
    ui->stadNameEdit->clear();
    ui->teamNameEdit->clear();
    ui->streetAddressEdit->clear();
    ui->cityNameEdit->clear();
    ui->countryComboBox->setCurrentIndex(0);
    ui->stateComboBox->setCurrentIndex(0);
    ui->zipCodeEdit->clear();
    ui->phoneNumEdit->clear();
    ui->grassEdit->setCurrentIndex(0);
    ui->dateEdit->clear();
    ui->maxCapacity->clear();
    ui->maxCapacityFrameEdit->clear();
    ui->minCapacity->clear();
    ui->minCapacityFrameEdit->clear();

    ui->addNewStadBtn->show();
}

void adminwindow::FillStateComboBox(bool isUS){
    if(isUS){
        ui->stateComboBox->clear();
        ui->stateComboBox->addItems(usList);
    }
    else{
        ui->stateComboBox->clear();
        ui->stateComboBox->addItems(canList);
    }
}

void adminwindow::on_stadiumSelectWidget_itemClicked(QListWidgetItem *item)
{
    //Disable button
    ui->addNewStadBtn->hide();

    bool isUS;
    int currRow = ui->stadiumSelectWidget->currentRow();
    int stateNum;

    QStringList list;
    list << "-- Select Legue --"
         << "American League"
         << "National League";

    ui->leagueEditComboBox->clear();
    ui->leagueEditComboBox->addItems(list);

    QStringList country;
    country << "" << "US" << "Canada";
    ui->countryComboBox->clear();
    ui->countryComboBox->addItems(country);

    QStringList grass;
    grass << "" << "Grass" << "Astro Turf";
    ui->grassEdit->clear();
    ui->grassEdit->addItems(grass);

    //Stadium Page Fields
    Stadium selectedStad;
    if(ui->leagueSelectComboBox->currentIndex() == 1){
        ui->leagueEditComboBox->setCurrentIndex(1);
        selectedStad = amLeague.at(currRow);
    }
    else{
        ui->leagueEditComboBox->setCurrentIndex(2);
        selectedStad = ntLeague.at(currRow);
    }
    ui->stadNameEdit->setText(selectedStad.GetName());
    ui->teamNameEdit->setText(selectedStad.GetTeamName());
    ui->streetAddressEdit->setText(selectedStad.GetAddress());
    ui->cityNameEdit->setText(selectedStad.GetCity());
    if(selectedStad.GetCountry() == "US"){
        ui->countryComboBox->setCurrentIndex(1);
        isUS = true;
        stateNum = usList.indexOf(selectedStad.GetState());
    }
    else{
        ui->countryComboBox->setCurrentIndex(2);
        isUS = false;
        stateNum = canList.indexOf(selectedStad.GetState());
    }
    FillStateComboBox(isUS);
    if(stateNum != -1){
        ui->stateComboBox->setCurrentIndex(stateNum);
    }
    else{
        qDebug() << "Error - state num -1" << endl;
    }
    ui->zipCodeEdit->setText(selectedStad.GetZip());
    ui->phoneNumEdit->setText(selectedStad.GetPhone());
    if(selectedStad.GetGrass() == true){
        ui->grassEdit->setCurrentIndex(1);
    }
    else{
        ui->grassEdit->setCurrentIndex(2);
    }
    ui->dateEdit->setText(selectedStad.GetOpenDate());
    ui->maxCapacity->setText(QString::number(selectedStad.GetCapacity()));
    ui->maxCapacityFrameEdit->setText(selectedStad.GetMaxFrame());
    ui->minCapacity->setText(QString::number(selectedStad.GetMin()));
    ui->minCapacityFrameEdit->setText(selectedStad.GetMinFrame());

    //Souvineer
//    QSqlQuery souvQuery;
//    souvQuery.prepare("SELECT * FROM souvenirs");
//    //souvQuery.bindValue(":id", selectedStad.GetId());
//    qDebug() << selectedStad.GetId() << endl;
//    souvQuery.exec();
//    souvQuery.first();

    this->createSouvTable();

    this->createAdjMatrix();

}

void adminwindow::on_countryComboBox_currentIndexChanged(int index)
{
    if(index > 0){
        if(index == 1){
            FillStateComboBox(true);
        }
        else{
            FillStateComboBox(false);
        }
    }
}

void adminwindow::on_saveBtn_clicked()
{
    bool hasFailed;
    bool isUS;
    int currRow = ui->stadiumSelectWidget->currentRow();
    int stateNum;
    responseWindow* response;

    //Stadium Page Fields
    Stadium selectedStad;
    if(ui->leagueSelectComboBox->currentIndex() == 1){
        selectedStad = amLeague.at(currRow);
    }
    else{
        selectedStad = ntLeague.at(currRow);
    }

    int LeagDex = ui->leagueEditComboBox->currentIndex();
    if(LeagDex == 0){
        hasFailed = true;
        // Declares new response window
        response = new responseWindow(NULL, LEAGUE_SELECT);
    }
    else if(ui->countryComboBox->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, COUNTRY_SELECT);
    }
    else if(ui->stateComboBox->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, STATE_SELECT);
    }
    else if(ui->grassEdit->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, GRASS_SELECT);
    }

    if(hasFailed){
        // Displays window
        response->show();
    }
    else{
        selectedStad.SetName(ui->stadNameEdit->text());
        selectedStad.SetTeamName(ui->teamNameEdit->text());
        QString country;
        QString state;
        if(ui->countryComboBox->currentIndex() == 1){
            country = "US";
            state = usList.at(ui->stateComboBox->currentIndex());
        }
        else{
            country = "Canada";
            state = canList.at(ui->stateComboBox->currentIndex());

        }
        selectedStad.SetAddress(ui->streetAddressEdit->text(),
                                ui->cityNameEdit->text(),
                                state,
                                ui->zipCodeEdit->text(),
                                country);
        selectedStad.SetPhone(ui->phoneNumEdit->text());
        selectedStad.SetOpenDate(ui->dateEdit->text());
        selectedStad.SetCapacity(ui->maxCapacity->text().toInt());
        selectedStad.SetCapFrame(ui->maxCapacityFrameEdit->text());
        selectedStad.SetMin(ui->minCapacity->text().toInt());
        selectedStad.SetMinFrame(ui->minCapacityFrameEdit->text());
        QString league;
        if(LeagDex == 1){
            league = "AM";
        }
        else{
            league = "NL";
        }
        selectedStad.SetLeague(league);
        bool grass;
        if(ui->grassEdit->currentIndex() == 1){
            grass = true;
        }
        else{
            grass = false;
        }
        selectedStad.SetGrass(grass);

        //Database Modification
        QSqlQuery mod(db);
        mod.prepare("UPDATE stadium SET name = :name, teamName = :teamName, address = :address, city = :city, state = :state, country = :country, zip = :zip, phoneNum = :phoneNum, openDate = :openDate, maxSeatCap = :maxSeatCap, maxTimeFrame = :maxTimeFrame, minSeatCap = :minSeatCap, minTimeFrame = :minTimeFrame, grassType = :grassType, league = :league Where id = :row");
        mod.bindValue(":name", selectedStad.GetName());
        mod.bindValue(":teamName", selectedStad.GetTeamName());
        mod.bindValue(":address", selectedStad.GetAddress());
        mod.bindValue(":city", selectedStad.GetCity());
        mod.bindValue(":state", selectedStad.GetState());
        mod.bindValue(":country", selectedStad.GetCountry());
        mod.bindValue(":zip", selectedStad.GetZip());
        mod.bindValue(":phoneNum", selectedStad.GetPhone());
        mod.bindValue(":openDate", selectedStad.GetOpenDate());
        mod.bindValue(":maxSeatCap", selectedStad.GetCapacity());
        mod.bindValue(":maxTimeFrame", selectedStad.GetMaxFrame());
        mod.bindValue(":minSeatCap", selectedStad.GetMin());
        mod.bindValue(":minTimeFrame", selectedStad.GetMinFrame());
        mod.bindValue(":row", selectedStad.GetId());
        QString grassStr;
        if(selectedStad.GetGrass()){
            grassStr = "Grass";
        }
        else{
            grassStr = "Astro Turf";
        }
        mod.bindValue(":grassType", grassStr);
        mod.bindValue(":league", selectedStad.GetLeague());

        if(!mod.exec()){
            qDebug() << mod.lastError();
        }

        response = new responseWindow(NULL, ADD_SUCCESS);


        this->hide();
        adminwindow *temp = new adminwindow();
        temp->show();
        response->show();
    }

//    //Souviner Saving --> UNNEEDED
//    QSqlQuery souv(db);

//    QAbstractItemModel *souvItem = ui->souvenirTableEdit->model();
//    int maxRows = souvItem->rowCount();

//    for(int row = 0; row < maxRows; row++){
//        souv.prepare("UPDATE souviner SET name = :name, price = :price WHERE stadiumID = :stadiumID");
//        souv.bindValue(":stadiumID", selectedStad.GetId());
//        souv.bindValue(":name", ui->souvenirTableEdit->model()->data(ui->souvenirTableEdit->model()->index(row,0)).toString());
//        souv.bindValue(":price",  ui->souvenirTableEdit->model()->data(ui->souvenirTableEdit->model()->index(row,1)).toString());
//        souv.exec();
//    }


}

void adminwindow::on_updateBtn_clicked()
{
    if(ui->leagueSelectComboBox->currentIndex() != 0 && ui->stadiumSelectWidget->currentRow() >= 0){
        int currRow = ui->stadiumSelectWidget->currentRow();

        Stadium selectedStad;
        if(ui->leagueSelectComboBox->currentIndex() == 1){
            ui->leagueEditComboBox->setCurrentIndex(1);
            selectedStad = amLeague.at(currRow);
        }
        else{
            ui->leagueEditComboBox->setCurrentIndex(2);
            selectedStad = ntLeague.at(currRow);
        }

        responseWindow* response;
        if(ui->souvNameLineEdit->text() == "" || ui->souvNameLineEdit->text() == ""){
            response = new responseWindow(NULL, LINE_BLANK);
        }
        else{
            int row = ui->souvenirTableEdit->selectionModel()->currentIndex().row();
            QSqlQuery query(db);
            query.prepare("UPDATE souvenirs SET name = :name, price = :price WHERE stadiumID = :stadiumID AND name = :oldName");
            query.bindValue(":oldName", ui->souvenirTableEdit->model()->data(ui->souvenirTableEdit->model()->index(row,0)).toString());
            query.bindValue(":stadiumID", selectedStad.GetId());
            query.bindValue(":name", ui->souvNameLineEdit->text());
            query.bindValue(":price", ui->souvPriceLineEdit->text());
            query.exec();

            this->destroySouvTable();
            ui->souvNameLineEdit->clear();
            ui->souvPriceLineEdit->clear();
        }
    }
}

void adminwindow::destroySouvTable(){
    QSqlTableModel *model = new QSqlTableModel();
    ui->souvenirTableEdit->setModel(model);
    this->createSouvTable();
    delete model;
}

void adminwindow::createSouvTable(){
    int currRow = ui->stadiumSelectWidget->currentRow();

    Stadium selectedStad;
    if(ui->leagueSelectComboBox->currentIndex() == 1){
        ui->leagueEditComboBox->setCurrentIndex(1);
        selectedStad = amLeague.at(currRow);
    }
    else{
        ui->leagueEditComboBox->setCurrentIndex(2);
        selectedStad = ntLeague.at(currRow);
    }


    QSqlTableModel *souvTable = new QSqlTableModel(0, db);
    souvTable->setTable("souvenirs");
    QString filter = "stadiumID = ";
            filter.append(QString::number(selectedStad.GetId()));
    qDebug() << filter;
    souvTable->setFilter(filter);
//    souvTable->setFilter("stadiumID=" + selectedStad.GetId());

    // Assigns the horizontal headers for the table
    souvTable->setHeaderData(0, Qt::Horizontal, "Product Name");
    souvTable->setHeaderData(1, Qt::Horizontal, "Price");
    souvTable->setHeaderData(2, Qt::Horizontal, "Stadium ID");

    // Sorts table by field base on column number
//    QSortFilterProxyModel *sort_filter = new QSortFilterProxyModel(this);
//    sort_filter->setSourceModel(souvTable);
//    sort_filter->sort(0);

    // Sets up the table
//    ui->souvenirTableEdit->setModel(sort_filter);
    ui->souvenirTableEdit->setModel(souvTable);
    ui->souvenirTableEdit->setAlternatingRowColors(true);
    ui->souvenirTableEdit->setEditTriggers(false);
    ui->souvenirTableEdit->verticalHeader()->setVisible(false);
    ui->souvenirTableEdit->hideColumn(2);

    // Displays the table
    souvTable->select();
}

void adminwindow::on_addNewBtn_clicked()
{
    if(ui->leagueSelectComboBox->currentIndex() != 0 && ui->stadiumSelectWidget->currentRow() >= 0){
        int currRow = ui->stadiumSelectWidget->currentRow();

        //SETTING STADIUM ID
        QSqlQuery query(db);
        query.prepare("SELECT * FROM stadium");
        query.exec();
        int newID = query.size();

        Stadium selectedStad;
        if(ui->leagueSelectComboBox->currentIndex() == 1){
            ui->leagueEditComboBox->setCurrentIndex(1);
            selectedStad = amLeague.at(currRow);
        }
        else{
            ui->leagueEditComboBox->setCurrentIndex(2);
            selectedStad = ntLeague.at(currRow);
        }

        responseWindow* response;
        if(ui->souvNameLineEdit->text() == "" || ui->souvNameLineEdit->text() == ""){
            response = new responseWindow(NULL, LINE_BLANK);
        }
        else{
            int row = ui->souvenirTableEdit->selectionModel()->currentIndex().row();
            QSqlQuery query(db);
            query.prepare("INSERT INTO souvenirs (name, price, stadiumID) VALUES (:name, :price, :stadiumID)");
            query.bindValue(":stadiumID", selectedStad.GetId());
            query.bindValue(":name", ui->souvNameLineEdit->text());
            query.bindValue(":price", ui->souvPriceLineEdit->text());
            query.exec();

            this->destroySouvTable();
            ui->souvNameLineEdit->clear();
            ui->souvPriceLineEdit->clear();


        }
    }
}

void adminwindow::on_deleteSouv_clicked()
{
    if(ui->leagueSelectComboBox->currentIndex() != 0 && ui->stadiumSelectWidget->currentRow() >= 0){
        int currRow = ui->stadiumSelectWidget->currentRow();

        Stadium selectedStad;
        if(ui->leagueSelectComboBox->currentIndex() == 1){
            ui->leagueEditComboBox->setCurrentIndex(1);
            selectedStad = amLeague.at(currRow);
        }
        else{
            ui->leagueEditComboBox->setCurrentIndex(2);
            selectedStad = ntLeague.at(currRow);
        }

        int row = ui->souvenirTableEdit->selectionModel()->currentIndex().row();
        QSqlQuery query(db);
        query.prepare("DELETE FROM souvenirs WHERE name = :name AND stadiumID = :stadiumID");
        query.bindValue(":stadiumID", selectedStad.GetId());
        query.bindValue(":name", ui->souvenirTableEdit->model()->data(ui->souvenirTableEdit->model()->index(row,0)).toString());
        query.exec();

        this->destroySouvTable();
        ui->souvNameLineEdit->clear();
        ui->souvPriceLineEdit->clear();
    }
}

void adminwindow::on_addNewStadBtn_clicked()
{
    bool hasFailed;
    responseWindow* response;

    //Stadium Page Fields
    Stadium newStadium;

    //SETTING STADIUM ID
    QSqlQuery query(db);
    query.prepare("SELECT * FROM stadium");
    query.exec();
    int newID = query.size();

    int LeagDex = ui->leagueEditComboBox->currentIndex();
    if(LeagDex == 0){
        hasFailed = true;
        // Declares new response window
        response = new responseWindow(NULL, LEAGUE_SELECT);
    }
    else if(ui->countryComboBox->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, COUNTRY_SELECT);
    }
    else if(ui->stateComboBox->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, STATE_SELECT);
    }
    else if(ui->grassEdit->currentIndex() == 0){
        hasFailed = true;
        response = new responseWindow(NULL, GRASS_SELECT);
    }

    if(hasFailed){
        // Displays window
        response->show();
    }
    else{
        newStadium.SetName(ui->stadNameEdit->text());
        newStadium.SetTeamName(ui->teamNameEdit->text());
        QString country;
        QString state;
        if(ui->countryComboBox->currentIndex() == 1){
            country = "US";
            state = usList.at(ui->stateComboBox->currentIndex());
        }
        else{
            country = "Canada";
            state = canList.at(ui->stateComboBox->currentIndex());

        }
        newStadium.SetAddress(ui->streetAddressEdit->text(),
                                ui->cityNameEdit->text(),
                                state,
                                ui->zipCodeEdit->text(),
                                country);
        newStadium.SetPhone(ui->phoneNumEdit->text());
        newStadium.SetOpenDate(ui->dateEdit->text());
        newStadium.SetCapacity(ui->maxCapacity->text().toInt());
        newStadium.SetCapFrame(ui->maxCapacityFrameEdit->text());
        newStadium.SetMin(ui->minCapacity->text().toInt());
        newStadium.SetMinFrame(ui->minCapacityFrameEdit->text());
        QString league;
        if(LeagDex == 1){
            league = "AM";
        }
        else{
            league = "NL";
        }
        newStadium.SetLeague(league);
        bool grass;
        if(ui->grassEdit->currentIndex() == 1){
            grass = true;
        }
        else{
            grass = false;
        }
        newStadium.SetGrass(grass);
        newStadium.SetId(newID);

        //Database Modification
        QSqlQuery mod(db);
        mod.prepare("INSERT INTO stadium (name, id, teamName, address, city, state, country, zip, phoneNum, openDate, maxSeatCap, maxTimeFrame, minSeatCap, minTimeFrame, grassType, league) VALUES (:name, :id, :teamName, :address, :city, :state, :country, :zip, :phoneNum, :openDate, :maxSeatCap, :maxTimeFrame, :minSeatCap, :minTimeFrame, :grassType, :league)");
        mod.bindValue(":name", newStadium.GetName());
        mod.bindValue(":teamName", newStadium.GetTeamName());
        mod.bindValue(":address", newStadium.GetAddress());
        mod.bindValue(":city", newStadium.GetCity());
        mod.bindValue(":state", newStadium.GetState());
        mod.bindValue(":country", newStadium.GetCountry());
        mod.bindValue(":zip", newStadium.GetZip());
        mod.bindValue(":phoneNum", newStadium.GetPhone());
        mod.bindValue(":openDate", newStadium.GetOpenDate());
        mod.bindValue(":maxSeatCap", newStadium.GetCapacity());
        mod.bindValue(":maxTimeFrame", newStadium.GetMaxFrame());
        mod.bindValue(":minSeatCap", newStadium.GetMin());
        mod.bindValue(":minTimeFrame", newStadium.GetMinFrame());
        mod.bindValue(":id", newStadium.GetId());
        QString grassStr;
        if(newStadium.GetGrass()){
            grassStr = "Grass";
        }
        else{
            grassStr = "Astro Turf";
        }
        mod.bindValue(":grassType", grassStr);
        mod.bindValue(":league", newStadium.GetLeague());

        if(!mod.exec()){
            qDebug() << mod.lastError();
        }

        response = new responseWindow(NULL, ADD_SUCCESS);

        this->hide();
        adminwindow *temp = new adminwindow();
        temp->show();
        response->show();
        ui->addNewStadBtn->hide();

        QSqlQuery find(db);
        find.exec("SELECT * FROM edges");
        find.first();
        int mtxCols= find.record().count();

        QString newCol = "c";
        newCol.append(QString::number(mtxCols-1));
        QSqlQuery mtrxEdit(db);
        QString prepState = "ALTER TABLE edges ADD ";
        prepState.append(newCol);
        prepState.append(" INT");
        mtrxEdit.prepare(prepState);

        qDebug() << "NEW COL: " << newCol;
        mtrxEdit.bindValue(":col", newCol);
        mtrxEdit.exec();

        mtrxEdit.prepare("INSERT INTO edges (id) VALUES (:id)");
        mtrxEdit.bindValue(":id", mtxCols-1);
        mtrxEdit.exec();

        mtrxEdit.prepare("SELECT * FROM edges");
        mtrxEdit.exec();
        mtrxEdit.first();
        for(int row = 0; row < mtxCols; row++){
            QString prep = "UPDATE edges SET ";
            prep.append(newCol);
            prep.append(" = 0");
            mtrxEdit.prepare(prep);
            mtrxEdit.exec();
            mtrxEdit.next();
        }

    }
}

void adminwindow::createAdjMatrix(){
    QSqlTableModel *adjMtrx = new QSqlTableModel(0, db);
    adjMtrx->setTable("edges");


    // Assigns the horizontal headers for the table


    // Sets up the table
    ui->adjMatrix->setModel(adjMtrx);
    ui->adjMatrix->setAlternatingRowColors(true);


    // Displays the table
    adjMtrx->select();
}
