#include "main.h"

/**
 * r_alloc - works the same as realloc.
 * @ptr: pointer to the memory.
 * @o_sze: initially allocated space.
 * @n_sze: newsize.
 *
 * Return: new ptr.
 */

void *r_alloc(void *ptr, unsigned int o_sze, unsigned int n_sze)
{
	void *nptr;

	if (ptr == NULL)
	{
		return (malloc(n_sze));
	}

	if (n_sze == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (n_sze == o_sze)
	{
		return (ptr);
	}
	nptr = malloc(n_sze);
	if (nptr == NULL)
		return (NULL);

	if (n_sze < o_sze)
		memcopy(nptr, ptr, n_sze);
	else
	{
		memcopy(nptr, ptr, o_sze);
	}

	free(ptr);
	return (nptr);
}

/**
 * memcopy - copies informatin stored in pointers.
 *
 * @nptr: pointer.
 * @ptr: pointer.
 * @sze: pointer size.
 *
 * Return: nothing.
 */

void memcopy(void *nptr, const void *ptr, unsigned int sze)
{
	char *c_ptr = (char *)ptr;
	unsigned int i;
	char *c_nptr = (char *)nptr;

	for (i = 0; i < sze; i++)
	{
		c_nptr[i] = c_ptr[i];
	}
}

/**
 * r_allocnew - reallocates a double pointer.
 *
 * @ptr: double pointer.
 * @o_sze: ...
 * @n_sze: ...
 *
 * Return: ...
 */

char **r_allocnew(char **ptr, unsigned int o_sze, unsigned int n_sze)
{
	unsigned int i;
	char **nptr;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * n_sze));

	if (n_sze == o_sze)
	{
		return (ptr);
	}

	nptr = malloc(sizeof(char *) * n_sze);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < o_sze;)
	{
		nptr[i] = ptr[i];
		i++;
	}
	free(ptr);

	return (nptr);
}

