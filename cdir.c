#include "main.h"

/**
 * cdir - checks for colon that its in current dir.
 * @pth: pointer char.
 * @i: index pointer.
 * Return: ...
 */

int cdir(char *pth, int *i)
{
	if (pth[*i] == ':')
		return (1);

	while (pth[*i] != ':' && pth[*i])
	{
		*i = *i + 1;
	}

	if (pth[*i])
		*i = *i + 1;

	return (0);
}

