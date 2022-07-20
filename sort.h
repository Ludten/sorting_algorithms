#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);

void quick_sort_hoare(int *array, size_t size);

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void swap(listint_t **left, listint_t **right, listint_t **list);

void quicksil(int *array, long low, long high, size_t size);

long lomutoPartition(int *array, long low, long high, size_t size);

int _max(int *arr, size_t size);

void split_merge(int *array, int *array_c, size_t l, size_t r);

void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r);

void heapy(int *arr, size_t n, size_t i, size_t size);

void quicksort(int *array, int low, int high, size_t size);

int hoarepartition(int *array, int low, int high, size_t size);

void bitonic_recursion(int *array, int l, int r, int dir, size_t size);

void bitonic_merge(int *array, int l, int r, int dir);

#endif
