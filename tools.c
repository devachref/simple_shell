#include "shell.h"

void freearray(char **arr)
{
	int i;
	if(!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]); 
		arr[i] = NULL;
	}
	free(arr), arr = NULL;

}

void prterror(char *name, char *cmd, int idx)
{
	char *index, msg[] = ": not found\n" ;

	index = _itoa(idx);/*int to aski */

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	
	free(index);
}

char *_itoa(int n)
{
	char  buffer[30];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buffer, i );/*reverse to string*/

	return (_strdup(buffer));/*return copy*/
}
void rev_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len -1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
