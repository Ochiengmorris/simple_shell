#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>


#define BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"
#define TOK_BUFSIZE 128


extern char **environ;

/**
 * struct data - contains all rel data at runtime.
 * @input: command written by the user.
 * @arguments: commandline tokens recieved.
 * @enviro: environ variable.
 * @pid: process ID of shell.
 * @countr: lines counter.
 * @status: stasus (last) of the shell.
 * @av: argument vector;
 */

typedef struct data
{
	char *input;
	char **arguments;
	char **enviro;
	char *pid;
	int status;
	int countr;
	char **av;
} data_group;

/**
 * struct b_ins - a struct for command arguments.
 *
 * @name: the argument names.
 * @l: fxn pointer data type.
 */

typedef struct b_ins
{
	char *name;
	int (*l)(data_group *reldata);
} b_int;

/**
 * struct lineseps - linked list.
 * @mstari: ...
 * @fol: next line.
 * Description: this is to store cmd line args.
 */
typedef struct lineseps
{
	char *mstari;
	struct lineseps *fol;
} linesep;


/**
 * struct listseparates - linked list.
 * @differen: ...
 * @fol: ...
 * Description: ...
 */

typedef struct listseparates
{
	char differen;
	struct listseparates *fol;
} listseparate;

/**
 * struct varrlist - linked list.
 * @vallen: ...
 * @varlen: ...
 * @value: ...
 * @fol: ...
 * Description: ...
 */
typedef struct varrlist
{
	int varlen;
	int vallen;
	char *value;
	struct varrlist *fol;
} varr;


int rec_leng(int x);
char *rec_intos(int x);
int stoin(char *y);
char *envv(const char *name, char **enviro);
int printenv(data_group *reldata);
char *strtok_(char str[], const char *del);
int digits(const char *y);
int strlen_(const char *y);
int char_comp(char str[], const char *del);
char *strdup_(const char *y);
void get_prompt(int sg);

int help_check(data_group *reldata);
void envhelp(void);
void setenvhelp(void);
void envunsethelp(void);
void genhelp(void);
void exithelp(void);
void helphelp(void);
void aliashelp(void);
void cdhelp(void);

char *r_line(int *eof);
ssize_t gline(char **l_ptr, size_t *m, FILE *stream);
void takeline(char **l_ptr, size_t *m, char *buff, size_t k);
void memcopy(void *newptr, const void *ptr, unsigned int size);
void *r_alloc(void *ptr, unsigned int o_sze, unsigned int n_sze);
char **r_allocnew(char **ptr, unsigned int o_sze, unsigned int n_sze);


void envc(varr **h, char *in, data_group *d);
int varcheck(varr **h, char *in, char *st, data_group *d);
char *rinput(varr **hd, char *inp, char *ninput, int nlen);
char *varrep(char *inp, data_group *reldata);



int run_line(data_group *reldata);
int (*getb_in(char *cd))(data_group *reldata);
char *cpyinf(char *name, char *val);
void envsett(char *name, char *val, data_group *reldata);
int envset(data_group *reldata);
int envunset(data_group *reldata);

char *cd_error(data_group *reldata);
char *catcd(data_group *, char *, char *, char *);
char *notfound(data_group *reldata);
char *shellexit(data_group *reldata);

int run_cmd(data_group *reldata);
int cdir(char *pth, int *i);
char *gani(char *cd, char **_env);
int isexec(data_group *reldata);
int errorcmd(char *dir, data_group *reldata);

int streamp(char *s1, char *p1);
char *strcat_(char *d, const char *s);
char *strcopy(char *d, char *s);
char *strchr_(char *s, char c);
int strspn_(char *x, char *yes);

int exits(data_group *reldata);
char *read_l(int *eof);
char *wcmt(char *n);
void loop(data_group *reldata);

int checkerror(data_group *reldata, int valerr);
char **r_allocnewer(char **ptr, unsigned int o_sze, unsigned int n_sze);

void cdfstop(data_group *reldata);
void tocd(data_group *reldata);
void cdback(data_group *reldata);
void cdhome(data_group *reldata);
int gointo(data_group *reldata);

void strrev(char *y);

char *patherror126(data_group *reldata);
char *enotfound(data_group *reldata);
char *enverror(data_group *reldata);



void d_free(data_group *reldata);
void dataset(data_group *reldata, char **av);


int charrep(char *inp, int i);
int seperror(char *inp, int i, char l);
int charf(char *inp, int *i);
void psynerror(data_group *reldata, char *inp, int i, int bl);
int synerror(data_group *reldata, char *inp);

char *charchange(char *inp, int bl);
void nodeplus(listseparate **heads, linesep **headl, char *inp);
void movenxt(listseparate **list_s, linesep **listl, data_group *reldata);
int scomm(data_group *reldata, char *inp);
char **splitl(char *inp);


listseparate *nodeplussep(listseparate **hd, char sp);
void freeslist(listseparate **hd);
linesep *addnodeline(linesep **hd, char *line);
void freellist(linesep **hd);
varr *varadd(varr **hd, int lar, char *val, int lval);
void freevlist(varr **hd);

#endif /*end if*/
