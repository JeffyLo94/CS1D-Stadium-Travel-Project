#ifndef STADIUM_H
#define STADIUM_H

#include "date.h"
#include "souvenir.h"
#include <sstream>
#include <qstring.h>
#include <vector>
#include <qlist.h>


class Stadium
{
public:
    Stadium();
    Stadium(int newid, QString newName, QString newTeamName, QString newAddress, QString newCity,
            QString newState, QString newZip, QString newCountry, bool isGrass, QString newPhoneNum, QString newOpenDate,
            int newSeatCap, int newSeatMin, QString newLeague);
    ~Stadium();
    void SetAll(int newid, QString newName, QString newTeamName, QString newAddress, QString newCity,
                QString newState, QString newZip, QString newCountry, QString newPhoneNum, bool isGrass, QString newOpenDate,
                int newSeatCap, int newSeatMin, QString newLeague);
    void SetName(QString newName);
    void SetId(int newId);
    void SetTeamName(QString newTeamName);
    void SetCapacity (int newCapacity);
    void SetCapFrame(QString newFrame);
    void SetMin (int newMin);
    void SetMinFrame(QString newFrame);
    void SetPhone(QString newPhone);
    void SetGrass(bool isGrass);
    void SetAddress(QString newAddress, QString newCity,
                    QString newState, QString newZip,
                    QString newCountry);
    void SetOpenDate (QString newDate);
    void SetLeague (QString newLeague);
    bool AddSouvenir (Souvenir newSouvenir);
    QString GetName () const;
    int GetId() const;
    QString GetTeamName () const;
    int GetCapacity () const;
    QString GetMaxFrame() const;
    int GetMin () const;
    QString GetMinFrame() const;
    QString GetPhone () const;
    QString GetAddress () const;
    QString GetStreet () const;
    QString GetCity () const;
    QString GetState () const;
    QString GetZip () const;
    QString GetCountry () const;
    QString GetOpenDate () const;
    QString GetLeague () const;
    bool GetGrass () const; // QString?
    QString ToString () const;
    void GetSouvenirs(QList<Souvenir> &youGet);
    Souvenir GetSouvenir (QString SouvenirName);
    void Print (ostream& os) const;

private:
    QString name;
    QString teamName;
    QString address;
    QString city;
    QString state;
    QString zip;
    QString country;
    QString phone;
    bool    grass;
    QString openDate;
    int     seatCap;
    QString seatCapFrame;
    int     seatMin;
    QString seatMinFrame;
    QString league;
    QList<Souvenir> souvenirList;
    int id;
};

#endif // STADIUM_H
