#include "main.h"

/**
 * gline - reads fro filestream.
 *
 * @l_ptr: stores input.
 * @m: l_ptr size.
 * @stream: stream to be read.
 * Return: no bytes.
 */

ssize_t gline(char **l_ptr, size_t *m, FILE *stream)
{
	static ssize_t inp;
	char x = 'z';
	int i;
	char *buff;
	ssize_t val;

	if (inp == 0)
		fflush(stream);
	else
		return (-1);
	inp = 0;

	buff = malloc(BUFSIZE * sizeof(char));
	if (buff == 0)
		return (-1);
	while (x != '\n')
	{
		i = read(STDIN_FILENO, &x, 1);
		if ((i == 0 && inp == 0) || i == -1)
		{
			free(buff);
			return (-1);
		}
		if (inp != 0 && i == 0)
		{
			inp++;
			break;
		}
		if (inp >= BUFSIZE)
			buff = r_alloc(buff, inp, inp + 1);
		buff[inp] = x;
		inp++;
	}
	buff[inp] = '\0';
	takeline(l_ptr, m, buff, inp);
	val = inp;
	if (i != 0)
		inp = 0;
	return (val);
}

