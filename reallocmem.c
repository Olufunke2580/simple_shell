#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@b: the pointer to the memory area
 *@a: the byte to fill *s with
 *@c: the amount of bytes to be filled
 *Return: (b) a pointer to the memory area s
 */
char *_memset(char *b, char a, unsigned int c)
{
	unsigned int i;

	for (i = 0; i < c; i++)
		b[i] = a;
	return (b);
}

/**
 * ffree - frees a string of strings
 * @pt: string of strings
 */
void ffree(char **pt)
{
	char **d = pt;

	if (!pt)
		return;
	while (*pt)
		free(*pt++);
	free(d);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
