#include "main.h"

/**
 * findfile - Searches for a file in a directory
 * @cmd: The file to search for
 * Return: Returns the file path
 */

char *findfile(char *cmd)
{
	char __attribute__((unused))*HOME;
	char  __attribute__((unused)) *tmp, *tmptmp;
	int __attribute__((unused)) dir_count, i, j, status, flag, found;
	char __attribute__((unused)) **strstr;
	DIR __attribute__((unused)) *dir;
	struct dirent __attribute__((unused)) *mdir;
	pid_t  __attribute__((unused))pid;
	struct stat st;

	found = stat(cmd, &st);

	if (found == 0)
	{
		return (cmd);
	}

	HOME = getenv("PATH");
	i = 0;
	flag = 0;
	j = 0;
	strstr = parsePath(HOME, &dir_count);

	i = 0;
	while (i < dir_count)
	{
		tmp = _strcat(strstr[i], "/");
		tmp = _strcat(tmp, cmd);

		found = stat(tmp, &st);
		if (found == 0)
		{
			return (tmp);
		}

		i++;
	}
	return (cmd);
}
/**
 * file_found - Searches for command(file)
 * @file: File to search for
 * @env: prints environment variables
 * @command: List of commands (files) to sreach into
 */

void file_found(char *file, char **command, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(file, command, env) == -1)
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * read_input - Reads input from user and parse it in list of pointers
 * @word_count: Number read inputs
 * Return: Returns the parsed inputs
 */
char **read_input(int *word_count)
{
	size_t len;
	char *lineptr;
	char **command;
	int read;

	lineptr = NULL;
	printf("$");
	read = getline(&lineptr, &len, stdin);

	if (read < 0)
	{
		printf("\n");
		exit(99);
	}

	command = parseInput(lineptr, word_count);
	return (command);
}

/**
 * count_charp - Counts the number of characters in a strings
 * @str: string of characters
 * Return: Returns the number of characters in the string
 */

int *count_charp(char *str)
{
	int count, i, j, words;
	int *index;

	count = 0;
	j = 0;
	words = count_wordsp(str);

	/*printf("count charp: %d\n", words);*/
	index = malloc(sizeof(int) * words);

	for (i = 0; str[i]/* && str[i]*/;)
	{
		/*printf("out loop\n");*/
		while (str[i] != 0)
		{
			if (str[i] != ':')
			{
				i++;
				count++;
				continue;
			}
			if (str[i] == ':')
			{
				index[j++] = count;
				count = 0;
			}
			i++;
		}
		index[j] = count;
	}
	return (index);
}
