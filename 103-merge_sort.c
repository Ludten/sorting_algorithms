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
void topdownmerge(int *work, int *array, size_t begin, size_t mid, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, (mid - begin));
	printf("[right]: ");
	print_array(array + mid, (end - mid));

	for (i = begin, j = mid; i < mid && j < end; k++)
	{
		if (array[i] < array[j])
			work[k] = array[i++];
		else
			work[k] = array[j++];
	}

	while (i < mid)
		work[k++] = array[i++];
	while (j < end)
		work[k++] = array[j++];

	for (k = begin, i = 0; k < end; k++)
		array[k] = work[i++];

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
	size_t n;

	if (end - begin > 1)
	{
		n = (end - begin) / 2 + begin;
		topdownsplit(work, array, begin, n);
		topdownsplit(work, array, n, end);
		topdownmerge(work, array, begin, n, end);
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

	if (array == NULL || size < 2)
		return;
	work = malloc(sizeof(int) * size);
	if (!work)
		return;
	topdownsplit(work, array, 0, size);
	free(work);
}
