
#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;


class Date
{
public:
	/*********************************************************************
	 * CONSTRUCTORS & DESTRUCTOR
	 *********************************************************************/
	Date();

	//uses private utility methods
	Date(unsigned short month,
		 unsigned short day,
		 unsigned short year);

	~Date();

	/*********************************************************************
	 * MUTATORS
	 *********************************************************************/
	// uses private utility methods
	void SetDate(unsigned short month,
				 unsigned short day,
				 unsigned short year);

	/*********************************************************************
	 * ACCESSORS
	 *********************************************************************/
	void GetDate(unsigned short &month,
				 unsigned short &day,
				 unsigned short &year) const;

	unsigned short GetYear()  const;
	unsigned short GetMonth() const;
	unsigned short GetDay()   const;
	// need to comment
	int CalculateMonths(Date secondDate);

	// Displays in MM/DD/YYYY format

	string DisplayDate() const;

private:

	/*********************************************************************
	 * UTILITIES METHODS
	 *********************************************************************/
	unsigned short GetDaysInMonth(unsigned short month,
								  unsigned short year) const;

	bool IsLeapYear(unsigned short year) const;

	/*********************************************************************
	 * VALIDATE METHODS
	 *********************************************************************/
	bool ValidateMonth(unsigned short month) const;

	bool ValidateDay(unsigned short month,
					 unsigned short day,
					 unsigned short year) const;

	bool ValidateYear(unsigned short year) const;

	bool ValidateDate(unsigned short month,
					  unsigned short day,
					  unsigned short year) const;

	/*********************************************************************
	 * ATTRIBUTES
	 *********************************************************************/
	unsigned short dateMonth;
	unsigned short dateDay;
	unsigned short dateYear;
};
/***********************************************************************
 * Date class
 *   This class represents a date it allows the user to change the
 *   month day and year, and will make sure the day is a valid date
 *   that is the same or earlier than the current date.
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/

/***********************************************************************
 ** Date();
 **   Constructor; Initializes class attributes
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** Date();
 **   Constructor;  This CONSTRUCTOR takes the user input, checks
 **   to see if it is valid, if it is not, it will set the Date
 **   object to the current time
 **
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 ** ~Date();
 **   Destructor; does nothing
 **   Parameter: None
 **   Returns: Nothing
 ***********************************************************************/

/**************
 ** MUTATORS **
 **************/

/***********************************************************************
 ** SetDate
 **
 **   This method checks the month day and year if its valid and then stores
 **     it into day , month , and year
 **---------------------------------------------------------------------
 **   Parameter: month day year
 **---------------------------------------------------------------------
 **   Returns: none
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 ** GetDate();
 **   Accessor; This Accessor returns month , day and year
 **   Parameter: month day year
 **   Returns: none
 ***********************************************************************/


/***********************************************************************
 ** GetYear();
 **   Accessor; This Accessor returns month , day and year
 **   Parameter: month day year
 **   Returns: none
 ***********************************************************************/


/***********************************************************************
 ** GetYear();
 **   Accessor; his Accessor returns dateMonth to the calling function
 **   Parameter: None
 **   Returns: dateYear
 ***********************************************************************/


/***********************************************************************
 ** GetMonth();
 **   Accessor; This Accessor returns month , day and year
 **   Parameter: month
 **   Returns: dateMonth
 ***********************************************************************/

/***********************************************************************
 ** GetDay();
 **   Accessor; This Accessor returns month , day and year
 **   Parameter:  day
 **   Returns: dateDay
 ***********************************************************************/

/***********************************************************************
 ** DisplayDate();
 **   Accessor; This Accessor checks if the date is two chars if not
 **      will add a zero infront of the date and then
 **      stroes it into dateLine.
 **   Parameter:  none
 **   Returns: dateLine.str()
 ***********************************************************************/



#endif /* DATE_H_ */
