#include "monty.h"

/**
 * free_arr - Frees a 2D Array of Strings
 * @array: Pointer to the head of the stack
 */
void free_arr(char **array)
{
	int i = 0;
	
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * free_stack - Frees a 2D Array of Strings
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;
	
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * all_freer - Frees both the stack and all lines
 */
void all_freer(void)
{
	if (glob.all_lines != NULL)
	{
		free_arr(glob.all_lines);
		glob.all_lines = NULL;
	}
	if (glob.stack != NULL)
	{
		free_stack(&(glob.stack));
		glob.stack = NULL;
	}
}
