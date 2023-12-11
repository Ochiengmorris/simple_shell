#include "main.h"

/**
 * cmenvname - compare 2 environmental variables
 *
 * @env: env variable name.
 * @name: passed name.
 *
 * Return: ...
 */

int cmenvname(const char *env, const char *name)
{
	int j;

	for (j = 0; env[j] != '=';)
	{
		if (env[j] != name[j])
		{
			return (0);
		}
		j++;
	}

	return (j + 1);
}


/**
 * printenv - printing environmental variable.
 *
 * @reldata: relevant data.
 *
 * Return: 1 success returns 1.
 */

int printenv(data_group *reldata)
{
	int j, k;

	for (j = 0; reldata->enviro[j]; j++)
	{
		for (k = 0; reldata->enviro[j][k]; k++)
			;

		write(STDOUT_FILENO, reldata->enviro[j], k);
		write(STDOUT_FILENO, "\n", 1);
	}
	reldata->status = 0;

	return (1);
}

/**
 * envv - get environment variable.
 *
 * @name: ...
 * @enviro: env variable.
 *
 * Return: value of other variables in mind.
 */

char *envv(const char *name, char **enviro)
{
	int i, mv;
	char *ptrenv;

	ptrenv = NULL;
	mv = 0;

	for (i = 0; enviro[i]; i++)
	{
		mv = cmenvname(enviro[i], name);
		if (mv)
		{
			ptrenv = enviro[i];
			break;
		}
	}

	return (ptrenv + mv);

}

