#include "main.h"

/**
 * help_check - this fxn brings help essages according to builtins.
 *
 * @reldata: ...
 * Return: 0.
 */

int help_check(data_group *reldata)
{
	if (reldata->arguments[1] == 0)
	{
		genhelp();
	}
	else if (streamp(reldata->arguments[1], "cd") == 0)
		cdhelp();
	else if (streamp(reldata->arguments[1], "setenv") == 0)
		setenvhelp();
	else if (streamp(reldata->arguments[1], "alias") == 0)
		aliashelp();
	else if (streamp(reldata->arguments[1], "help") == 0)
		helphelp();
	else if (streamp(reldata->arguments[1], "exit") == 0)
		exithelp();
	else if (streamp(reldata->arguments[1], "unsetenv") == 0)
		envunsethelp();
	else if (streamp(reldata->arguments[1], "env") == 0)
		envhelp();
	else
		write(STDERR_FILENO, reldata->arguments[0], strlen_(reldata->arguments[0]));

	reldata->status = 0;
	return (1);
}

