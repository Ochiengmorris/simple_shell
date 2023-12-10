#include "main.h"

/**
 * synerror - find and print syn error.
 * @reldata: ...
 * @inp: ...
 * Return: ...
 */

int synerror(data_group *reldata, char *inp)
{
	int start = 0;
	int fchar = 0;
	int i = 0;

	fchar = charf(inp, &start);
	if (fchar == -1)
	{
		psynerror(reldata, inp, start, 0);
		return (1);
	}

	i = seperror(inp + start, 0, *(inp + start));
	if (i != 0)
	{
		psynerror(reldata, inp, start + i, 1);
		return (1);
	}

	return (0);
}

/**
 * psynerror - prints syntax error.
 * @reldata: ...
 * @inp: ...
 * @i: ...
 * @bl: ...
 */

void psynerror(data_group *reldata, char *inp, int i, int bl)
{
	char *messo, *messo2, *messo3, *errorval, *count;
	int length;

	if (inp[i] == ';')
	{
		if (bl == 0)
			messo = (inp[i + 1] == ';' ? ";;" : ";");
		else
			messo = (inp[i - 1] == ';' ? ";;" : ";");
	}

	if (inp[i] == '|')
		messo = (inp[i + 1] == '|' ? "||" : "|");

	if (inp[i] == '&')
		messo = (inp[i + 1] == '&' ? "&&" : "&");

	messo2 = ": error Syntax: \"";
	messo3 = "\" unexpected\n";
	count = rec_intos(reldata->countr);
	length = strlen_(reldata->av[0]) + strlen_(count);
	length += strlen_(messo) + strlen_(messo2) + strlen_(messo3) + 2;

	errorval = malloc(sizeof(char) * (length + 1));
	if (errorval == 0)
	{
		free(count);
		return;
	}
	strcopy(errorval, reldata->av[0]);
	strcat_(errorval, ": ");
	strcat_(errorval, count);
	strcat_(errorval, messo2);
	strcat_(errorval, messo);
	strcat_(errorval, messo3);
	strcat_(errorval, "\0");

	write(STDERR_FILENO, errorval, length);
	free(errorval);
	free(count);
}

/**
 * seperror - finds error syntaxes.
 * @inp: ...
 * @i: ...
 * @l: ...
 * Return: ...
 */

int seperror(char *inp, int i, char l)
{
	int count;

	count = 0;
	if (*inp == '\0')
		return (0);

	if (*inp == ' ' || *inp == '\t')
		return (seperror(inp + 1, i + 1, l));

	if (*inp == ';')
		if (l == '|' || l == '&' || l == ';')
			return (i);

	if (*inp == '|')
	{
		if (l == ';' || l == '&')
			return (i);

		if (l == '|')
		{
			count = charrep(inp, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*inp == '&')
	{
		if (l == ';' || l == '|')
			return (i);

		if (l == '&')
		{
			count = charrep(inp, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (seperror(inp + 1, i + 1, *inp));
}

/**
 * charrep - counts rep. cjhars.
 * @inp: ...
 * @i: ...
 * Return: ...
 */

int charrep(char *inp, int i)
{
	if (*(inp - 1) == *inp)
		return (charrep(inp - 1, i + 1));

	return (i);
}

/**
 * charf - ...
 * @inp: ...
 * @i: ...
 * Return: ...
 */

int charf(char *inp, int *i)
{

	for (*i = 0; inp[*i]; *i += 1)
	{
		if (inp[*i] == ' ' || inp[*i] == '\t')
			continue;

		if (inp[*i] == ';' || inp[*i] == '|' || inp[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

