#include "stadium.h"

Stadium::Stadium()
{
    
}

Stadium::Stadium(int newid, QString newName, QString newTeamName, QString newAddress, QString newCity,
        QString newState, QString newZip, QString newCountry, bool isGrass, QString newPhoneNum, QString newOpenDate,
        int newSeatCap, int newSeatMin, QString newLeague)
{
    id = newid;
    name = newName;
    teamName = newTeamName;
    address = newAddress;
    city = newCity;
    state = newState;
    zip = newZip;
    country = newCountry;
    phone = newPhoneNum;
    grass = isGrass;
    openDate = newOpenDate;
    seatCap = newSeatCap;
    seatMin = newSeatMin;
    league = newLeague;
}

Stadium::~Stadium()
{
    
}

void Stadium::SetAll(int newid, QString newName, QString newTeamName, QString newAddress, QString newCity,
            QString newState, QString newZip, QString newCountry, QString newPhoneNum, bool isGrass, QString newOpenDate,
            int newSeatCap, int newSeatMin, QString newLeague)
{
    id = newid;
    name = newName;
    teamName = newTeamName;
    address = newAddress;
    city = newCity;
    state = newState;
    zip = newZip;
    country = newCountry;
    phone = newPhoneNum;
    grass = isGrass;
    openDate = newOpenDate;
    seatCap = newSeatCap;
    seatMin = newSeatMin;
    league = newLeague;
}

void Stadium::SetName(QString newName)
{
    name = newName;
}

void Stadium::SetId(int newId)
{
    id = newId;
}

void Stadium::SetTeamName(QString newTeamName)
{
    teamName = newTeamName;
}

void Stadium::SetCapacity (int newCapacity)
{
    seatCap = newCapacity;
}

void Stadium::SetCapFrame(QString newFrame)
{
    seatCapFrame = newFrame;
}

void Stadium::SetMin (int newMin)
{
    seatMin = newMin;
}

void Stadium::SetMinFrame(QString newFrame)
{
    seatMinFrame = newFrame;
}

void Stadium::SetPhone(QString newPhone)
{
    phone = newPhone;
}

void Stadium::SetAddress(QString newAddress, QString newCity,
                QString newState, QString newZip,
                QString newCountry)
{
    address = newAddress;
    city = newCity;
    state = newState;
    zip = newZip;
    country = newCountry;
}

void Stadium::SetOpenDate (QString newDate)
{
    openDate = newDate;
}

void Stadium::SetLeague (QString newLeague)
{
    league = newLeague;
}

void Stadium::SetGrass(bool isGrass)
{
    grass = isGrass;
}

bool Stadium::AddSouvenir (Souvenir newSouvenir)
{
    souvenirList.push_back(newSouvenir);
}

QString Stadium::GetName () const
{
    return name;
}

int Stadium::GetId() const
{
    return id;
}

QString Stadium::GetTeamName () const
{
    return teamName;
}

int Stadium::GetCapacity () const
{
    return seatCap;
}

QString Stadium::GetMaxFrame() const
{
    return seatCapFrame;
}

int Stadium::GetMin () const
{
    return seatMin;
}

QString Stadium::GetMinFrame() const
{
    return seatMinFrame;
}

QString Stadium::GetPhone () const
{
    return phone;
}

QString Stadium::GetAddress () const
{
    return address;
}

QString Stadium::GetStreet () const{
    return address;
}

QString Stadium::GetCity() const{
    return city;
}

QString Stadium::GetState() const{
    return state;
}

QString Stadium::GetZip() const{
    return zip;
}

QString Stadium::GetCountry() const{
    return country;
}

QString Stadium::GetOpenDate () const
{
    return openDate;
}

QString Stadium::GetLeague () const
{
    return league;
}

bool Stadium::GetGrass() const
{
    return grass;
}

QString Stadium::ToString () const
{
    //TODO this
}

void Stadium::GetSouvenirs(QList<Souvenir> &youGet)
{
    youGet = souvenirList;
}

Souvenir Stadium::GetSouvenir (QString SouvenirName)
{
    Souvenir temp;
    for (int i = 0; i < souvenirList.size()-1;i++)
    {
        if (souvenirList.at(i).GetName() == SouvenirName)
        {
            temp = souvenirList.at(i);
        }
    }

    return temp;
}

void Stadium::Print (ostream& os) const
{
    
}
