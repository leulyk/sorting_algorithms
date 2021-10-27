#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_sort_main(int *array, int *temp, int low, int high, int size);
void merge(int *array, int *temp, int low, int mid, int high, int size);
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
	print_array(temparray, size);

	merge_sort_main(array, temparray, 0, size - 1, size);

	free(temparray);
}

/**
 * merge_sort_main - implementation of the top down mergesort algorithm
 *
 * @array: array to sort
 * @low: the lowest index
 * @high: the highest index
 * @temp: temp array to to work on the merging
 * @size: size of the array
 *
 */
void merge_sort_main(int *array, int *temp, int low, int high, int size)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		merge_sort_main(array, temp, low, mid, size);
		merge_sort_main(array, temp, mid + 1, high, size);
		merge(array, temp, low, mid, high, size);
	}
	/**
	* ----------------- Bottom up implementation -------------------
	* Divide the array into blocks of size `j`
	* j = [1, 2, 4, 8, 16…]
	* - for j = 1, i = 0, 2, 4, 6, 8…
	* - for j = 2, i = 0, 4, 8…
	* - for j = 4, i = 0, 8…
	* - …
	*
	*** Code:
	*
	*int i, j, k, from, mid, to;
	*
	*for (j = 1; j <= high - low; j = 2 * j)
	*{
	*	for (i = low; i < high; i += 2 * j)
	*	{
	*		from = i;
	*		mid = i + j - 1;
	*		k = i + 2 * j - 1;
	*		to = k < high ? k : high;
	*
	*		merge(array, temp, from, mid, to, size);
	*	}
	*}
	*/
}

/**
 * merge - the merge operation in mergesort
 *
 * @array: array to sort
 * @temp: copy of array to work on the merging
 * @low: the lowest index
 * @mid: the middle index
 * @high: the highest index
 * @size: size of the array
 *
 */
void merge(int *array, int *temp, int low, int mid, int high, int size)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = low; i <= mid; ++i)
	{
		printf("%d", array[i]);
		if (i != mid)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = mid + 1; i <= high; ++i)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");

	i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < size && i <= mid)
		temp[k++] = array[i++];
	for (i = low; i <= high; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, high - low + 1);

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
