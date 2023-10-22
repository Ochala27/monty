#include "monty.h"

/**
 * del_dnodeint_end - Deletes a node at the top
 * of the stack - the end of the list
 * @head: Double pointer to the head node
 * Return: NULL or new address
 */

stack_t *del_dnodeint_end(stack_t **head)
{
	stack_t *lastNode = NULL;
	stack_t *current = *head;

	if (current == NULL)
		return (NULL);

	while (current->next != NULL)
		current = current->next;

	if (current->prev == NULL)
	{
		glob.TOS1 = -99;
		glob.TOS2 = -99;
		glob.top = NULL;
		glob.btm = NULL;
		free(current);
		*head = NULL;
	}
	else
	{
		lastNode = current->prev;
		lastNode->next = current->next;
		glob.TOS1 = lastNode->n;

		if (lastNode->prev != NULL)
			glob.TOS2 = lastNode->prev->n;

		glob.top = lastNode;
		glob.btm = lastNode->prev;

		free(current);
	}

	return (lastNode);
}
