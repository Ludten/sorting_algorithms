#include "sort.h"

/**
 * shell_sort - Shell Sort using Knuth sequence
 *
 * @array: Array
 * @size: Array size
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j, k;
	int temp;

	gap = 1;
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	k = 0;
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		if (k > 0)
			print_array(array, size);
		k++;
	}
}
