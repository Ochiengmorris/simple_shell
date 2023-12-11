#include "main.h"

/**
 * scomm - splits the lines of the commands.
 * @reldata: ...
 * @inp: ...
 * Return: 0 to exit.
 */

int scomm(data_group *reldata, char *inp)
{

	int lp;
	listseparate *heads, *lists;
	linesep *headl, *listl;

	heads = NULL;
	headl = NULL;

	nodeplus(&heads, &headl, inp);

	lists = heads;
	listl = headl;

	while (listl != NULL)
	{
		reldata->input = listl->mstari;
		reldata->arguments = splitl(reldata->input);
		lp = run_line(reldata);
		free(reldata->arguments);

		if (lp == 0)
			break;

		movenxt(&lists, &listl, reldata);

		if (listl != NULL)
			listl = listl->fol;
	}

	freeslist(&heads);
	freellist(&headl);

	if (lp == 0)
	{
		return (0);
	}
	return (1);
}

/**
 * movenxt - check the next command.
 * @lists: separating the list.
 * @listl: list of cmd line.
 * @reldata: ...
 * Return: nothing.
 */

void movenxt(listseparate **lists, linesep **listl, data_group *reldata)
{
	int lp;
	listseparate *lss;
	linesep *lsl;

	lp = 1;
	lss = *lists;
	lsl = *listl;

	while (lss != NULL && lp)
	{
		if (reldata->status == 0)
		{
			if (lss->differen == '&' || lss->differen == ';')
				lp = 0;
			if (lss->differen == '|')
				lsl = lsl->fol, lss = lss->fol;
		}
		else
		{
			if (lss->differen == '|' || lss->differen == ';')
				lp = 0;
			if (lss->differen == '&')
				lsl = lsl->fol, lss = lss->fol;
		}

		if (lss != NULL && !lp)
			lss = lss->fol;
	}


	*lists = lss;
	*listl = lsl;
}

/**
 * splitl - input string tokenization.
 * @inp: input.
 * Return: tkn.
 */

char **splitl(char *inp)
{
	size_t buffsize;
	char *tkn;
	size_t i;
	char **tkns;

	buffsize = TOK_BUFSIZE;
	tkns = malloc(sizeof(char *) * (buffsize));

	if (tkns == NULL)
	{
		write(STDERR_FILENO, ": error in allocation.\n", 22);
		exit(EXIT_FAILURE);
	}

	tkn = strtok_(inp, TOK_DELIM);
	tkns[0] = tkn;

	for (i = 1; tkn != NULL; i++)
	{
		if (i == buffsize)
		{
			buffsize = buffsize + TOK_BUFSIZE;
			tkns = r_allocnewer(tkns, i, sizeof(char *) * buffsize);

			if (tkns == NULL)
			{
				write(STDERR_FILENO, ": error in allocation.\n", 22);
				exit(EXIT_FAILURE);
			}
		}

		tkn = strtok_(NULL, TOK_DELIM);
		tkns[i] = tkn;
	}

	return (tkns);
}

/**
 * nodeplus - plus seps and commas at list ends.
 * @heads: 1st sep list.
 * @headl: ...
 * @inp: inp.
 * Return: ...
 */

void nodeplus(listseparate **heads, linesep **headl, char *inp)
{
	int i;
	char *line;

	inp = charchange(inp, 0);

	for (i = 0; inp[i]; i++)
	{
		if (inp[i] == ';')
		{
			nodeplussep(heads, inp[i]);
		}

		if (inp[i] == '|' || inp[i] == '&')
		{
			nodeplussep(heads, inp[i]);
			i++;
		}
	}

	line = strtok_(inp, ";|&");
	do {
		line = charchange(line, 1);
		addnodeline(headl, line);
		line = strtok_(NULL, ";|&");
	} while (line != NULL);

}

/**
 * charchange - for characters that are non prntd | & are swapped.
 * @inp: ...
 * @bl: ...
 * Return: changed str.
 */

char *charchange(char *inp, int bl)
{
	int i;

	if (bl == 0)
	{
		for (i = 0; inp[i]; i++)
		{
			if (inp[i] == '|')
			{
				if (inp[i + 1] != '|')
				{
					inp[i] = 16;
				}
				else
					i++;
			}

			if (inp[i] == '&')
			{
				if (inp[i + 1] != '&')
					inp[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; inp[i]; i++)
		{
			inp[i] = (inp[i] == 16 ? '|' : inp[i]);
			inp[i] = (inp[i] == 12 ? '&' : inp[i]);
		}
	}
	return (inp);
}

