#include "sort.h"


/**
 * shell_sort - sorts an array of numbers using the shell sort
 * algorithm (Knuth sequence)
 *
 * @array: the array to sort
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, i;
	int temp, j, swapped = 0;

	while (gap < size)
		gap = gap * 3 + 1;
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; ++i)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j] < array[j + gap])
					break;
				temp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = temp;
				swapped = 1;
			}
		}
		if (swapped)
			print_array(array, size);
	}
}
