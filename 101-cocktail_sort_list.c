#include <stdio.h>
#include "sort.h"


void swap_nodes(listint_t **head, listint_t **node1, listint_t **node2);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers using
 * the cocktail shaker sort
 *
 * @list: pointer to the head of the doubly linked list to sort
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *temp;
	int swapped = 0;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = *list;
	do {
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				current->next = temp->next;
				temp->next = current;
				temp->prev = current->prev;
				current->prev = temp;
				if (current->next)
					current->next->prev = current;
				if (temp->prev)
					temp->prev->next = temp;
				else
					*list = temp;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				temp  = current->prev;
				current->prev = temp->prev;
				temp->prev = current;
				temp->next = current->next;
				current->next = temp;
				if (current->prev)
					current->prev->next = current;
				else
					*list = current;
				if (temp->next)
					temp->next->prev = temp;
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		current = current->next;
	} while (swapped);
}

/**
 * swap_nodes - swaps two nodes on a doubly linked list (currently not used)
 *
 * @head: pointer to the head node of the doubly linked list
 * @node1: first node to swap
 * @node2: second node to swap
 *
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	temp = *node2;
	(*node1)->next = temp->next;
	temp->next = (*node1);
	temp->prev = (*node1)->prev;
	(*node1)->prev = temp;
	if ((*node1)->next)
		(*node1)->next->prev = (*node1);
	if (temp->prev)
		temp->prev->next = temp;
	else
		*head = temp;
}
