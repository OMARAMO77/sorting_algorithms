#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *tmp_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->n < (node->prev)->n)
		{
			tmp_node = node;
			if (node->next)
				(node->next)->prev = tmp_node->prev;
			(node->prev)->next = tmp_node->next;
			node = node->prev;
			tmp_node->prev = node->prev;
			tmp_node->next = node;
			if (node->prev)
				(node->prev)->next = tmp_node;
			node->prev = tmp_node;
			if (tmp_node->prev == NULL)
				*list = tmp_node;
			print_list(*list);
			node = node->prev;
		}
		node = node->next;
	}

}
