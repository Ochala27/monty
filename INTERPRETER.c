#include "monty.h"

/**
 * INTERPRETER - Interpreter of the opcode
 * @ops_array: Array of function and opcode
 * @all_lines: Array of pointer to lines
 * Return: Void
 */

void INTERPRETER(instruction_t ops_array[], char **all_lines)
{
	char *commands[2] = {NULL, NULL}, *token = NULL;
	int idx = 0, flag = 0, p = 0;
	stack_t *Our_Stack = NULL;

	while (all_lines[idx] != NULL)
	{
		p = 0, token = strtok(all_lines[idx], " ");
		commands[0] = token;
		token = strtok(NULL, " ");
		commands[1] = token, glob.arg = commands;

		for (p = 0; ops_array[p].opcode != NULL; p++)
		{
			flag = 0;
			if (strcmp(commands[0], ops_array[p].opcode) == 0)
			{
				ops_array[p].f(&Our_Stack, idx + 1), flag = 1;
				break;
			}
		}
		glob.stack = Our_Stack;

		if (flag == 0)
			error_not_found(all_lines, idx + 1, commands[0]);
		idx++;
	}
	all_freer();
}
