

#include "include/Date.h"

/*************************************************************************
 * Method GetDaysInMonth: Class Date
 *------------------------------------------------------------------------
 *   This method takes the month and year in as input, it will calculate
 *   the number of days in the current month it will call the IsLeapYear
 *   method if the month input is February
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *
 *    month : user input month
 *    year  : user input year
 *
 *  POST-CONDITIONS:
 *    This method will return the number of days in the input month
 *************************************************************************/
unsigned short Date::GetDaysInMonth
					(unsigned short month,		// IN - user input year
					 unsigned short year) const // IN - user input year
{
	unsigned short daysInMonth;

	if(month == 2)
	{
		if(IsLeapYear(year))
		{
			daysInMonth = 29;
		}
		else
		{
			daysInMonth = 28;
		}
	}
	else if(month == 4 ||
			month == 6 ||
			month == 9 ||
			month == 11 )
	{
		daysInMonth = 30;
	}
	else
	{
		daysInMonth = 31;
	}
	return daysInMonth;
}

/*************************************************************************
 * Method IsLeapYear: Class Date
 *------------------------------------------------------------------------
 *   This method takes the year as input, and checks if its a leap year,
 *   every 4th year is a leap year, unless its a 100th year, but is a leap
 *   year every 400 years
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    year  : user input year
 *
 *  POST-CONDITIONS:
 *    Returns a bool, true if leap year false if not
 *************************************************************************/
bool Date::IsLeapYear(unsigned short year) const // IN - year to check
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}
