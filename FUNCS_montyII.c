#include "monty.h"

void Monty_add(stack_t **stack, unsigned int line_number);
void Monty_sub(stack_t **stack, unsigned int line_number);
void Monty_div(stack_t **stack, unsigned int line_number);
void Monty_mul(stack_t **stack, unsigned int line_number);
void Monty_mod(stack_t **stack, unsigned int line_number);

/**
 * Monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void Monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		SET_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	Monty_pop(stack, line_number);
}

/**
 * Monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void Monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		SET_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	Monty_pop(stack, line_number);
}

/**
 * Monty_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void Monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		SET_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		SET_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	Monty_pop(stack, line_number);
}

/**
 * Monty_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void Monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		SET_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	Monty_pop(stack, line_number);
}

/**
 * Monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void Monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		SET_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		SET_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	Monty_pop(stack, line_number);
}