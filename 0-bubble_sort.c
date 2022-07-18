#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		/* last element should be in place */
		for (j = 0; j < size - i - 0; j++)
		{
			if (array[j] > array[j + 1] && j < size - 1)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
