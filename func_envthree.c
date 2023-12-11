#include "main.h"

/**
 * envset - for contrasting env vars.
 *
 * @reldata: reldata.
 * Return: 1.
 */

int envset(data_group *reldata)
{
	if (reldata->arguments[1] == NULL || reldata->arguments[2] == NULL)
	{
		checkerror(reldata, -1);
		return (1);
	}

	envsett(reldata->arguments[1], reldata->arguments[2], reldata);

	return (1);
}

/**
 * envunset - removes an environment variable.
 *
 * @reldata: reldata.
 * Return: 1.
 */

int envunset(data_group *reldata)
{
	char **envr;
	char *envvar, *envname;
	int i, j, k;

	if (reldata->arguments[1] == NULL)
	{
		checkerror(reldata, -1);
		return (1);
	}
	k = -1;

	for (i = 0; reldata->enviro[i]; i++)
	{
		envvar = strdup_(reldata->enviro[i]);
		envname = strtok_(envvar, "=");
		if (streamp(envname, reldata->arguments[1]) == 0)
		{
			k = i;
		}
		free(envvar);
	}
	if (k == -1)
	{
		checkerror(reldata, -1);
		return (1);
	}
	envr = malloc(sizeof(char *) * (i));
	for (i = j = 0; reldata->enviro[i]; i++)
	{
		if (i != k)
		{
			envr[j] = reldata->enviro[i];
			j++;
		}
	}
	envr[j] = NULL;
	free(reldata->enviro[k]);
	free(reldata->enviro);
	reldata->enviro = envr;
	return (1);
}

