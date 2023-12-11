#include "main.h"

/**
 * getb_in - it passes the command in the argument.
 * @cd: the command.
 *
 * Return: fxn pointer for the command that is builtin.
 */

int (*getb_in(char *cd))(data_group *)
{
	b_int b_in[] = {
		{ "env", printenv }, { "exit", exits },
		{ "setenv", envset }, { "unsetenv", envunset },
		{ "cd", gointo }, { "help", help_check }, { NULL, NULL },
	};

	int j;

	for (j = 0; b_in[j].name; j++)
	{
		if (streamp(b_in[j].name, cd) == 0)
		{
			break;
		}
	}

	return (b_in[j].l);
}

