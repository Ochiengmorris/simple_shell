#include "main.h"

/**
 * takeline - put l var for gline.
 *
 * @l_ptr: stores input.
 * @buff: called to line.
 * @m: linesize.
 * @k: buff size.
 */

void takeline(char **l_ptr, size_t *m, char *buff, size_t k)
{
	if (*l_ptr == NULL)
	{
		if (k > BUFSIZE)
		{
			*m = k;
		}
		else
		{
			*m = BUFSIZE;
		}
		*l_ptr = buff;
	}
	else if (*m < k)
	{
		if (k > BUFSIZE)
		{
			*m = k;
		}
		else
		{
			*m = BUFSIZE;
		}
		*l_ptr = buff;
	}
	else
	{
		strcopy(*l_ptr, buff);
		free(buff);
	}
}
