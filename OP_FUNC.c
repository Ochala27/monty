#include "monty.h"
/**
 * op_nop - It does nothing
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_add - Adds two TOS1 and TOS2 and pops TOS1
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	value = (curr->prev->n + curr->n);
	curr->prev->n = value;
	del_dnodeint_end(stack);
}

/**
 * op_sub - Sub two TOS1 and TOS2 and pops TOS1
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	value = (curr->prev->n - curr->n);
	curr->prev->n = value;
	del_dnodeint_end(stack);
}

/**
 * op_mul - Mul two TOS1 and TOS2 and pops TOS1
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		all_freer();
		exit(EXIT_FAILURE);
	}

	while (curr->next != NULL)
		curr = curr->next;

	value = (curr->prev->n * curr->n);
	curr->prev->n = value;
	del_dnodeint_end(stack);
}

/**
 * op_mod - Mod two TOS1 and TOS2 and pops TOS1
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_mod(stack_t **stack, unsigned int line_number)
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

	value = (curr->prev->n % curr->n);
	curr->prev->n = value;
	del_dnodeint_end(stack);
}
