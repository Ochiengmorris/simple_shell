#include "main.h"

/**
 * gointo - change the working directory.
 * @reldata: ...
 * Return: 1 on success.
 */

int gointo(data_group *reldata)
{
	char *d;
	int ish, ish2, isd;

	d = reldata->arguments[1];

	if (d != NULL)
	{
		ish = streamp("$HOME", d);
		ish2 = streamp("~", d);
		isd = streamp("--", d);
	}

	if (d == NULL || !ish || !ish2 || !isd)
	{
		cdhome(reldata);
		return (1);
	}

	if (streamp("-", d) == 0)
	{
		cdback(reldata);
		return (1);
	}

	if (streamp("..", d) == 0 || streamp(".", d) == 0)
	{
		cdfstop(reldata);
		return (1);
	}

	tocd(reldata);

	return (1);
}

