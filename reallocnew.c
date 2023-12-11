#include "main.h"

/**
 * r_allocnewer - realllocates mem to a double pointer.
 * @ptr: ...
 * @o_sze: ...
 * @n_sze: ...
 * Return: ptr.
 * if malloc doesn't go thriough returns NULL.
 */

char **r_allocnewer(char **ptr, unsigned int o_sze, unsigned int n_sze)
{
	unsigned int i;
	char **nptr;

	if (ptr == NULL)
	{
		return (malloc(sizeof(char *) * n_sze));
	}

	if (n_sze == o_sze)
	{
		return (ptr);
	}

	nptr = malloc(sizeof(char *) * n_sze);
	if (nptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < o_sze; i++)
	{
		nptr[i] = ptr[i];
	}

	free(ptr);

	return (nptr);
}

