#include "sort.h"

/**
 * swap - swap nodes
 *
 * @left: left node
 * @right: right node
 * @list: linked list
 */
void swap(listint_t **left, listint_t **right, listint_t **list)
{
	listint_t *tmp;

	tmp = (*left)->prev;
	if (tmp)
		tmp->next = *right;
	else
		*list = *right;
	(*right)->prev = tmp;

	(*left)->prev = *right;
	(*left)->next = (*right)->next;
	(*right)->next = *left;
	if ((*left)->next != NULL)
		(*left)->next->prev = (*left);
	(*left) = tmp;
}

/**
 * insertion_sort_list - insertion sort algorithm
 *
 * @list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *next, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current;
		sorted = current->prev;

		if (sorted->n > next->n)
			current = current->prev;
		while (sorted != NULL && (sorted->n > next->n))
		{
			swap(&sorted, &next, list);
			print_list(*list);
		}
		current = current->next;
	}
}
