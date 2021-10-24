#include <stdio.h>
#include <stddef.h>
#include "sort.h"


void quick_sort_rec(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *array, int i, int j, size_t size);

/**
 * quick_sort_hoare - sort an array of integers using the quick sort
 * algorithm (Hoare partition scheme)
 *
 * @array: array to sort
 * @size: size of array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - implementation of quicksort algorithm
 *
 * @array: array to sort
 * @low: lowest index of subarray to sort
 * @high: highest index of subarray to sort
 * @size: size of the array
 *
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low >= high)
		return;
	pivot = partition(array, low, high, size);
	quick_sort_rec(array, low, pivot, size);
	quick_sort_rec(array, pivot + 1, high, size);
}

/**
 * partition - partitions an array using the Hoare partition
 * scheme
 *
 * @array: array to partition
 * @low: lowest index of subarray to sort
 * @high: highest index of subarray to sort
 * @size: size of the array
 *
 * Return: the pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, new_pivot, index;

	pivot = array[high];
	new_pivot = high + 1;
	index = low - 1;
	while (1)
	{
		while (array[++index] < pivot)
			;
		while (pivot < array[--new_pivot])
			;
		if (new_pivot < index)
			return (new_pivot);
		if (new_pivot != index)
			swap(array, new_pivot, index, size);
	}
}
/**
 * swap - swaps two elements of an array
 *
 * @array: array containing the elements to swap
 * @index_1: index of first element
 * @index_2: index of second element
 * @size: size of array
 *
 */
void swap(int *array, int index_1, int index_2, size_t size)
{
	int temp;

	temp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = temp;
	print_array(array, size);
}
