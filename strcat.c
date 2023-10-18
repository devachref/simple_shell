#include <stdio.h>
#include <stdlib.h>
/**
 * _strcat - Contcatenates two strings
 * @dest: The final or destination string
 * @src: The the string to be concatenated to the end of the dest string
 * Return: Returns the concatenated strings(dest)
 */
char *_strcat(char *dest, char *src)
{
	int i, j;
	char *tmp;

	tmp = malloc(sizeof(char) * 100);
	i = 0;

	while (dest[i] != '\0')
	{
		*(tmp + i) = *(dest + i);
		i++;
	}

	tmp[i] = '\0';

	for (j = 0; *(tmp + j) != '\0'; j++)
	{
	}

	for (i = 0; *(src + i) != '\0';)
	{
		*(tmp + j) = *(src + i);

		if (*(src + i) == '\0')
		{
			return (tmp);
		}
		i++;
		j++;
	}

	return (tmp);
}
