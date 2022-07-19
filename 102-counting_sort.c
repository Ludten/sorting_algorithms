#include "sort.h"

/**
 * _max - find max integer
 *
 * @arr: Array
 * @size: Size of array
 * Return: Max
 */
int _max(int *arr, size_t size)
{
	size_t i;
	int max;

	max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return (max);
}

/**
 * counting_sort - Counting Sort
 *
 * @array: Array
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int i, n, *output, *count, max;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = _max(array, size);
	n = (int)size;

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(output);
		return;
	}
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = n - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
