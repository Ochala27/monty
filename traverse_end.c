#include "monty.h"

/**
 * traverse_end - Traverses to the end of a list
 * @stack: Stack pointer to traverse
 * Return: Returns pointer to the last item
 */

stack_t *traverse_end(stack_t *stack)
{
	stack_t *curr = stack;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	return (curr);
}
