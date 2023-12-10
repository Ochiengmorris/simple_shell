#include "main.h"

/**
 * strrev - reverse string.
 * @y: pointer.
 * Return: nun.
 */

void strrev(char *y)
{
	int cnt = 0, i, j;
	char *str, tmp;

	while (cnt >= 0)
	{
		if (y[cnt] == '\0')
			break;
		cnt++;
	}
	str = y;

	for (i = 0; i < (cnt - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			tmp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = tmp;
		}
	}
}

