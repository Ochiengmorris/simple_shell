#include "main.h"

/**
 * helphelp - builtin help.
 * Return: ...
 */

void helphelp(void)
{
	char *m = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, m, strlen_(m));
	m = "\tFor displaying info about builtin commands.\n";
	write(STDOUT_FILENO, m, strlen_(m));
	m = "Show brief summary about builtin commands.\n";
	write(STDOUT_FILENO, m, strlen_(m));
}

/**
 * aliashelp - alias builtin.
 * Return: ...
 */

void aliashelp(void)
{
	char *m = "alias: alias [-p] [name[=val] ....]\n";

	write(STDOUT_FILENO, m, strlen_(m));
	m = "\t used to define or show aliases.\n";
	write(STDOUT_FILENO, m, strlen_(m));
}

/**
 * cdhelp - builtin cd.
 * Return: ...
 */

void cdhelp(void)
{
	char *m = "cd: cd [-L|[-P [-e]] [@]] [dir]\n";

	write(STDOUT_FILENO, m, strlen_(m));
	m = "\tchange the working directory.\n";
	write(STDOUT_FILENO, m, strlen_(m));
}
