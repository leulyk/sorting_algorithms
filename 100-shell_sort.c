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
	int temp, j, decreased = 0;

	if (size < 2 || !array)
		return;
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
			}
		}
		if (decreased)
			print_array(array, size);
		decreased = 1;
	}
}
