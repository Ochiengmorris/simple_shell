#include "main.h"

/**
 * catcd - put cd error message together.
 * @reldata: reldata.
 * @messo: to be printed.
 * @valerr: the error messo.
 * @strvar: countr lines.
 * Return: error message.
 */

char *catcd(data_group *reldata, char *messo, char *valerr, char *strvar)
{
	char *flag;

	strcopy(valerr, reldata->av[0]);
	strcat_(valerr, ": ");
	strcat_(valerr, strvar);
	strcat_(valerr, ": ");
	strcat_(valerr, reldata->arguments[0]);
	strcat_(valerr, messo);

	if (reldata->arguments[1][0] == '-')
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = reldata->arguments[1][1];
		flag[2] = '\0';

		strcat_(valerr, flag);
		free(flag);
	}
	else
	{
		strcat_(valerr, reldata->arguments[1]);
	}

	strcat_(valerr, "\n");
	strcat_(valerr, "\0");

	return (valerr);
}

/**
 * shellexit - error messo for exiting the shell.
 * @reldata: reldata.
 * Return: error messo.
 */

char *shellexit(data_group *reldata)
{
	int len;
	char *errorval, *strvar;

	strvar = rec_intos(reldata->countr);
	len = strlen_(reldata->av[0]) + strlen_(strvar);
	len += strlen_(reldata->arguments[0]) + strlen_(reldata->arguments[1]) + 23;
	errorval = malloc(sizeof(char) * (len + 1));

	if (errorval == 0)
	{
		free(strvar);
		return (NULL);
	}
	strcopy(errorval, reldata->av[0]);
	strcat_(errorval, ": ");
	strcat_(errorval, strvar);
	strcat_(errorval, ": ");
	strcat_(errorval, reldata->arguments[0]);
	strcat_(errorval, ": command not found: ");
	strcat_(errorval, reldata->arguments[1]);
	strcat_(errorval, "\n\0");
	free(strvar);

	return (errorval);
}

/**
 * enverror - message for error of env envv.
 * @reldata: ...
 * Return: ...
 */

char *enverror(data_group *reldata)
{
	int len;
	char *errorval, *strvar, *messo;

	strvar = rec_intos(reldata->countr);
	messo = ": Unable to do the add/removal action from the environment\n";
	len = strlen_(reldata->av[0]) + strlen_(strvar);
	len = len + strlen_(reldata->arguments[0]) + strlen_(messo) + 4;
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
	strcat_(errorval, messo);
	strcat_(errorval, "\0");
	free(strvar);

	return (errorval);
}

/**
 * patherror126 - error message for path error.
 * @reldata: ...
 * Return: ...
 */

char *patherror126(data_group *reldata)
{
	int len;
	char *strvar, *errorval;

	strvar = rec_intos(reldata->countr);
	len = strlen_(reldata->av[0]) + strlen_(strvar);
	len = len + strlen_(reldata->arguments[0]) + 24;
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
	strcat_(errorval, ": Permission revoked\n");
	strcat_(errorval, "\0");
	free(strvar);

	return (errorval);
}

