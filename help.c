#include "main.h"

/**
 * setenvhelp - help info for builrin setenv
 * Return: nothing.
 */

void setenvhelp(void)
{
	char *h = "setenv: setenv (const char *name, const char *val,";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "int replace)\n\t";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "Add a new defn to this environment\n";
	write(STDOUT_FILENO, h, strlen_(h));
}

/**
 * envhelp - builtin env.
 * Return: nothing.
 */

void envhelp(void)
{
	char *h = "env: env [option] [name=val] [command [arguments]]\n\t";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "print shell environment.\n";
	write(STDOUT_FILENO, h, strlen_(h));
}

/**
 * genhelp - help info start point.
 * Return: nun.
 */

void genhelp(void)
{
	char *h = "(0__0)$ bash, version 1.00 - release\n";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "All commands are defined inside the shell. To see it, type 'help'";
	write(STDOUT_FILENO, h, strlen_(h));
	h = "To see more about function 'name', type 'help name'.\n\n ";
	write(STDOUT_FILENO, h, strlen_(h));
	h = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, h, strlen_(h));
	h = "[dir]\nexit: exit [n]\n env: [option] [name=val] [command ";
	write(STDOUT_FILENO, h, strlen_(h));
	h = "[arguments]]\n setenv: [var] [val]\n unsetenv: ";
	write(STDOUT_FILENO, h, strlen_(h));
	h = "unsetenv [var]\n";
	write(STDOUT_FILENO, h, strlen_(h));
}

/**
 * exithelp - help info for exit.
 * Return: ...
 */

void exithelp(void)
{
	char *h = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "It does the work of exiting the shell with status n. If n is not typed,";
	write(STDOUT_FILENO, h, strlen_(h));
	h = " the exit status is executed of the last command.\n";
	write(STDOUT_FILENO, h, strlen_(h));
}

/**
 * envunsethelp - builtin unsetenv.
 * Return: ...
 */

void envunsethelp(void)
{
	char *h = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, h, strlen_(h));
	h = "This removes tne input completely from the environment\n";
	write(STDOUT_FILENO, h, strlen_(h));
}

