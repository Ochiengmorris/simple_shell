#include "main.h"

/**
 * varrep - replaces str with fxns.
 * @inp: ...
 * @reldata: reldata.
 * Return: ...
 */

char *varrep(char *inp, data_group *reldata)
{
	varr *hd, *index;
	char *status, *ninput;
	int olen, nlen;

	status = rec_intos(reldata->status);
	hd = NULL;

	olen = varcheck(&hd, inp, status, reldata);

	if (hd == NULL)
	{
		free(status);
		return (inp);
	}

	index = hd;
	nlen = 0;

	while (index != NULL)
	{
		nlen += (index->vallen - index->varlen);
		index = index->fol;
	}

	nlen += olen;

	ninput = malloc(sizeof(char) * (nlen + 1));
	ninput[nlen] = '\0';

	ninput = rinput(&hd, inp, ninput, nlen);

	free(inp);
	free(status);
	freevlist(&hd);

	return (ninput);
}

/**
 * rinput - replace str with variables.
 * @hd: ...
 * @inp: ...
 * @ninput: ...
 * @nlen: ...
 * Return: ...
 */

char *rinput(varr **hd, char *inp, char *ninput, int nlen)
{
	varr *index;
	int i, j, k;

	index = *hd;
	for (j = i = 0; i < nlen; i++)
	{
		if (inp[j] == '$')
		{
			if (!(index->varlen) && !(index->vallen))
			{
				ninput[i] = inp[j];
				j++;
			}
			else if (index->varlen && !(index->vallen))
			{
				for (k = 0; k < index->varlen; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < index->vallen; k++)
				{
					ninput[i] = index->value[k];
					i++;
				}
				j += (index->varlen);
				i--;
			}
			index = index->fol;
		}
		else
		{
			ninput[i] = inp[j];
			j++;
		}
	}

	return (ninput);
}

/**
 * varcheck - check for $$ and $
 * @h: ..
 * @in: ..
 * @st: ..
 * @d: ..
 * Return: ..
 */

int varcheck(varr **h, char *in, char *st, data_group *d)
{
	int i, lst, lpd;

	lst = strlen_(st);
	lpd = strlen_(d->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				varadd(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				varadd(h, 2, d->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				varadd(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				varadd(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				varadd(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				varadd(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				varadd(h, 0, NULL, 0);
			else
				envc(h, in + i, d);
		}
	}

	return (i);
}

/**
 * envc - check if is an env varibale.
 * @h: ..
 * @in: ..
 * @d: ..
 * Return: ..
 */

void envc(varr **h, char *in, data_group *d)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = d->enviro;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = strlen_(_envr[row] + chr + 1);
				varadd(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	varadd(h, j, NULL, 0);
}
