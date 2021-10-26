#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

char *_memset(char *str, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * counting_sort - sorts an array of integers using counting sort
 *
 * @array: the array to sort
 * @size: size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	unsigned int index, max;
	int *carray, *temparray;

	if (!array || size < 2)
		return;

	max = array[0];
	for (index = 1; index < size; ++index)
		if ((unsigned int)array[index] > max)
			max = array[index];

	carray = malloc((max + 1) * sizeof(int));
	if (!carray)
		return;
	temparray = malloc(size * sizeof(int));
	if (!temparray)
		return;

	_memset((char *)carray, 0, (max + 1) * sizeof(int));
	for (index = 0; index < size; ++index)
		carray[array[index]]++;
	_memcpy((char *)temparray, (char *)array, (size) * sizeof(int));

	for (index = 0; index <= max; ++index)
	{
		if (index != 0)
			carray[index] += carray[index - 1];
		printf("%d", carray[index]);
		if (index != max)
			printf(", ");
	}
	printf("\n");

	for (index = size - 1; ; --index)
	{
		array[carray[temparray[index]] - 1] = temparray[index];
		--carray[temparray[index]];
		if (index == 0)
			break;
	}

	free(temparray);
	free(carray);
}

/**
 * _memset - fill memory with a constant byte
 *
 * @str: pointer to a memory area
 * @b: the constant byte to fill the memory area
 * @n: number of bytes to fill
 *
 * Return: pointer to memory area str
 */
char *_memset(char *str, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n ; ++i)
		*(str + i) = b;
	return (str);
}

/**
 * _memcpy - copy a memory area
 *
 * @dest: pointer to the destination memory
 * @src: pointer to the source memory
 * @n: number of bytes to copy
 *
 * Return: pointer to the destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; ++i)
		*(dest + i) = *(src + i);
	return (dest);
}
