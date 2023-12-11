#include "main.h"

/**
 * char_comp - contr strings.
 * @str: string.
 * @del: ...
 * Return: 0 if not equal, 1 otherwise
 */

int char_comp(char str[], const char *del)
{
	unsigned int j, i, k;

	for (i = k = 0; str[i]; i++)
	{
		for (j = 0; del[j]; j++)
		{
			if (str[i] == del[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * strdup_ - duplicates strings.
 * @y: string.
 * Return: duped string.
 */

char *strdup_(const char *y)
{
	char *mpya;
	size_t length;

	length = strlen_(y);
	mpya = malloc(sizeof(char) * (length + 1));

	if (mpya == NULL)
	{
		return (NULL);
	}

	memcopy(mpya, y, length + 1);
	return (mpya);
}

