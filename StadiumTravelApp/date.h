#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <iostream>
using namespace std;

class Date
{
    public:
        Date ();
        Date(int newDay,int newMonth,int newYear);
        ~Date ();
        void SetDate (int newDay, int newMonth, int newYear);
        void SetDay  (int newDay);

        int GetDay       () const;
        int GetMonth     () const;
        int GetYear      () const;
        void GetDate     (int &day1, int &month1, int &year1) const;
        string PrintDate   () const;
        bool CompareDate (const Date &compDate) const;
        bool CompareDate (int newDay, int newMonth, int newYear) const;

    private:
        int day;
        int month;
        int year;
};


#endif // DATE_H
