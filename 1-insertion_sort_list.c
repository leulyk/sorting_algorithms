#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using
 * the insertion sort algorithm
 *
 * @list: the doubly linked list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *current, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		current = node;
		while (current->prev && current->prev->n > current->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			temp->next = current->next;
			current->next = temp;
			temp->prev = current;
			if (temp->next)
				temp->next->prev = temp;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		node = node->next;
	}
}
