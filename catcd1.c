#include "main.h"

/**
 * enotfound - error messo for command not found.
 * @reldata: ...
 * Return: ...
 */

char *enotfound(data_group *reldata)
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

