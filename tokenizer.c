#include "shell.h"
char **tokenizer(char *line)
{
	char *token = NULL, delin[] = " \t\n", *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	token = strtok(tmp, delin);
	if (token == NULL)
	{
		free(line), line  = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		cpt++;
		token = strtok(NULL, delin);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line), line  = NULL;
		return (NULL);
	}

	token = strtok(line, delin);
        while (token)
        {
                command[i] = _strdup(token);
                token = strtok(NULL, delin);
		i++;
        }
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
