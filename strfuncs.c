#include "main.h"

/**
 * strcopy - copy strings form the pointer s.
 * @d: pointer...
 * @s: char pointer to where s comes from.
 * Return: d.
 */

char *strcopy(char *d, char *s)
{
	size_t a;

	for (a = 0; s[a] != '\0'; a++)
	{
		d[a] = s[a];
	}
	d[a] = '\0';

	return (d);
}

/**
 * strcat_ - concatenator.
 * @d: ...
 * @s: ...
 *
 * Return: d.
 */

char *strcat_(char *d, const char *s)
{
	int i, j;

	for (i = 0; d[i] != '\0'; i++)
	{
		;
	}

	for (j = 0; s[j] != '\0'; j++)
	{
		d[i] = s[j];
		i++;
	}

	d[i] = '\0';
	return (d);
}

/**
 * streamp - compares strings.
 * @s1: ...
 * @p1: ...
 * Return: 0.
 */

int streamp(char *s1, char *p1)
{
	int j;

	for (j = 0; s1[j] == p1[j] && s1[j]; j++)
	{
		;
	}

	if (s1[j] > p1[j])
		return (1);
	if (s1[j] < p1[j])
		return (-1);
	return (0);
}

/**
 * strchr_ -- looks for a char in a str.
 * @s: ...
 * @c: ...
 * Return: pointer to c.
 */

char *strchr_(char *s, char c)
{
	unsigned int j = 0;

	for (; *(s + j) != '\0'; j++)
	{
		if (*(s + j) == c)
		{
			return (s + j);
		}
	}
	if (*(s + j) == c)
	{
		return (s + j);
	}

	return ('\0');
}

/**
 * strspn_ - len of substring.
 * @x: ...
 * @yes: yes bytes.
 * Return: no. of yes bytes.
 */

int strspn_(char *x, char *yes)
{
	int i, j, bt;

	for (i = 0; *(x + i) != '\0'; i++)
	{
		bt = 1;
		for (j = 0; *(yes + j) != '\0'; j++)
		{
			if (*(x + i) == *(yes + j))
			{
				bt = 0;
				break;
			}
		}
		if (bt == 1)
		{
			break;
		}
	}

	return (1);
}

