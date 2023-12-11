#include "main.h"

/**
 * strlen_ - gets length of strings.
 * @y: pointer data type.
 * Return: 0..
 */

int strlen_(const char *y)
{
	int l;

	for (l = 0; y[l] != 0; l++)
	{
	}
	return (l);
}

/**
 * strtok_ - used to split strings.
 * @str: inp string.
 * @del: ...
 * Return: the split string
 */

char *strtok_(char str[], const char *del)
{
	char *strstr;
	unsigned int i, bl;
	static char *split, *estr;

	if (str != NULL)
	{
		if (char_comp(str, del))
			return (NULL);
		split = str;
		i = strlen_(str);
		estr = &str[i];
	}
	strstr = split;
	if (strstr == estr)
		return (NULL);

	for (bl = 0; *split; split++)
	{
		if (split != strstr)
		{
			if (*split && *(split - 1) == '\0')
				break;
		}
		for (i = 0; del[i]; i++)
		{
			if (*split == del[i])
			{
				*split = '\0';
				if (split == strstr)
					strstr++;
				break;
			}
		}

		if (bl == 0 && *split)
			bl = 1;
	}
	if (bl == 0)
		return (NULL);
	return (strstr);
}

/**
 * digits - checks if passed dtinrg is a number.
 * @y: inp string.
 * Return: 1.
 */

int digits(const char *y)
{
	unsigned int j;

	for (j = 0; y[j]; j++)
	{
		if (y[j] < 48 || y[j] > 57)
			return (0);
	}
	return (1);
}

