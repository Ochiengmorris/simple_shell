#include "main.h"

/**
 * cpyinf - where info to create an alias is copied.
 *
 * @name: name.
 * @val: value.
 * Return: new name or alias
 */

char *cpyinf(char *name, char *val)
{
	char *mpya;
	int lengthname, length, lengthval;

	lengthval = strlen_(val);
	lengthname = strlen_(name);
	length = lengthname + lengthval + 2;
	mpya = malloc(sizeof(char) * (length));

	strcopy(mpya, name);
	strcat_(mpya, "=");
	strcat_(mpya, val);
	strcat_(mpya, "\0");

	return (mpya);
}

/**
 * envsett - for setting env var.
 * @name: it's name.
 * @val: i'ts value.
 * @reldata: enviro data structure.
 * Return: returns void.
 */

void envsett(char *name, char *val, data_group *reldata)
{
	int j;
	char *envvar;
	char *envname;

	for (j = 0; reldata->enviro[j]; j++)
	{
		envvar = strdup_(reldata->enviro[j]);
		envname = strtok_(envvar, "=");
		if (streamp(envname, name) == 0)
		{
			free(reldata->enviro[j]);
			reldata->enviro[j] = cpyinf(name, val);
			free(envvar);
			return;
		}
		free(envvar);
	}

	reldata->enviro = r_allocnewer(reldata->enviro, j, sizeof(char *) * (j + 2));
	reldata->enviro[j] = cpyinf(name, val);
	reldata->enviro[j + 1] = NULL;
}

