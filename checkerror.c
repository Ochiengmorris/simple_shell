#include "main.h"

/**
 * checkerror - takes error according to builtin syntax given.
 *
 * @reldata: reldata.
 * @valerr: value of error.
 * Return: the erroe value.
 */

int checkerror(data_group *reldata, int valerr)
{
	char *errorval;

	switch (valerr)
	{
		case -1:
			errorval = enverror(reldata);
			break;
		case 126:
			errorval = patherror126(reldata);
			break;
		case 127:
			errorval = enotfound(reldata);
			break;
		case 2:
			if (streamp("exit", reldata->arguments[0]) == 0)
			{
				errorval = shellexit(reldata);
			}
			else if (streamp("cd", reldata->arguments[0]) == 0)
			{
				errorval = cd_error(reldata);
			}
			break;
	}

	if (errorval)
	{
		write(STDERR_FILENO, errorval, strlen_(errorval));
		free(errorval);
	}

	reldata->status = valerr;
	return (valerr);
}

