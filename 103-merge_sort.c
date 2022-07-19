#include "sort.h"

/**
 * topdownmerge - Top Down Merge for merge sort
 *
 * @work: work array
 * @begin: beginning
 * @mid: middle
 * @end: end
 * @array: array to be sorted
 */
void topdownmerge(int *work, size_t begin, size_t mid, size_t end, int *array)
{
	size_t i, j, k;

	i = begin;
	j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(work + begin, (size_t)(mid - begin));
	printf("[right]: ");
	print_array(work + mid, (size_t)(end - mid));

	for (k = begin; k < end; k++)
	{
		if (i < mid && (j >= end || work[i] <= work[j]))
		{
			array[k] = work[i];
			i++;
		}
		else
		{
			array[k] = work[j];
			j++;
		}
	}
	printf("[Done]:");
	print_array(array + begin, (size_t)(end - begin));
}

/**
 * topdownsplit - Top Down Split Merge
 *
 * @work: work array
 * @begin: beginning
 * @end: end
 * @array: array to be sorted
 */
void topdownsplit(int *work, size_t begin, size_t end, int *array)
{
	size_t n;

	if (end - begin <= 1)
		return;
	n = (end + begin) / 2;

	topdownsplit(array, begin, n, work);
	topdownsplit(array, n, end, work);

	topdownmerge(work, begin, n, end, array);
}

/**
 * copyarray - copy contents of main array into
 * work array
 *
 * @array: array to be sorted
 * @work: Work array
 * @begin: Beginning
 * @size: Array size
 */
void copyarray(int *array, int *work, size_t begin, size_t size)
{
	size_t i;

	for (i = begin; i < size; i++)
		work[i] = array[i];
}

/**
 * merge_sort - Top Down Merge Sort
 *
 * @array: Array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int *work;

	if (array == NULL || size < 2)
		return;
	work = malloc(sizeof(int) * size);
	if (!work)
		return;
	copyarray(array, work, 0, size);
	topdownsplit(work, 0, size, array);
	free(work);
}
