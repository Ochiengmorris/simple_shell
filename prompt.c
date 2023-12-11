#include "main.h"

/**
 * get_prompt - take care of cntrl c and prompt.
 * @sg: kuhandle.
 */

void get_prompt(int sg)
{
	(void)sg;
	write(STDOUT_FILENO, "\n(0__0)$ ", 9);
}

