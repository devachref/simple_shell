#include "shell.h"

int builtin(char *command)
{
	char *bltns[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int i;

	for (i = 0; bltns[i]; i++)
	{
		if (_strcmp(command, bltns[i]) == 0)
			return (1);
	}
	return (0);
}

void hndl_bltn(char **command, char **argv , int *status, int idx)
{
	(void) argv;
	(void)idx;

	if (_strcmp(command[0], "exit") == 0)
		e_xit(command, argv, status, idx);
	else if (_strcmp(command[0],"env") == 0)
		print_env(command, status);
}

void e_xit(char **command, char **argv, int *status, int idx)
{
	int exit_val = (*status);
	char *index, msg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (positive_nbr(command[1]))
		{
			exit_val = _atoi(command[1]);/*string to int*/
		}
		else
		{
			index = _itoa(idx);/*int to string*/
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
        		write(STDERR_FILENO, ": ", 2);
        		write(STDERR_FILENO, index, _strlen(index));
        		write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);


			free(index);
			freearray(command);
			(*status) = 2;
			return;/*In order not to continue*/
		}
	}

	freearray(command);
	exit(exit_val);
}

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(command);
	(*status) = 0;
}
