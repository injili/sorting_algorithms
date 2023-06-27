#include "sort.h"

/**
 *swap_node - swap list items
 *@node: node
 *@list: node list
 *Return: pointer to swapped node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back, *current;

	back = node->prev;
	current = node;
	back->next = current->next;

	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		listint_t *insertion = current->prev;

		while (insertion && insertion->n > current->n)
		{
			swap_node(current, list);
			print_list(*list);
			insertion = current->prev;
		}
		current = current->next;
	}
}
