#include "shell.h"

/**
 *_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, c;
	char *b = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		c = a;
		while (c < n)
		{
			dest[c] = '\0';
			c++;
		}
	}
	return (b);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, c;
	char *b = dest;

	a = 0;
	c = 0;
	while (dest[a] != '\0')
		a++;
	while (src[c] != '\0' && c < n)
	{
		dest[a] = src[c];
		a++;
		c++;
	}
	if (c < n)
		dest[a] = '\0';
	return (b);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@d: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *b, char d)
{
	do {
		if (*b == d)
			return (b);
	} while (*b++ != '\0');

	return (NULL);
}

