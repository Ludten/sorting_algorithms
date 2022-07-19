#include "sort.h"

/**
 * lomutoPartition - Lomuto Partition scheme
 *
 * @array: Array
 * @low: Low
 * @high: High
 * @size: Array size
 * Return: Pivot index
 */
long lomutoPartition(int *array, long low, long high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			++i;
		}
	}
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksil - Quick Silver
 *
 * @array: Array
 * @low: low
 * @high: high
 * @size: Size of array
 */
void quicksil(int *array, long low, long high, size_t size)
{
	long parti;

	if (low > high)
		return;

	parti = lomutoPartition(array, low, high, size);
	quicksil(array, low, parti - 1, size);
	quicksil(array, parti + 1, high, size);
}

/**
 * quick_sort - Quick Sort
 *
 * @array: array to be sorted
 * @size: length of array
 */
void quick_sort(int *array, size_t size)
{
	quicksil(array, 0, (long)(size - 1), size);
}
