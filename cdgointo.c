#include "main.h"

/**
 * cdhome - go to home dir.
 * @reldata: ...
 * Return: no.
 */

void cdhome(data_group *reldata)
{
	char *p_wd, *hme;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_wd = strdup_(pwd);
	hme = envv("HOME", reldata->enviro);

	if (hme == NULL)
	{
		envsett("OLDPWD", p_wd, reldata);
		free(p_wd);
		return;
	}
	if (chdir(hme) == -1)
	{
		checkerror(reldata, 2);
		free(p_wd);
		return;
	}
	envsett("OLDPWD", p_wd, reldata);
	envsett("PWD", hme, reldata);
	free(p_wd);
	reldata->status = 0;
}

/**
 * cdback - move to previous dir.
 * @reldata: ...
 * Return: ...
 */

void cdback(data_group *reldata)
{
	char pd[PATH_MAX];
	char *ppd, *oldpd, *cppd, *cpoldpd;

	getcwd(pd, sizeof(pd));
	cppd = strdup_(pd);

	oldpd = envv("OLDPD", reldata->enviro);

	if (oldpd == NULL)
		cpoldpd = cppd;
	else
		cpoldpd = strdup_(oldpd);

	envsett("OLDPD", cppd, reldata);

	if (chdir(cpoldpd) == -1)
		envsett("PWD", cppd, reldata);
	else
		envsett("PWD", cpoldpd, reldata);

	ppd = envv("PWD", reldata->enviro);

	write(STDOUT_FILENO, ppd, strlen_(ppd));
	write(STDOUT_FILENO, "\n", 1);

	free(cppd);
	if (oldpd)
		free(cpoldpd);

	reldata->status = 0;

	chdir(ppd);
}

/**
 * tocd - go to given directory.
 * @reldata: ...
 * Return: ...
 */


void tocd(data_group *reldata)
{
	char pwd[PATH_MAX];

	char *cppd, *cpdir, *dic;

	getcwd(pwd, sizeof(pwd));

	dic = reldata->arguments[1];

	if (chdir(dic) == -1)
	{
		checkerror(reldata, 2);
		return;
	}

	cppd = strdup_(pwd);
	envsett("OLDPWD", cppd, reldata);

	cpdir = strdup_(dic);

	envsett("PWD", cpdir, reldata);

	free(cppd);
	free(cpdir);

	reldata->status = 0;
	chdir(dic);
}

/**
 * cdfstop - change to parent directory.
 * @reldata: ...
 * Return: ...
 */

void cdfstop(data_group *reldata)
{
	char *cppd, *strtokpd, *dir;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	cppd = strdup_(pwd);

	envsett("OLDPWD", cppd, reldata);
	dir = reldata->arguments[1];
	if (streamp(".", dir) == 0)
	{
		envsett("PWD", cppd, reldata);
		free(cppd);
		return;
	}
	if (streamp("/", cppd) == 0)
	{
		free(cppd);
		return;
	}
	strtokpd = cppd;
	strrev(strtokpd);
	strtokpd = strtok_(strtokpd, "/");
	if (strtokpd != NULL)
	{
		strtokpd = strtok_(NULL, "\0");
		if (strtokpd != NULL)
			strrev(strtokpd);
	}
	if (strtokpd != NULL)
	{
		chdir(strtokpd);
		envsett("PWD", strtokpd, reldata);
	}
	else
	{
		chdir("/");
		envsett("PWD", "/", reldata);
	}
	reldata->status = 0;
	free(cppd);
}

