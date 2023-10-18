#include "main.h"

/**
 * count_words - Counts the number of commands in the strings
 * commands are separated with space or :
 * @str: string of chars
 * Return: Returns the number of words found
 */

int count_words(char *str)
{
	int count, i;

	count = 0;
	/*printf("word str: %s\n", str);*/
	for (i = 0; str[i] != 10/* && str[i]*/;)
	{
		if (str[i] == 32)
		{
			i++;
			if (str[i] == 10)
				break;
			continue;
		}
		else
		{
			while (str[i] != 32)
			{
				i++;
				if (str[i] == 32 || str[i] == 10)
					count++;
				if (str[i] == 10/* || str[i]*/)
					break;
				continue;
			}

		}
	}
	/*printf("words end: %d\n", count);*/
	return (count);
}

/**
 * count_char - Counts the number of characters in a strings
 * @str: string of characters
 * Return: Returns the number of characters in the string
 */

int *count_char(char *str)
{
	int count, i, j, words;
	int *index;

	count = 0;
	j = 0;
	words = count_words(str);

	index = malloc(sizeof(int) * words);

	for (i = 0; str[i] != 10;)
	{
		if (str[i] == 32)
		{
			i++;
			if (str[i] == 10)
				break;
			continue;
		}
		else
		{
			while (str[i] != 32)
			{
				i++;
				count++;
				/*printf("count***: %d\n", count);*/
				if (str[i] == 32 || str[i] == 10)
				{
					index[j++] = count;
					count = 0;
				}
				if (str[i] == 10)
					break;
				continue;
			}

		}
	}
	return (index);
}

/**
 * parseInput - Parses the input into strings
 * @str: String to be parsed
 * @count: Number of words
 * Return: Returns pointer to list of pointers(strings)
 */
char **parseInput(char *str, int *count)
{
	char **strw;
	int i, words, j, k;
	int *c_index;

	k = 0;
	words = count_words(str);
	*count = words;
	c_index = count_char(str);

	strw = malloc(sizeof(char *) * words);

	if (strw == NULL)
		return (NULL);
	for (i = 0; i < words; i++)
	{
		strw[i] = malloc(sizeof(char) * (c_index[i]));
		if (strw[i] == NULL)
			return (NULL);
	}

	for (i = 0; i < words; i++)
	{
		for (j = 0; j < (c_index[i]); j++, k++)
		{
			while (str[k] == 32)
			{
				k++;
				if (str[k] == 10/* || str[k]*/)
					break;
				continue;
			}
			if (str[k] == 10/* || str[k]*/)
				break;

			strw[i][j] = str[k];
	}
}
return (strw);
}

/**
 * parsePath - Parses the PATH into Directories
 * @str: PATH to be parsed
 * @count: Number directories
 * Return: Returns pointer to list of pointers(strings) aka directories
 */

char **parsePath(char *str, int *count)
{

	char **strw;
	int i, words, j, k;
	int *c_index;

	k = 0;
	words = count_wordsp(str);
	*count = words;
	c_index = count_charp(str);

	strw = malloc(sizeof(char *) * words);

	for (i = 0; i < words; i++)
	{
		strw[i] = malloc(sizeof(char) * (c_index[i]));
	}

	for (i = 0; i < words; i++)
	{
		for (j = 0; j < (c_index[i]); j++, k++)
		{
			while (str[k] == 32 || str[k] == ':')
			{
				k++;
				if (str[k] == 0/* || str[k]*/)
					break;
				continue;
			}
			if (str[k] == 0/* || str[k]*/)
				break;

			strw[i][j] = str[k];
		}


		/*strw[i] = NULL;*/
	}

	return (strw);
}

/**
 * count_wordsp - Counts the number of commands in the strings
 * commands are separated with space or :
 * @str: string of chars
 * Return: Returns the number of words found
 */
int count_wordsp(char *str)
{
	int count, i;

	count = 0;
	/*printf("word strw: %s\n", str);*/
	if (str[0])
		count++;
	/*printf("before loop\n");*/
	for (i = 0; str[i]/* && str[i]*/; i++)
	{
		/*printf("before count\n");*/
		if (str[i] == ':')
			count++;
		/*printf("count: %d\n", count);*/
	}
	/*printf("directories: %d\n", count);*/
	return (count);
}
