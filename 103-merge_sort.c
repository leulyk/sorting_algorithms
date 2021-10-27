#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_sort_main(int *array, int *temp, int low, int high);
void merge(int *array, int *temp, int low, int mid, int high);
void print_array_range(int *array, int low, int high, char *title);
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * merge_sort - sort an array of integers using the merge sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	int *temparray;

	temparray = malloc(size * sizeof(int));
	if (!temparray)
		return;
	_memcpy((char *)temparray, (char *)array, size * sizeof(int));

	merge_sort_main(array, temparray, 0, size - 1);

	free(temparray);
}

/**
 * merge_sort_main - implementation of the top down mergesort algorithm
 *
 * @array: array to sort
 * @low: the lowest index
 * @high: the highest index
 * @temp: temp array to to work on the merging
 *
 */
void merge_sort_main(int *array, int *temp, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		merge_sort_main(array, temp, low, mid);
		merge_sort_main(array, temp, mid + 1, high);
		merge(array, temp, low, mid, high);
	}
}

/**
 * merge - the merge operation in mergesort
 *
 * @array: array to sort
 * @temp: copy of array to work on the merging
 * @low: the lowest index
 * @mid: the middle index
 * @high: the highest index
 *
 */
void merge(int *array, int *temp, int low, int mid, int high)
{
	int i, j, k;

	i = low, j = mid + 1, k = low;

	print_array_range(array, low, mid, "Merging...\n[left]: ");
	print_array_range(array, mid + 1, high, "[right]: ");

	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	for (i = low; i <= high; i++)
		array[i] = temp[i];

	print_array_range(array, low, high, "[Done]: ");
}

/**
 * print_array_range - modified version of print array to print
 * elements in a specified range
 *
 * @array: the array to print the elements from
 * @low: lowest index
 * @high: highest index
 * @title: title to print before the array
 *
 */
void print_array_range(int *array, int low, int high, char *title)
{
	int i;

	printf("%s", title);
	for (i = low; i <= high; ++i)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");
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
