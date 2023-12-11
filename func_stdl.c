#include "main.h"

/**
 * rec_leng - record the length of a number.
 *
 * @x: int type number.
 *
 * Return: number length.
 */

int rec_leng(int x)
{
	unsigned int x1;
	int leng = 1;

	if (x < 0)
	{
		leng++;
		x1 = x * -1;
	}
	else
	{
		x1 = x;
	}

	while (x1 > 9)
	{
		leng++;
		x1 = x1 / 10;
	}

	return (leng);
}


/**
 * rec_intos - changes an integer into a STRING.
 *
 * @x: input int.
 *
 * Return: length.
 */

char *rec_intos(int x)
{
	unsigned int x2;
	char *buff;
	int leng = rec_leng(x);

	buff = malloc(sizeof(char) * (leng + 1));
	if (buff == 0)
	{
		return (NULL);
	}
	*(buff + leng) = '\0';

	if (x < 0)
	{
		x2 = x * -1;
		buff[0] = '-';
	}
	else
	{
		x2 = x;
	}
	leng--;
	do {
		*(buff + leng) = (x2 % 10) + '0';
		x2 /= 10;
		leng--;
	}
	while (x2 > 0)
		;
	return (buff);
}

/**
 * stoin - changes or convertes strings to integers.
 *
 * @y: inputted variable.
 *
 * Return: int.
 */

int stoin(char *y)
{
	unsigned int siz = 0, cnt = 0, oin = 0, pm = 1, m = 1;
	unsigned int j;

	while (*(cnt + y) != '\0')
	{
		if (siz > 0 && (*(cnt + y) < '0' || *(cnt + y) > '9'))
		{
			break;
		}

		if (*(y + cnt) == '-')
		{
			pm = pm * -1;
		}

		if ((*(cnt + y) >= '0') && (*(cnt + y) <= '9'))
		{
			if (siz > 0)
				m = m * 10;
			siz++;
		}
		cnt++;
	}

	for (j = cnt - siz; j < cnt; j++)
	{
		oin = oin + ((*(y + j) - 48) * m);
		m = m / 10;
	}
	return (oin * pm);
}

