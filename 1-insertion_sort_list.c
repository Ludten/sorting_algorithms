#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 *
 * @list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *next, *tmp;
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		next = current;
		sorted = current->prev;
		if (next)
		{
			if (sorted->n > next->n)
				current = current->prev;
			while (sorted != NULL && (sorted->n > next->n))
			{
				tmp = sorted->prev;
				if (tmp)
					tmp->next = next;
				next->prev = tmp;

				sorted->prev = next;
				sorted->next = next->next;
				next->next = sorted;
				if (sorted->next != NULL)
					sorted->next->prev = sorted;
				if (tmp == NULL)
					*list = next;
				sorted = tmp;
				print_list(*list);
			}
		}
		current = current->next;
	}
}
