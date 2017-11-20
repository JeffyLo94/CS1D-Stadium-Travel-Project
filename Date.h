/*************************************************************************
 * AUTHOR         : Jon Griswold
 * STUDENT ID     : 364919
 * Assignment #6  : Saddleback Bank - OOP
 * CLASS          : CS1B
 * SECTION        : MTWTH: 8AM
 * DUE DATE       : 07/08/14
 *************************************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <sstream>
#include <iostream>
using namespace std;

class Date
{
	public:
		Date ();
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



#endif /* DATE_H_ */
