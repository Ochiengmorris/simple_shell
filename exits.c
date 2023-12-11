#include "main.h"

/**
 * exits - exits shell
 * @reldata: reldata.
 * Return: 0 success
 */

int exits(data_group *reldata)
{
	unsigned int astatus;
	int digit, lenstr, largeno;

	if (reldata->arguments[1] != NULL)
	{
		astatus = stoin(reldata->arguments[1]);
		digit = digits(reldata->arguments[1]);
		lenstr = strlen_(reldata->arguments[1]);
		largeno = astatus > (unsigned int)INT_MAX;
		if (!digit || lenstr > 10 || largeno)
		{
			checkerror(reldata, 2);
			reldata->status = 2;
			return (1);
		}
		reldata->status = (astatus % 256);
	}
	return (0);
}

