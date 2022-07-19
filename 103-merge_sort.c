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
void topdownmerge(int *array, int *work, size_t begin, size_t mid, size_t end)
{
	size_t i, j, k;

	i = begin;
	j = mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, (mid - begin));
	printf("[right]: ");
	print_array(array + mid, (end - mid));

	for (k = begin; k < end; k++)
	{
		if ((i < mid) && ((j >= end) || (work[i] <= work[j])))
		{
			array[k] = work[i++];
		}
		else
		{
			array[k] = work[j++];
		}
	}

	printf("[Done]:");
	print_array(array + begin, (end - begin));
}

/**
 * topdownsplit - Top Down Split Merge
 *
 * @work: work array
 * @begin: beginning
 * @end: end
 * @array: array to be sorted
 */
void topdownsplit(int *work, int *array, size_t begin, size_t end)
{
	size_t i, n;

	if (end - begin > 1)
	{
		n = (end + begin) / 2;
		topdownsplit(array, work, begin, n);
		topdownsplit(array, work, n, end);
		for (i = begin; i <= end; i++)
			work[i] = array[i];
		topdownmerge(array, work, begin, n, end);
	}
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
	size_t i;

	if (array == NULL || size < 2)
		return;
	work = malloc(sizeof(int) * size);
	if (!work)
		return;
	for (i = 0; i < size; i++)
		work[i] = array[i];
	topdownsplit(work, array, 0, size);
	free(work);
}
