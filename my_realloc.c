#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: size of old ptr
 * @new_size: size of new ptr
 * Return: reallocated ptr
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *block = NULL;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (!ptr)
	{
		block = malloc(new_size);
		if (!block)
		{
			perror("Malloc failed");
			exit(errno);
			free(block);
		}
		return (block);
	}
	if (!new_size && ptr)
	{
		return (NULL);
	}
	block = malloc(new_size);
	if (!block)
	{
		perror("Malloc failed");
		exit(errno);
		free(block);
	}
	_memcpy(block, ptr, old_size);
	return (block);
}

/**
 * _memcpy - copies memory
 * @to: destination
 * @from: source
 * @n: number of bytes to be copied
 * Return: pointer to dest
 */
char *_memcpy(char *to, char *from, unsigned int n)
{
	char *ptr = to;

	while (n--)
	{
		*to++ = *from++;
	}
	return (ptr);
}
