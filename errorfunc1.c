#include "main.h"

/**
 * cd_error - messo for error to be printed for the cd command.
 *
 * @reldata: reldata.
 * Return: the error messo.
 */

char *cd_error(data_group *reldata)
{
	int lengid, len;
	char *errorval, *strvar, *messo;

	strvar = rec_intos(reldata->countr);
	if (reldata->arguments[1][0] == '-')
	{
		messo = ": Option not allowed ";
		lengid = 2;
	}
	else
	{
		messo = ": unable to cd to ";
		lengid = strlen_(reldata->arguments[1]);
	}

	len = strlen_(reldata->av[0]) + strlen_(reldata->arguments[0]);
	len = len + strlen_(strvar) + strlen_(messo) + lengid + 5;
	errorval = malloc(sizeof(char) * (len + 1));

	if (errorval == 0)
	{
		free(strvar);
		return (NULL);
	}

	errorval = catcd(reldata, messo, errorval, strvar);

	free(strvar);

	return (errorval);
}


/**
 * notfound - error messo for unavailable command.
 *
 * @reldata: reldata.
 * Return: error messo.
 */

char *notfound(data_group *reldata)
{
	int len;
	char *errorval, *strvar;

	strvar = rec_intos(reldata->countr);
	len = strlen_(reldata->av[0]) + strlen_(strvar);
	len = len + strlen_(reldata->arguments[0]) + 16;
	errorval = malloc(sizeof(char) * (len + 1));

	if (errorval == 0)
	{
		free(errorval);
		free(strvar);
		return (NULL);
	}
	strcopy(errorval, reldata->av[0]);
	strcat_(errorval, ": ");
	strcat_(errorval, strvar);
	strcat_(errorval, ": ");
	strcat_(errorval, reldata->arguments[0]);
	strcat_(errorval, ": not found\n");
	strcat_(errorval, "\0");
	free(strvar);

	return (errorval);
}

