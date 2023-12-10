#include "main.h"

/**
 * run_line - checks for built ins and commands.
 *
 * @reldata: arguments that are similar.
 *
 * Return: 2 on success
 */

int run_line(data_group *reldata)
{
	int (*b_in)(data_group *reldata);

	if (reldata->arguments[0] == NULL)
	{
		return (2);
	}

	b_in = getb_in(reldata->arguments[0]);

	if (b_in != NULL)
	{
		return (b_in(reldata));
	}

	return (run_cmd(reldata));
}

/**
 * run_cmd - to exec cmd lines.
 * @reldata: ...
 * Return: ...
 */

int run_cmd(data_group *reldata)
{
	pid_t pd, wd;
	int stte, ex;
	char *dir;
	(void) wd;

	ex = isexec(reldata);
	if (ex == -1)
		return (1);
	if (ex == 0)
	{
		dir = gani(reldata->arguments[0], reldata->enviro);

		if (errorcmd(dir, reldata) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (ex == 0)
			dir = gani(reldata->arguments[0], reldata->enviro);
		else
			dir = reldata->arguments[0];
		execve(dir + ex, reldata->arguments, reldata->enviro);
	}
	else if (pd < 0)
	{
		perror(reldata->av[0]);
		return (1);
	}
	else
	{
		do {
			wd = waitpid(pd, &stte, WUNTRACED);
		} while (!WIFEXITED(stte) && !WIFSIGNALED(stte));
	}

	reldata->status = stte / 256;
	return (1);
}


/**
 * errorcmd - verifies permissions.
 * @dr: dir to go to.
 * @reldata: ...
 * Return: 0 if there is an error.
 */


int errorcmd(char *dr, data_group *reldata)
{
	if (dr == NULL)
	{
		checkerror(reldata, 127);
		return (1);
	}

	if (streamp(reldata->arguments[0], dr) != 0)
	{
		if (access(dr, X_OK) == -1)
		{
			checkerror(reldata, 126);
			free(dr);
			return (1);
		}
		free(dr);
	}
	else
	{
		if (access(reldata->arguments[0], X_OK) == -1)
		{
			checkerror(reldata, 126);
			return (1);
		}
	}


	return (0);
}


/**
 * isexec - check if it is an executable.
 * @reldata: ...
 * Return: ...
 */

int isexec(data_group *reldata)
{
	int i;
	struct stat sta;

	char *inp;

	inp = reldata->arguments[0];
	for (i = 0; inp[i]; i++)
	{
		if (inp[i] == '.')
		{
			if (inp[i + 1] == '.')
				return (0);
			if (inp[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (inp[i] == '/' && i != 0)
		{
			if (inp[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(inp + i, &sta) == 0)
	{
		return (i);
	}
	checkerror(reldata, 127);
	return (-1);
}

/**
 * gani - looks for a comd.
 * @cd: ...
 * @_env: ...
 * Return: ...
 */

char *gani(char *cd, char **_env)
{
	char *pth, *ppath, *tpath, *dir;
	int lendir, len_cd, i;
	struct stat sta;

	pth = envv("PATH", _env);
	if (pth)
	{
		ppath = strdup_(pth);
		len_cd = strlen_(cd);
		tpath = strtok_(ppath, ":");
		i = 0;
		while (tpath != NULL)
		{
			if (cdir(pth, &i))
				if (stat(cd, &sta) == 0)
					return (cd);
			lendir = strlen_(tpath);
			dir = malloc(lendir + len_cd + 2);
			strcopy(dir, tpath);
			strcat_(dir, "/");
			strcat_(dir, cd);
			strcat_(dir, "\0");
			if (stat(dir, &sta) == 0)
			{
				free(ppath);
				return (dir);
			}
			free(dir);
			tpath = strtok_(NULL, ":");
		}
		free(ppath);
		if (stat(cd, &sta) == 0)
			return (cd);
		return (NULL);
	}
	if (cd[0] == '/')
		if (stat(cd, &sta) == 0)
			return (cd);
	return (NULL);
}

