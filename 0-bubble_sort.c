#include <stdio.h>
#include "sort.h"

void swap(int *array, size_t i, size_t j);

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm
 *
 * @array: an array of integers
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1 && swapped; ++i)
	{
		swapped = 0;
		for (j = 0; j < size - i; ++j)
		{
			if (array[j - 1] > array[j])
			{
				swap(array, j, j - 1);
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - swaps two elements of an array
 *
 * @array: the array whose elements will be swapped
 * @index_1: first index
 * @index_2: second index
 *
 */
void swap(int *array, size_t index_1, size_t index_2)
{
	int temp;

	temp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = temp;
}
