#include "sort.h"
/**
 *cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *order using the Cocktail shaker sort algorithm
 *@list: Double pointer to the head node of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;
	while (swapped == 1)
	{
		swapped = 0;
		/* Traverse from left to right */
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		/* Traverse from right to left */
		for (current = current->prev; current != NULL;
				current = current->prev)
		{
			if (current->prev != NULL && current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else if (current->prev == NULL && current->n < (*list)->n)
			{
				*list = current;
				swap_nodes(current->prev, current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
/**
 *swap_nodes - Swaps two nodes in a doubly linked list
 *@node1: Pointer to the first node
 *@node2: Pointer to the second node
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
