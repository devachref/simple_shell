#include "shell.h"

char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;
	for(i = 0; command[i]; i++)/* if the command is already path */
	{
		if(command[i] == '/')
		{
			if (stat(command, &st) == 0)/*path exit*/
				return(_strdup(command));
			return (NULL);

		}
	}

	path_env = _getenv("PATH");/* if the user unset path (no get directories)*/
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");/*try handle the path */
	while (dir)
	{
		/*size = len(directory) + len(command) + 2 ('/' '\0') */
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
