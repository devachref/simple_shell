#include "shell.h"
/**
 * main - Simple shell main function
 * @ac: count of arguments
 * @av: Arguments
 * Return: 0 Always (success).
 * */
int main(int ac, char **argv)
{
        char *line = NULL, **command = NULL;
        int status = 0, idx = 0;
        (void) ac;

        while(1)
        {
                line = read_line();
                if (line == NULL) /* reache EDF ctr + D */
                {
                        if (isatty(STDIN_FILENO))
                                write(STDOUT_FILENO, "\n", 1);
                        return (status);
                }
		idx++;

                command = tokenizer(line);
                if (!command)
                        continue;
		
		if (builtin(command[0]))
			hndl_bltn(command, argv, &status, idx);/*handle_builtin*/
		else
                	status = _execute(command, argv, idx);
        }
}
