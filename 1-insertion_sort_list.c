#include "sort.h"
/**
 * insertion sort - sorts a doubly linked list using the Insertion sort 
 * @list: array
 */

void insertion_sort_list(listint_t **list)
{
	listint *node;

	if(list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while(node)
	{
		while((node->prev) && (node->prev->n > node->v))
		{
			node = swap_n(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *swap_n - swap a node with previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was entered
 */
listint_t *swap_n(listint_t *node, listint_t **list)
{
	listint_t *pre = node->prev, *current = node;

	pre->next = current->next;
	if (current->next)
		current->next->prev = pre;
	current->next = pre;
	current->prev = pre->prev;
	pre->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
