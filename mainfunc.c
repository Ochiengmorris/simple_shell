#include "main.h"

/**
 * dataset - struct data.
 * @reldata: ...
 * @av: arguments range.
 * Return: ...
 */

void dataset(data_group *reldata, char **av)
{
	unsigned int i;

	reldata->av = av;
	reldata->input = NULL;
	reldata->arguments = NULL;
	reldata->status = 0;
	reldata->countr = 1;

	for (i = 0; environ[i]; i++)
		;

	reldata->enviro = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		reldata->enviro[i] = strdup_(environ[i]);
	}

	reldata->enviro[i] = NULL;
	reldata->pid = rec_intos(getpid());
}

/**
 * d_free - free struct data.
 * @reldata: ...
 * Return: ...
 */

void d_free(data_group *reldata)
{
	unsigned int i;

	for (i = 0; reldata->enviro[i]; i++)
	{
		free(reldata->enviro[i]);
	}

	free(reldata->enviro);
	free(reldata->pid);
}

/**
 * loop - shell loop.
 * @reldata: ...
 * Return: ...
 */

void loop(data_group *reldata)
{
	int lp, eof;
	char *inp;

	lp = 1;
	while (lp == 1)
	{
		write(STDIN_FILENO, "\n(0__0)$ ", 9);
		inp = read_l(&eof);
		if (eof != -1)
		{
			inp = wcmt(inp);
			if (inp == NULL)
				continue;

			if (synerror(reldata, inp) == 1)
			{
				reldata->status = 2;
				free(inp);
				continue;
			}
			inp = varrep(inp, reldata);
			lp = scomm(reldata, inp);
			reldata->countr += 1;
			free(inp);
		}
		else
		{
			lp = 0;
			free(inp);
		}
	}
}

/**
 * wcmt - no comment.
 * @n: ...
 * Return: ...
 */

char *wcmt(char *n)
{
	int i, upto;

	upto = 0;
	for (i = 0; n[i]; i++)
	{
		if (n[i] == '#')
		{
			if (i == 0)
			{
				free(n);
				return (NULL);
			}

			if (n[i - 1] == ' ' || n[i - 1] == '\t' || n[i - 1] == ';')
				upto = i;
		}
	}

	if (upto != 0)
	{
		n = r_alloc(n, i, upto + 1);
		n[upto] = '\0';
	}

	return (n);
}

/**
 * read_l - reads line.
 * @eof: ...
 * Return: ...
 */

char *read_l(int *eof)
{
	char *inp = NULL;
	size_t buff = 0;

	*eof = getline(&inp, &buff, stdin);

	return (inp);
}
