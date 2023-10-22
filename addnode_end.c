#include "monty.h"

/**
 * add_dnodeint_end - Adds a node to the top
 * of the stack - the end of the list
 * @head: Double pointer to the head node
 * @n: New member value
 * Return: NULL or new address
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *lastNode = NULL;
	stack_t *current = *head;

	lastNode = malloc(sizeof(stack_t));
	if (!lastNode)
	{
		all_freer();
		err_malloc();
	}

	lastNode->n = n;

	if (*head == NULL)
	{
		lastNode->prev = *head;
		lastNode->next = NULL;
		*head = lastNode;
		glob.TOS1 = lastNode->n;
		glob.top = lastNode;
		glob.btm = lastNode->prev;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;

		lastNode->prev = current;
		current->next = lastNode;
		lastNode->next = NULL;

		glob.TOS1 = lastNode->n;
		glob.TOS2 = lastNode->prev->n;
		glob.top = lastNode;
		glob.btm = lastNode->prev;
	}

	return (lastNode);
}
