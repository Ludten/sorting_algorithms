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
 * cocktail_sort_list - Cockttail Sort
 *
 * @list: Linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *next, *current;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next)
		{
			next = current->next;
			if (current->n > next->n)
			{
				swap(&current, &next, list);
				print_list(*list);
				swapped = 1;
			}
			current = next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev)
		{
			next = current->prev;
			if (current->n < next->n)
			{
				swap(&next, &current, list);
				print_list(*list);
				current = current->next;
				swapped = 1;
			}
			current = current->prev;
		}
	}
}
