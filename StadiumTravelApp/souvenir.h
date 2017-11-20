#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <qstring.h>

class Souvenir
{
public:
    Souvenir();
    Souvenir(QString newName, double newPrice);
    ~Souvenir();
    void SetAll(QString newName, double newPrice);
    QString GetName () const;
    double GetPrice () const;
    void Print () const;
    QString ToString () const;

private:
    double price;
    QString name;
};

#endif // SOUVENIR_H
