#include "main.h"

/**
 * main - entry.
 * @ac: count of arguments.
 * @av: arguments.
 * Return: 0.
 */

int main(int ac, char **av)
{
	data_group reldata;
	(void) ac;


	signal(SIGINT, get_prompt);
	dataset(&reldata, av);
	loop(&reldata);
	d_free(&reldata);

	if (reldata.status < 0)
	{
		return (255);
	}

	return (reldata.status);
}

