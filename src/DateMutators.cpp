
#include "include/Date.h"

/*************************************************************************
 * Method SetDate: Class Date
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
 *    This method will set the date
 *************************************************************************/
void Date :: SetDate(unsigned short month,
		             unsigned short day,
			         unsigned short year)
{

	if(   ValidateMonth(month)
	   && ValidateYear(year)
	   && ValidateDay( month, day, year))
		{
			dateDay   = day;
			dateMonth = month;
			dateYear  = year;
		}
}

