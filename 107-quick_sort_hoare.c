#include "sort.h"

/**
 * hoarepartition - Hoare Partition
 *
 * @array: Array
 * @low: Low
 * @high: High
 * @size: Array Size
 * Return: Pivot
 */
int hoarepartition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * quicksort - Quick Sort
 *
 * @array: Array
 * @low: Low
 * @high: High
 * @size: Array Size
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int parti;

	if (low < high)
	{
		parti = hoarepartition(array, low, high, size);

		quicksort(array, low, parti - 1, size);
		quicksort(array, parti, high, size);
	}
}

/**
 * quick_sort_hoare - Quick Sort - Hoare Partition scheme
 *
 * @array: Array
 * @size: Array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, (int)size - 1, size);
}
