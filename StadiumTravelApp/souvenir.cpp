#include "souvenir.h"

Souvenir::Souvenir()
{

}

Souvenir::Souvenir(QString newName, double newPrice)
{
    name = newName;
    price = newPrice;
}

Souvenir::~Souvenir()
{
}

void Souvenir::SetAll(QString newName, double newPrice)
{
    name = newName;
    price = newPrice;
}

QString Souvenir::GetName () const
{
    return name;
}

double Souvenir::GetPrice () const
{
    return price;
}

void Souvenir::Print () const
{
    //TODO print souvenir if we need it
}

QString Souvenir::ToString () const
{
    //TODO to String if we need that
}


