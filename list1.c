#include "main.h"

/**
 * nodeplussep - puts separator.
 * @hd: ...
 * @sp: ...
 * Return: hd.
 */

listseparate *nodeplussep(listseparate **hd, char sp)
{
	listseparate *new, *tmp;

	new = malloc(sizeof(listseparate));
	if (new == NULL)
		return (NULL);

	new->differen = sp;
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
 * addnodeline - puts cmd line at end.
 * @hd: ...
 * @line: ...
 * Return: ...
 */

linesep *addnodeline(linesep **hd, char *line)
{
	linesep *new, *tmp;

	new = malloc(sizeof(linesep));
	if (new == NULL)
		return (NULL);

	new->mstari = line;

	new->fol = NULL;

	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = new;
	}
	else
	{
		while (tmp->fol != NULL)
		{
			tmp = tmp->fol;
		}

		tmp->fol = new;
	}

	return (*hd);
}

/**
 * freellist - line list freed.
 * @hd: ...
 * Return: ...
 */

void freellist(linesep **hd)
{
	linesep *tmp;
	linesep *now;

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

/**
 * freeslist - free s list.
 * @hd: ...
 * Return: ...
 */

void freeslist(listseparate **hd)
{
	listseparate *tmp;
	listseparate *crr;

	if (hd != NULL)
	{
		crr = *hd;
		while ((tmp = crr) != NULL)
		{
			crr = crr->fol;
			free(tmp);
		}
		*hd = NULL;
	}
}

