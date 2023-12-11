#include "main.h"

/**
 * varadd - add variable.
 * @hd: ...
 * @lar: ...
 * @val: ...
 * @lval: ...
 * Return: hd.
 */

varr *varadd(varr **hd, int lar, char *val, int lval)
{
	varr *new, *tmp;

	new = malloc(sizeof(varr));

	if (new == NULL)
		return (NULL);

	new->varlen = lar;
	new->value = val;
	new->vallen = lval;

	new->fol = NULL;

	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = new;
	}
	else
	{
		while (tmp->fol != NULL)
			tmp = tmp->fol;
		tmp->fol = new;
	}


	return (*hd);
}

/**
 * freevlist - free the varr list.
 * @hd: ...
 * Return: void.
 */

void freevlist(varr **hd)
{
	varr *tmp;
	varr *now;

	if (hd != NULL)
	{
		now = *hd;
		while ((tmp = now) != NULL)
		{
			now = now->fol;
			free(tmp);
		}
		*hd = NULL;
	}
}

