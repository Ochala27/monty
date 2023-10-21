#include "monty.h"
/**
 * op_div- Div two TOS1 and TOS2 and pops TOS1
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	value = (curr->prev->n / curr->n);
	curr->prev->n = value;
	del_dnodeint_end(stack);
}
