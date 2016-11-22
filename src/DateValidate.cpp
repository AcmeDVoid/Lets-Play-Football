

#include "include/Date.h"
/*************************************************************************
 * Method ValidateMonth: Class Date
 *------------------------------------------------------------------------
 *   This method checks the month day and year if its valid and then stores
 *   it into day , month , and year
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  month
 *  day
 *  year
 *
 *  POST-CONDITIONS:
 *   This method retruns a bool
 *************************************************************************/
bool Date :: ValidateMonth(unsigned short month) const
{
	return month >= 1 && month <= 12;
}
/*************************************************************************
 * Method ValidateDay: Class Date
 *------------------------------------------------------------------------
 *   This method checks the month, day , yeear to check for the users \
 *   input for the day and then
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  month
 *  day
 *  year
 *
 *  POST-CONDITIONS:
 *    This method retruns a bool
 *************************************************************************/
bool Date :: ValidateDay(unsigned short month,
						 unsigned short day,
						 unsigned short year) const
{
	unsigned short maxDays;

	maxDays = GetDaysInMonth(month, year);

	return day >= 1 && day <= maxDays;
}
/*************************************************************************
 * Method SetDate: Class Date
 *------------------------------------------------------------------------
 *   This method checks the users input for the year
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  month
 *  day
 *  year
 *
 *  POST-CONDITIONS:
 *    This method retruns a bool
 *************************************************************************/
bool Date :: ValidateYear(unsigned short year) const
{
	return year >= 1900 && year <= 3000;
}
/*************************************************************************
 * Method ValidateDate: Class Date
 *------------------------------------------------------------------------
 *   This method checks the year month and day to the current date
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  month
 *  day
 *  year
 *
 *  POST-CONDITIONS:
 *    This method retruns a bool
 *************************************************************************/
bool Date :: ValidateDate(unsigned short month,
				  unsigned short day,
				  unsigned short year) const
{
	Date today;
	bool valid;

	valid = false;

	if(ValidateYear(year))
	{
		if(month == today.dateMonth)
		{
			if(day <= today.dateDay)
			{
				valid = true;
			}
		}
		else if(month < today.dateMonth)
		{
			valid = true;
		}
	}
	else if(ValidateYear(year))
	{
		valid = true;
	}

	return valid;
}
