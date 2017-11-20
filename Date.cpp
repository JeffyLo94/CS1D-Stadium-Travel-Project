/*************************************************************************
 * AUTHOR         : Jon Griswold
 * STUDENT ID     : 364919
 * Assignment #6  : Saddleback Bank - OOP
 * CLASS          : CS1B
 * SECTION        : MTWTH: 8AM
 * DUE DATE       : 07/08/14
 *************************************************************************/

#include "Date.h"


Date::Date ()
{
	day   = 0;
	month = 0;
	year  = 0;
}

Date::~Date ()
{
}

void Date::SetDate (int newDay, int newMonth, int newYear)
{
	day = newDay;
	month = newMonth;
	year = newYear;
}

void Date::SetDay  (int newDay)
{
	day = newDay;
}

int Date::GetDay       () const
{
	return day;
}

int Date::GetMonth     () const
{
	return month;
}

int Date::GetYear      () const
{
	return year;
}

void Date::GetDate     (int &day1, int &month1, int &year1) const
{
	day1   = day;
	month1 = month;
	year1  = month;
}

string Date::PrintDate   () const
{
	ostringstream outString;
	if (month < 10)
	{
		outString << 0;
	}

	outString << month << "/";

	if (day < 10)
	{
		outString << 0;
	}

	outString << day << "/" << year;

	return outString.str();
}

bool Date::CompareDate (const Date &compDate) const
{
	return (compDate.GetDay() == day && compDate.GetMonth() == month &&
		    compDate.GetYear() == year);

}

bool Date::CompareDate (int newDay, int newMonth, int newYear) const
{
	return (newDay == day && newMonth == month && newYear == year);

}

