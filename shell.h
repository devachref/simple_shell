#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv, int idx);
char *_getenv(char *variable);
char *_getpath(char *command);

/*string.c*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
/*__________________________________*/

/*tools.c*/
void freearray(char **arr);
void prterror(char *name, char *cmd, int idx);
char *_itoa(int n);
void rev_str(char *str, int len);
/*_____________________________________*/

/*builtins.c*/
int builtin(char *command);
void hndl_bltn(char **command, char **argv , int *status, int idx);
void e_xit(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);
/*_____________________________________*/


/*new_tools*/
int positive_nbr(char *str);
int _atoi(char *str);
/*_____________________________________*/



#endif
