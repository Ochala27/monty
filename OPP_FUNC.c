#include "monty.h"

/**
 * op_push - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int number = 0;

	(void)stack;
	(void)line_number;

	if (glob.arg[1] == NULL || (_atoi(glob.arg[1]) == -99))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	number = _atoi(glob.arg[1]);

	add_dnodeint_end(stack, number);
}

/**
 * op_pop - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}
	del_dnodeint_end(stack);
}

/**
 * op_pall - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL, *curr = NULL;

	(void)line_number;

	if (*stack == NULL)
		return;

	curr = *stack;

	while (curr->next != NULL)
		curr = curr->next;

	top = curr;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}

/**
 * op_pint - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (glob.TOS1 == -99)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", glob.TOS1);
}

/**
 * op_swap - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack, *temp = NULL;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	/**
	 * temp = curr->prev;
	 * temp->next = curr->next;
	 * curr->prev = temp->prev;
	 * curr->next = temp->next;
	 * curr = temp;
	 */

	temp = curr->prev;
	temp->next = curr->next;
	curr->prev = temp->prev;
	curr->next = temp;
	temp->prev = curr;
}
