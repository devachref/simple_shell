#include "main.h"

/**
 * built_env - Prints the env environment variable
 * @pid: id of the child process
 * @status: int value representing the status code
 * @env: The env environment variable
 */

void built_env(int status, int *pid, char **env)
{
	int i;

	*pid = fork();
	i = 0;
	if (pid == 0)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	wait(&status);
}

/**
 * comp - Compares to strings
 * @file: string to be compared to the two strings
 * @built_in: first string
 * @built_ine: second string
 * Return: Returns 1 if file equal to first string
 * 2 if file equals to sencond string
 * 0 if not equal to any
 */
int comp(char *file, char *built_in, char *built_ine)
{
	int k;
	int ajang;

	k = 0;

	while (file[k])
	{
		if (file[k] == built_in[k])
			ajang = 1;
		else if (file[k] == built_ine[k])
			ajang = 2;
		else
			ajang = 0;
		k++;
	}
	return (ajang);
}

/**
 * _atoi - convert a string to integer
 * @s: Pointer to the String to be converted
 * Return: Returns the coverted number if success
 * if not returns -1
 */

int _atoi(char *s)
{
	int i;
	int j;
	int mynum;
	int *num;

	mynum = 11;
	num = &mynum;

	if (s == NULL)
		return (-1);
	if (*s == 0)
		return (-1);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = '0'; j <= '9' && j >= '0'; j++)
		{
			if (*(s + i) == j)
			{
				*(num + i) = j - '0';
			}
			else
				return (-1);
		}
	}
	return (*num);
}


/**
 * free_str - Frees arrays of char pointers
 * @str: The array to be freed
 * @count: Number of pointers to be freed
 */

void free_str(char **str, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (str[i])
			free(str[i]);
	}
	free(str);
}

/**
 * main - Program that read cmds
 * @ac: Number of commands read;
 * @av: command read
 * @env: Environment of the current program
 * Return: Always Zero
 */

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av,
		char **env)
{
	int word_count, k, status, sttus, ajang;
	char **command, *file, *built_in, *built_ine;
	pid_t pid;

	built_in = "exit";
	built_ine = "env";

	while (1)
	{
		command = read_input(&word_count);
		k = 0;
		while (k < word_count)
		{
			k++;
		}
		command[k] = NULL;
		file = findfile(command[0]);
		ajang = comp(file, built_in, built_ine);
		sttus = _atoi(command[1]);
		if (ajang == 1)
		{
			free_str(command, word_count);
			if (sttus > 0)
				exit(sttus);
			else
				exit(0);
		}
		if (ajang == 2)
		{
			built_env(status, &pid, env);
		}
		if (file)
		{
			file_found(file, command, env);
		}
		free(file);
		wait(&status);
	}
	return (0);
}
