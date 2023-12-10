#include "main.h"

/**
 * r_line - reads input string.
 *
 * @eof: r value of g_line function
 * Return: ...
 */

char *r_line(int *eof)
{
	size_t buffsize = 0;
	char *inp = NULL;

	*eof = gline(&inp, &buffsize, stdin);

	return (inp);
}

