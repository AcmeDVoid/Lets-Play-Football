

#include "include/Date.h"
/*************************************************************************
 * CONSTRUCTOR Date()
 *------------------------------------------------------------------------
 *   This CONSTRUCTOR gets the current system time and stores as a day,
 *   month , and year
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *
 *  POST-CONDITIONS:
 *    initializes a Date object to the current date
 *************************************************************************/
Date :: Date()
{
	time_t now;
	tm     *currentTime;

	currentTime = NULL;

	now = time(NULL);
	currentTime = localtime(&now);

	dateDay   = currentTime        -> tm_mday;
	dateMonth = currentTime        -> tm_mon + 1;
	dateYear  = 1900 + currentTime -> tm_year;
}

/*************************************************************************
 * CONSTRUCTOR Date(unsigned short month,
 *                  unsigned short day,
 *                  unsigned short year)
 *------------------------------------------------------------------------
 *   This CONSTRUCTOR takes the user input, checks to see if it is valid,
 *   if it is not, it will set the Date object to the current time
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *  	month : the month to be stored in the object
 *  	day	  : the day to be stored in the object
 *  	year  : the year to be stored in the object
 *
 *  POST-CONDITIONS:
 *    initializes a Date object to the stored info if it is valid
 *    	otherwise initializes a Date object to the current date
 *************************************************************************/
Date :: Date(unsigned short month,unsigned short day,unsigned short year)
{
	time_t now;
	tm     *currentTime;

	currentTime = NULL;

	now = time(NULL);
	currentTime = localtime(&now);

//The reason i commeneted this out is because i don't think we need
//validation for the datastructure holding the time - all date and time
//validation will be done on the front-end.
//	if(ValidateMonth(month)
//	   && ValidateYear(year)
//	   && ValidateDay( month, day, year)
//	   && ValidateDate(month, day ,year))
    if(true)
	{
		dateDay   = day;
		dateMonth = month;
		dateYear  = year;

	}
	else
	{
		dateDay   = currentTime        -> tm_mday;
		dateMonth = currentTime        -> tm_mon + 1;
		dateYear  = 1900 + currentTime -> tm_year;
	}

}

/*************************************************************************
 * Destructor ~Date()
 *------------------------------------------------------------------------
 *   This destructor does nothing inparticular
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *
 *  POST-CONDITIONS:
 *  	does nothing
 *************************************************************************/
Date :: ~Date()
{

}
