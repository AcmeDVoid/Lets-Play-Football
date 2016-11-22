

#include "include/Date.h"
/*************************************************************************
 * Accessor GetDate: Class Date
 *------------------------------------------------------------------------
 *   This Accessor returns month , day and year
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  month : dummy variable to return the month
 *  day   : dummy variable to return the day
 *  year  : dummy variable to return the year
 *
 *  POST-CONDITIONS:
 *    This method return the day month and year by reference
 *************************************************************************/
void Date :: GetDate(unsigned short &month,
		             unsigned short &day,
		             unsigned short &year) const
{

	month = dateMonth;
	day   = dateDay;
	year  = dateYear;
}

/*************************************************************************
 * Accessor GetYear: Class Date
 *------------------------------------------------------------------------
 *   This Accessor returns dateYear to the calling function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  none
 *
 *  POST-CONDITIONS:
 *    This method will returns the year
 *************************************************************************/
unsigned short Date :: GetYear() const
{
	return dateYear;
}
/*************************************************************************
 * Accessor GetMonth: Class Date
 *------------------------------------------------------------------------
 *   This Accessor returns dateMonth to the calling function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *
 *  POST-CONDITIONS:
 *    This method will retrun the month
 *************************************************************************/
unsigned short Date :: GetMonth() const
{
	return dateMonth;
}
/*************************************************************************
 * Accessor GetDay: Class Date
 *------------------------------------------------------------------------
 *   This Accessor returns dateDays
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *
 *  POST-CONDITIONS:
 *    This method retruns dateDay
 *************************************************************************/
unsigned short Date :: GetDay() const
{
	return dateDay;
}
/*************************************************************************
 * Accessor DisplayDate: Class Date
 *------------------------------------------------------------------------
 *   This Accessor checks if the date is two chars if not will add a zero
 *   infront of the date and then stroes it into dateLine.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:

 *
 *  POST-CONDITIONS:
 *    returns dateLine as a string
 *************************************************************************/
string Date :: DisplayDate() const
{
	ostringstream dateLine;

	if(dateMonth < 10)
	{
		dateLine << '0' << dateMonth;
	}
	else
	{
		dateLine << dateMonth;
	}

	dateLine << '/';

	if(dateDay < 10)
	{
		dateLine << '0' << dateDay;
	}
	else
	{
		dateLine << dateDay;
	}

	dateLine << '/';

	dateLine << dateYear;

	return dateLine.str();
}

/*************************************************************************
 * Method CalculateMonths: Class Date
 *------------------------------------------------------------------------
 *   finds the difference in months between two dates, if the first date
 *   is later than the second date returns 0 months;
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    The following need previously defined values:
 *	    secondDate : date to compare with
 *
 *  POST-CONDITIONS:
 *    returns the number of months that have passed
 *************************************************************************/
int Date :: CalculateMonths(Date secondDate) //IN - date to compare with
{
	int numberOfMonths;
	int changeOfYears;

	numberOfMonths = secondDate.dateMonth - dateMonth;
	changeOfYears  = secondDate.dateYear  - dateYear;

	for(int count = 0; count < changeOfYears; count++)
	{
		numberOfMonths += 12;
	}

	if(changeOfYears < 0 || numberOfMonths < 0)
	{
		numberOfMonths = 0;
	}

	return numberOfMonths;
}
