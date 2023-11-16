#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;
	listint_t *left = NULL;
	listint_t *right = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (swapped)
	{
		swapped = 0;

		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		right = current;
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

		left = current;
	}
}
